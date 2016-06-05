function main() {
    loadColumns();
    initEdges() //TODO
    loadCanvas();
    loadImages();
    drawEdges(); //TODO
    drawColumns(); //TODO
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
    console.log("column "+nr);
    console.log(components.length+" left to localize");

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
            console.log("localized "+componentRemove.id);
        }
    }

    console.log(columns[nr]);
    if(components.length!=0 && nr!=maxRound) loadColumn(nr+1);
}

// 1.2 lines TODO

let edges;

function initEdges() {
    edges = [];
}

// 2. drawing

// 2.1 load canvas

let ctx;

function loadCanvas() {
    let canvas = document.getElementById('canvas');
    if(canvas.getContext) ctx = canvas.getContext('2d');
}

// 2.2 draw lines TODO

function drawEdges() {
    for (let i = 0; i < edges.length; i++){

    }
}

let imgGates;

function loadImages() {
    imgGates = {};
    let gates = ["AND", "NAND", "NOR", "NOT", "OR", "XNOR", "XOR"];

    for (let i = 0; i < gates.length; i++){
        let gate = gates[i];
        imgGates[gate] = new Image();
        imgGates[gate].src = "img/"+gate+".png";
    }
    console.log(imgGates);
}

// 2.3 draw components TODO

function drawColumns() {
    let x = 5.5;

    for (let i = 0; i < columns.length; i++){
        let column = columns[i];

        for (let j = 0; j < column.length; j++){
            let component = column[j];
            let y = 5+j*100+0.5;

            if(component.gate!=""){ //gates
                ctx.strokeRect(x, y, 80, 80);
                ctx.fillText(component.id, x+20, y+15);
                ctx.drawImage(imgGates[component.gate], x+10, y+25, 60, 30);
                ctx.fillText(component.gate, x+20, y+70);
            } else { // inputs and outputs
                ctx.beginPath();
                ctx.arc(x+45, y+45, 10, 0, Math.PI*2, true);
                ctx.stroke();
            }
        }

        x += 80 + column.length * 30;
    }
}


main();