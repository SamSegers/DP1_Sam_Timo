"use strict"

function main() {
    createColumns();
    positionComponents();

    createEdges()

    loadCanvas();
    loadImages();

    drawEdges();
    drawColumns();
}

// 1. calculation

// 1.1 columns

let columns;
let maxRound; // make sure the script won't run into maximum loop by checking on worst case

function createColumns() {
    columns = [];
    maxRound = components.length;
    createColumn(0);
}

function createColumn(nr) {
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
        }
    }

    if(components.length!=0 && nr!=maxRound) createColumn(nr+1);
}

// x.x position components

const gateSize = 80;
const componentCenter = gateSize / 2;
const space = 20;

function positionComponents() {
    let x = space;

    for (let i = 0; i < columns.length; i++) {
        let column = columns[i];
        column.x = x;

        for (let j = 0; j < column.length; j++) {
            let component = column[j];
            component.x = x;
            component.y = j * (gateSize + space);
        }

        let top = column.length * (gateSize + space) - space;
        column.populations = [[0, top]]; // setting first population

        let next = getNextAmount(i);
        let neighborPrevious = getNeighborPreviousAmount(i);

        column.space = { // spaces reserved for edge lines
            start: x += space + gateSize,
            end: (x += (next + neighborPrevious) * space) - space
        }
    }
}

// param index is column index
function getNextAmount(index) {
    let column = columns[index];
    let count = 0;

    for (let i = 0; i < column.length; i++){
        let next = column[i].next;

        for (let j = 0; j < next.length; j++) { // loop through previous of component
            if (index == 0 || index+1 != getColumnIndex(next[j]) || i != getComponentIndex(next[j])) {
                count++;
                break;
            }
        }
    }
    return count;
}

// param index is column index
function getNeighborPreviousAmount(index, componentIndex) {
    if (index + 1 == columns.length) return 0;
    let column = columns[index+1];
    let count = 0;
    for (let i = 0; i < column.length; i++) { // loop throught components in column
        let previous = column[i].previous;
        for(let j=0; j<previous.length; j++){ // loop through previous of component
            let columnIndex = getColumnIndex(previous[j]);
            if (index != columnIndex/* && i != getComponentIndex(previous[j])*/) {
                count++;
                break;
            }
        }
    }
    return count;
}

// 1.2 edges TODO

let edges;

function createEdges() {
    edges = [];

    for (let i = 0; i < columns.length; i++){ // loop through columns
        let column = columns[i];

        for (let j = 0; j < column.length; j++){ // loop through column components
            let component = column[j];
            let nextLength = component.next.length;
            let addSpace = false;

            if(nextLength){
                let excludeY = [];
                let index = edges.length;
                let edge = edges[index] = {};
                let routes = [];

                let y = getEdgeStartY(column, component);

                edge.start = {
                    x: column.x + gateSize / 2,
                    y: y
                }
                edge.crossroad = {
                    x: column.space.start,
                    y: y
                }

                edge.lines = [];
                let lines = edge.lines;

                for (let k = 0; k < nextLength; k++){ // loop through component next
                    let next = getComponent(component.next[k]);
                    let destinationIndex = getColumnIndex(next.id);
                    let destinationNeighborColumn = columns[destinationIndex-1];
                    let destinationColumn = columns[destinationIndex];
                    let line = lines[k] = [];
                    let connectionY = next.y + gateSize / (next.previous.length + 1) * (next.previous.indexOf(component.id) + 1);

                    if(i == destinationIndex-1 && (i == 0 || j!=destinationColumn.indexOf(next))){ // line connects to column next to it, not straight
                        line.push({x: edge.crossroad.x, y: connectionY});
                        addSpace = true;
                    } else if (i != destinationIndex-1){ // line travels around other columns
                        let travelY = getEdgeTravelY(i+1, destinationIndex-1);
                        routes.push({ start: i + 1, end: destinationIndex - 1, y: travelY });

                        let x = destinationNeighborColumn.space.end;
                        line.push({x: edge.crossroad.x, y: travelY});
                        line.push({x: x, y: travelY});
                        line.push({x: x, y: connectionY});
                        destinationNeighborColumn.space.end -= space;
                        addSpace = true;
                    }

                    line.push({x: destinationColumn.x + gateSize/2, y: connectionY});
                }

                if(edge.lines.length==1 && edge.lines[0].length==1) edge.directLink = true; // makes edge + line blue

                for (let k = 0; k < routes.length; k++) alterRoutesPopulations(routes);

                if(addSpace) column.space.start += space;
            }
        }
    }
}

function getEdgeStartY(column, component) {
    let columnIndex = columns.indexOf(column);

    if (columnIndex != 0) {
        let index = getComponentIndex(component.id);

        for (let i = 0; i < component.next.length; i++){
            let id = component.next[i];
            let next = getComponent(id);
            let nextIndex = getComponentIndex(id);
            let nextColumnIndex = getColumnIndex(id);

            if (columnIndex == nextColumnIndex - 1 && index == nextIndex) {
                return next.y + gateSize / (next.previous.length + 1) * (next.previous.indexOf(component.id) + 1);
            }
        }
    }

    return component.y + gateSize / 2;
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

function getColumn(componentId){
    for (let i = 0; i < columns.length; i++) {
        for (let j = 0; j < columns[i].length; j++) {
            if (columns[i][j].id == componentId) return columns[i];
        }
    }
}

function getEdgeTravelY(originColumnIndex, destinationColumnIndex) {
    let y = 0;
    let match = false;
    let limit = 100*space;

    while (!match && y<=limit) { // loop through y until match or y reached 100
        for (let i = originColumnIndex; i <= destinationColumnIndex; i++){ // loop through specific columns
            match = true;

            let populations = columns[i].populations;

            for(let j=0; j<populations.length; j++){ // loop through column populations
                let population = populations[j];

                if (y >= population[0] && y <= population[1]) {
                    match = false;
                    break;
                }
            }

            if (!match) break;
        }

        if(!match) y += space;
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

function alterRoutesPopulations(routes) {
    for (let i = 0; i < routes.length; i++){
        let route = routes[i];

        alterRoutePopulations(route.start, route.end, route.y);
    }
}

function alterRoutePopulations(originColumnIndex, destinationColumnIndex, y) {
    for (let i = originColumnIndex; i <= destinationColumnIndex; i++) { // loop through columns range
        let populations = columns[i].populations;
        let absorbed = false;

        for (let j = 0; j < populations.length && !absorbed; j++){
            let population = populations[j];

            if (absorbed = (y == population[0]-space || y == population[1]+space)){
                population[y == population[0]-space ? 0 : 1] = y;
            }

            //TODO merge populations
        }

        if(!absorbed) columns[i].populations.push([y, y]);
    }
}

// 2. drawing

const correction = 0.5; // add correction for drawing, to make lines sharp

// 2.1 load canvas

let ctx;

function loadCanvas() {
    let canvas = document.getElementById('canvas');
    if(canvas.getContext) ctx = canvas.getContext('2d');
}

// 2.2 draw edges TODO

function drawEdges() {

    for (let i = 0; i < edges.length; i++){
        let edge = edges[i];
        let lines = edge.lines;

        ctx.strokeStyle = "#0000ff";
        ctx.beginPath();
        ctx.moveTo(edge.start.x + correction, edge.start.y + correction);
        ctx.lineTo(edge.crossroad.x + correction, edge.crossroad.y + correction);
        ctx.stroke();

        ctx.strokeStyle = edge.directLink ? "#0000ff" : "#000";

        for (let j = 0; j < lines.length; j++) {
            let line = lines[j];

            ctx.beginPath();
            ctx.moveTo(edge.crossroad.x + correction, edge.crossroad.y + correction);
            for (let k = 0; k < line.length; k++) ctx.lineTo(line[k].x + correction, line[k].y + correction);
            ctx.stroke();
        }

        ctx.strokeStyle = "#000";
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
        let x = column.x + correction;

        for (let j = 0; j < column.length; j++){
            let component = column[j];
            let y = component.y + correction;
            
            ctx.fillStyle = "#fff";

            if(component.gate!=""){ // gates
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