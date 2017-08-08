Main.space = 20;

Main.prototype.canvasDimensions;
Main.prototype.columns;
Main.prototype.edges;

function Main() {
    this.canvasDimensions = { height: 0 };
    this.createColumns();
    this.createEdges()
    this.initCanvasHeight();
    this.renderer = new Renderer();

    this.run();
}

// deduce canvas hight by the farthest border + space
Main.prototype.initCanvasHeight = function() {
    this.columns.forEach(column => {
        column.populations.forEach(population => {
            let border = population[1];
            if (border > this.canvasDimensions.height) this.canvasDimensions.height = border;
        })
    });
    this.canvasDimensions.height += Main.space;
}

// basically tell the render do it's job
Main.prototype.run = function() {
    this.renderer.loadCanvas(this.canvasDimensions);
    this.renderer.loadImages();
    this.renderer.drawEdges(this.edges);
    this.renderer.drawColumns(this.columns);
}

Main.prototype.createColumns = function() {
    this.columns = [];
    this.createColumn(0);
    this.positionComponents();
}

Main.prototype.createColumn = function(nr) {
    this.columns[nr] = [];

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
            this.columns[nr].push(componentRemove);
        }
    }

    if(components.length!=0 && nr!=components.length) this.createColumn(nr+1);
}

Main.prototype.positionComponents = function() {
    let x = Main.space;

    for (let i = 0; i < this.columns.length; i++) {
        let column = this.columns[i];
        let y = 0;

        column.x = x;

        for (let j = 0; j < column.length; j++) {
            let component = column[j];
            component.x = x;
            component.y = y;
            y += Component.size + Main.space;
        }

        let top = column.length * (Component.size + Main.space) - Main.space;
        column.populations = [[0, top]]; // setting first population

        let next = this.getNextAmount(i);
        let neighborPrevious = this.getNeighborPreviousAmount(i);

        column.space = { // spaces reserved for edge lines
            start: x += Main.space + Component.size,
            end: (x += (next + neighborPrevious) * Main.space) - Main.space
        }
    }

    this.canvasDimensions.width = x;
}

// param index is column index
Main.prototype.getNextAmount = function(index) {
    let column = this.columns[index];
    let count = 0;

    for (let i = 0; i < column.length; i++){
        let next = column[i].next;

        for (let j = 0; j < next.length; j++) { // loop through previous of component
            if (index == 0 || index+1 != this.getColumnIndex(next[j]) || i != this.getComponentIndex(next[j])) {
                count++;
                break;
            }
        }
    }
    return count;
}

Main.prototype.getColumnIndex = function(componentId){
    for (let i = 0; i < this.columns.length; i++) {
        for (let j = 0; j < this.columns[i].length; j++) {
            if (this.columns[i][j].id == componentId) return i;
        }
    }
}

// param index is column index
Main.prototype.getNeighborPreviousAmount = function(index, componentIndex) {
    if (index + 1 == this.columns.length) return 0;
    let column = this.columns[index+1];
    let count = 0;
    for (let i = 0; i < column.length; i++) { // loop throught components in column
        let previous = column[i].previous;
        for(let j=0; j<previous.length; j++){ // loop through previous of component
            let columnIndex = this.getColumnIndex(previous[j]);
            if (index != columnIndex) {
                count++;
                break;
            }
        }
    }
    return count;
}

Main.prototype.alterRoutesPopulations = function(routes) {
    for (let i = 0; i < routes.length; i++){
        let route = routes[i];

        this.alterRoutePopulations(route.start, route.end, route.y);
    }
}

Main.prototype.alterRoutePopulations = function(originColumnIndex, destinationColumnIndex, y) {
    for (let i = originColumnIndex; i <= destinationColumnIndex; i++) { // loop through columns range
        let populations = this.columns[i].populations;
        let absorbed = false;

        for (let j = 0; j < populations.length && !absorbed; j++){
            let population = populations[j];

            if (absorbed = (y == population[0]-Main.space || y == population[1]+Main.space)){
                population[y == population[0]-Main.space ? 0 : 1] = y;
            }

            //TODO merge populations
        }

        if(!absorbed) this.columns[i].populations.push([y, y]);
    }
}

Main.prototype.createEdges = function() {
    this.edges = [];

    for (let i = 0; i < this.columns.length; i++){ // loop through columns
        let column = this.columns[i];

        for (let j = 0; j < column.length; j++){ // loop through column components
            let component = column[j];
            let nextLength = component.next.length;
            let addSpace = false;

            if(nextLength){
                let excludeY = [];
                let index = this.edges.length;
                let edge = this.edges[index] = {};
                let routes = [];

                let y = this.getEdgeStartY(column, component);

                edge.start = {
                    x: column.x + Component.size / 2,
                    y: y
                }
                edge.crossroad = {
                    x: column.space.start,
                    y: y
                }

                edge.lines = [];
                let lines = edge.lines;

                for (let k = 0; k < nextLength; k++){ // loop through component next
                    let next = this.getComponent(component.next[k]);

                    if(next){
                        let destinationIndex = this.getColumnIndex(next.id);
                        let destinationNeighborColumn = this.columns[destinationIndex-1];
                        let destinationColumn = this.columns[destinationIndex];
                        let line = lines[k] = [];
                        let connectionY = next.y + Component.size / (next.previous.length + 1) * (next.previous.indexOf(component.id) + 1);

                        if(i == destinationIndex-1 && (i == 0 || j!=destinationColumn.indexOf(next))){ // line connects to column next to it, not straight
                            line.push({x: edge.crossroad.x, y: connectionY});
                            addSpace = true;
                        } else if (i != destinationIndex-1){ // line travels around other columns
                            let travelY = this.getEdgeTravelY(i+1, destinationIndex-1);
                            routes.push({
                                start: i + 1,
                                end: destinationIndex - 1,
                                y: travelY
                            });

                            let x = destinationNeighborColumn.space.end;
                            line.push({x: edge.crossroad.x, y: travelY});
                            line.push({x: x, y: travelY});
                            line.push({x: x, y: connectionY});
                            destinationNeighborColumn.space.end -= Main.space;
                            addSpace = true;
                        }

                        line.push({x: destinationColumn.x + Component.size/2, y: connectionY});
                    }
                }

                if(edge.lines.length==1 && edge.lines[0].length==1) edge.directLink = true; // makes edge + line blue

                for (let k = 0; k < routes.length; k++) this.alterRoutesPopulations(routes);

                if(addSpace) column.space.start += Main.space;
            }
        }
    }
}

Main.prototype.getEdgeStartY = function(column, component) {
    let columnIndex = this.columns.indexOf(column);

    if (columnIndex != 0) {
        let index = this.getComponentIndex(component.id);

        for (let i = 0; i < component.next.length; i++){
            let id = component.next[i];
            let next = this.getComponent(id);
            let nextIndex = this.getComponentIndex(id);
            let nextColumnIndex = this.getColumnIndex(id);

            if (columnIndex == nextColumnIndex - 1 && index == nextIndex) {
                return next.y + Component.size / (next.previous.length + 1) * (next.previous.indexOf(component.id) + 1);
            }
        }
    }

    return component.y + Component.size / 2;
}

Main.prototype.getComponent = function(id) {
    for (let i = 0; i < this.columns.length; i++) {
        for (let j = 0; j < this.columns[i].length; j++) {
            if (this.columns[i][j].id == id) return this.columns[i][j];
        }
    }
}

Main.prototype.getComponentIndex = function(id) {
    for (let i = 0; i < this.columns.length; i++) {
        for (let j = 0; j < this.columns[i].length; j++) {
            if (this.columns[i][j].id == id) return j;
        }
    }
}

Main.prototype.getColumn = function(componentId){
    for (let i = 0; i < this.columns.length; i++) {
        for (let j = 0; j < this.columns[i].length; j++) {
            if (this.columns[i][j].id == componentId) return this.columns[i];
        }
    }
}

Main.prototype.getEdgeTravelY = function(originColumnIndex, destinationColumnIndex) {
    let y = 0;
    let match = false;
    let limit = 100 * Main.space;

    while (!match && y<=limit) { // loop through y until match or y reached limit
        for (let i = originColumnIndex; i <= destinationColumnIndex; i++){ // loop through specific columns
            match = true;

            let populations = this.columns[i].populations;

            for(let j=0; j<populations.length; j++){ // loop through column populations
                let population = populations[j];

                if (y >= population[0] && y <= population[1]) {
                    match = false;
                    break;
                }
            }

            if (!match) break;
        }

        if(!match) y += Main.space;
    }

    return y;
}

Main.prototype.getRangeColumnLength = function(originColumnIndex, destinationColumnIndex) {
    let length = Main.columns[originColumnIndex].length;
    for (let i = originColumnIndex; i <= destinationColumnIndex; i++) { // loop through columns range
        if(columns[i].length>length) length = columns[i].length;
    }
    return length;
}

