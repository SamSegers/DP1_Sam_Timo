function main() {
    loadColumns();
    assignShapes(); //TODO
    initLines() //TODO
    loadCanvas();
    drawComponents(); //TODO
    drawComponents(); //TODO
}

// 1. columns

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
        for(let j = 0; j < component.callers.length; j++){
            let isPlaced = true;
            for(let k = 0; k < componentsRound.length; k++){
                if (component.callers[j] == componentsRound[k].id) { // caller component is not placed yet
                    isPlaced = false;
                    break;
                }
            }
            if(isPlaced) calls++;
        }

        if(calls==component.callers.length){
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

// x. shapes TODO

function assignShapes() {
    // figure out if I should do this in Output.cpp/Diagram.cpp
}

// x. lines TODO

let lines;

function initLines() {

}

// 2. drawing

// 2.1 load canvas

let ctx;

function loadCanvas() {
    let canvas = document.getElementById('canvas');
    if(canvas.getContext) ctx = canvas.getContext('2d');
}

// 2.2 draw lines TODO

function drawLines() {

}

// 2.3 draw components TODO

function drawComponents() {

}


main();