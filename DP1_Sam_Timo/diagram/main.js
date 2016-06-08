"use strict"

function main() {
    loadColumns();
    positionComponents();
    initEdges()
    loadCanvas();
    loadImages();
    drawEdges();
    drawColumns();
}

// 1. calculation

// 1.1 columns

let columns;
let maxRound; // make sure the script won't run into maximum loop by checking on worst case

function loadColumns() {
    columns = [];
    maxRound = components.length;
    loadColumn(0);
}

function loadColumn(nr) {
    //console.log("column "+nr);
    //console.log(components.length+" left to localize");

    columns[nr] = [];

    // make clone snapshot of round
    let componentsRound = JSON.parse(JSON.stringify(components));

    for (let i = 0; i < componentsRound.length; i++){
        let component = componentsRound[i];

        // test wheter the component has surpassed all its callers
        let calls = 0; 
        for(let j = 0; j < component.previous.length; j++){
            let isPlaced = true;
            for(let k = 0; k < componentsRound.length; k++){
                if (component.previous[j] == componentsRound[k].id) { // caller component is not placed yet
                    isPlaced = false;
                    break;
                }
            }
            if(isPlaced) calls++;
        }

        // test wheter all previous nodes have been placed into columns
        if(calls==component.previous.length){
            let componentRemove;
            for(let j=0; j<components.length; j++){
                if(components[j].id==component.id){
                    componentRemove = components[j];
                    components.splice(j, 1);
                    break;
                }
            }
            columns[nr].push(componentRemove);
            //console.log("localized "+componentRemove.id);
        }
    }

    let length = columns[nr].length;
    columns[nr].populations = [[0, length * gateSize + (length-1) * space]];
    console.log(columns[nr].populations);

    if(components.length!=0 && nr!=maxRound) loadColumn(nr+1);
}

// x.x position components

const gateSize = 80;
const componentCenter = gateSize / 2;
const space = 20;
const correction = 0.5; // add correction for drawing, to make lines sharp

function positionComponents() {
    let x = space;

    for (let i = 0; i < columns.length; i++) {
        let column = columns[i];

        for (let j = 0; j < column.length; j++) {
            let component = column[j];
            component.x = x;
            component.y = j * (gateSize + space);
        }

        // add space next to column
        x += gateSize + column.length * space + space;
        // add space before next column
        if(i+1<columns.length){
            let nextColumn = columns[i + 1];
            x += nextColumn.length * space;
        }
    }
}

// 1.2 edges TODO

let edges;

function initEdges() {
    edges = [];

    for (let i = 0; i < columns.length; i++){
        let column = columns[i];

        for (let j = 0; j < column.length; j++){
            let component = column[j];

            let excludeY = [];

            for (let k = 0; k < component.next.length; k++){
                let next = getComponent(component.next[k]);
                let index = edges.length;
                let destinationIndex = getColumnIndex(next.id);

                // get x position next to specific next component
                let marginX = space / next.previous.length * next.previous.indexOf(component.id);
                // get y position of connection on specific next component
                let connectionY = gateSize / (next.previous.length + 1) * (next.previous.indexOf(component.id) + 1);

                if(i==destinationIndex-1){ // when columns are next to each other
                    // caller side
                    edges[index] = [];
                    edges[index].push({
                        x: component.x + gateSize / 2,
                        y: component.y + (component.y == next.y && i != 0 ? connectionY : gateSize / 2) // set y aligned to next y when the components are directly next to each other
                    });
                    if(component.y!=next.y || i==0) // add second point
                        edges[index].push({x: component.x + gateSize + space + j * space, y: component.y + gateSize / 2 });
                    edges[index].push({x: component.x + gateSize + space + j * space, y: next.y + connectionY });
                } else { // make use of y connection path
                    let y = getEdgeTravelY(i+1, destinationIndex-1);
                    excludeY.push({origin: i+1, destination: destinationIndex-1, y: y});

                    let linkIndex = getComponentIndex(next.id);

                    // caller side
                    edges[index] = [];
                    edges[index].push({x: component.x + gateSize/2, y: component.y + gateSize/2});
                    edges[index].push({x: component.x + gateSize + space + j * space, y: component.y + gateSize / 2 });
                    edges[index].push({x: component.x + gateSize + space + j * space, y: y });

                    // calling side
                    edges[index].push({x: next.x - space - linkIndex * space + marginX, y: y });
                    edges[index].push({x: next.x - space - linkIndex * space + marginX, y: next.y + connectionY });
                }

                // calling side
                edges[index].push({x: next.x + gateSize/2, y: next.y + connectionY });
            }

            // remove y from columns populations
            for (let k = 0; k < excludeY.length; k++) RangeAlterColumnPopulations(excludeY[k].origin, excludeY[k].destination, excludeY[k].y);
        }
    }
}

function getComponent(id) {
    for (let i = 0; i < columns.length; i++) {
        for (let j = 0; j < columns[i].length; j++) {
            if (columns[i][j].id == id) return columns[i][j];
        }
    }
}

function getComponentIndex(id) {
    for (let i = 0; i < columns.length; i++) {
        for (let j = 0; j < columns[i].length; j++) {
            if (columns[i][j].id == id) return j;
        }
    }
}

function getColumnIndex(componentId){
    for (let i = 0; i < columns.length; i++) {
        for (let j = 0; j < columns[i].length; j++) {
            if (columns[i][j].id == componentId) return i;
        }
    }
}

function getEdgeTravelY(originColumnIndex, destinationColumnIndex) {
    let length = getRangeColumnLength(originColumnIndex, destinationColumnIndex);
    let y = gateSize * length + space * (length-1);
    let match = false;

    while (!match && y!=100) { // loop through y until match or y reached 100
        y += space;

        for (let i = originColumnIndex; i <= destinationColumnIndex; i++){ // loop through specific columns
            match = true;

            for(let j=0; j<columns[i].populations.length; j++){ // loop through column populations
                let population = columns[i].populations[j];

                if (y >= population[0] && y <= population[1]) {
                    match = false;
                    break;
                }
            }

            if (!match) break;
        }
    }

    return y;
}

function getRangeColumnLength(originColumnIndex, destinationColumnIndex) {
    let length = columns[originColumnIndex].length;
    for (let i = originColumnIndex; i <= destinationColumnIndex; i++) { // loop through columns range
        if(columns[i].length>length) length = columns[i].length;
    }
    return length;
}

function RangeAlterColumnPopulations(originColumnIndex, destinationColumnIndex, y) {
    for (let i = originColumnIndex; i <= destinationColumnIndex; i++) { // loop through columns range
        //let populations = columns[i].populations;
        console.log("start populations column ", i);

        let absorbed = false;

        for (let j = 0; j < columns[i].populations.length && !absorbed; j++){
            //let population = populations[j];

            if (y == columns[i].populations[j][0]-space){
                //console.log("absorbed begin");
                columns[i].populations[j][0] = y;
                absorbed = true;
            } else if (y == columns[i].populations[j][1]+space) {
                //console.log("absorbed end", j);
                columns[i].populations[j][1] = y;
                absorbed = true;
            }
        }

        if(!absorbed) columns[i].populations.push([y, y]);
        console.log(columns[i].populations);
    }
}

// 2. drawing

// 2.1 load canvas

let ctx;

function loadCanvas() {
    let canvas = document.getElementById('canvas');
    if(canvas.getContext) ctx = canvas.getContext('2d');
}

// 2.2 draw edges TODO

function drawEdges() {
    for (let i = 0; i < edges.length; i++){
        // draw begin line of edge with different color to make it easier to differentiate
        ctx.beginPath();
        ctx.strokeStyle = "#0000ff";
        ctx.moveTo(edges[i][0].x + correction, edges[i][0].y + correction);
        ctx.lineTo(edges[i][1].x + correction, edges[i][1].y + correction);
        ctx.stroke();
        // draw rest of edge
        ctx.beginPath();
        ctx.strokeStyle = "#000";
        ctx.moveTo(edges[i][1].x + correction, edges[i][1].y + correction);
        for (let j = 2; j < edges[i].length; j++) ctx.lineTo(edges[i][j].x + correction, edges[i][j].y + correction);
        ctx.stroke();
    }
}

// 2.3 draw components

let imgGates;

function loadImages() {
    imgGates = {};
    let gates = ["AND", "NAND", "NOR", "NOT", "OR", "XNOR", "XOR"];

    for (let i = 0; i < gates.length; i++){
        let gate = gates[i];
        imgGates[gate] = new Image();
        imgGates[gate].src = "img/"+gate+".png";
    }
}

function drawColumns() {
    for (let i = 0; i < columns.length; i++){
        let column = columns[i];

        for (let j = 0; j < column.length; j++){
            let component = column[j];
            let x = component.x + correction;
            let y = component.y + correction;
            
            ctx.fillStyle = "#fff";

            if(component.gate!=""){ //gates
                ctx.fillRect(x, y, gateSize, gateSize);
                ctx.fillStyle = "#000";
                ctx.strokeRect(x, y, gateSize, gateSize);
                ctx.fillText(component.id, x+20, y+15);
                ctx.drawImage(imgGates[component.gate], x+10, y+25, 60, 30);
                ctx.fillText(component.gate, x+20, y+70);
            } else { // inputs and outputs
                ctx.beginPath();
                ctx.arc(x+componentCenter, y+componentCenter, 10, 0, Math.PI*2, true);
                ctx.fill();
                ctx.fillStyle = "#000";
                ctx.arc(x+componentCenter, y+componentCenter, 10, 0, Math.PI*2, true);
                ctx.stroke();
                ctx.fillText(component.id, x+componentCenter-10, y+componentCenter+25);
            }
        }
    }
}


main();