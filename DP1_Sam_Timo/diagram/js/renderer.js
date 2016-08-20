function Renderer() {}

Renderer.prototype.correction = 0.5; // add correction for drawing, to make lines sharp
Renderer.prototype.ctx; // context
Renderer.prototype.imgGates; // gate images which are loaded once before drawing

Renderer.prototype.loadCanvas = function() {
    let canvas = document.getElementById('canvas');
    if(canvas.getContext) this.ctx = canvas.getContext('2d');
}

Renderer.prototype.loadImages = function() {
    this.imgGates = {};
    let gates = ["AND", "NAND", "NOR", "NOT", "OR", "XNOR", "XOR"];

    for (let i = 0; i < gates.length; i++){
        let gate = gates[i];
        this.imgGates[gate] = new Image();
        this.imgGates[gate].src = "img/"+gate+".png";
    }
}

Renderer.prototype.drawEdges = function(edges) {
    for (let i = 0; i < edges.length; i++){
        let edge = edges[i];
        let lines = edge.lines;

        this.ctx.strokeStyle = "#0000ff";
        this.ctx.beginPath();
        this.ctx.moveTo(edge.start.x + this.correction, edge.start.y + this.correction);
        this.ctx.lineTo(edge.crossroad.x + this.correction, edge.crossroad.y + this.correction);
        this.ctx.stroke();

        this.ctx.strokeStyle = edge.directLink ? "#0000ff" : "#000";

        for (let j = 0; j < lines.length; j++) {
            let line = lines[j];

            this.ctx.beginPath();
            this.ctx.moveTo(edge.crossroad.x + this.correction, edge.crossroad.y + this.correction);
            for (let k = 0; k < line.length; k++) this.ctx.lineTo(line[k].x + this.correction, line[k].y + this.correction);
            this.ctx.stroke();
        }

        this.ctx.strokeStyle = "#000";
    }
}

Renderer.prototype.drawColumns = function(columns) {
    for (let i = 0; i < columns.length; i++) this.drawColumn(columns[i]);
}

Renderer.prototype.drawColumn = function (column) {
    let x = column.x + this.correction;

    for (let j = 0; j < column.length; j++) this.drawComponent(column[j], x);
}

Renderer.prototype.drawComponent = function (component, x) {
    let y = component.y + this.correction;
    
    this.ctx.fillStyle = "#fff";

    if(component.gate!=""){ // gates
        this.ctx.fillRect(x, y, Component.size, Component.size);
        this.ctx.fillStyle = "#000";
        this.ctx.strokeRect(x, y, Component.size, Component.size);
        this.ctx.fillText(component.id, x+15, y+15);
        //this.ctx.fillText(component.gate, x+25, y+45);
        this.ctx.drawImage(this.imgGates[component.gate], x+10, y+25, 60, 30);
        this.ctx.fillText(component.value, x+35, y+70);
    } else { // inputs and outputs
        this.ctx.beginPath();
        this.ctx.arc(x+Component.componentCenter, y+Component.componentCenter, 10, 0, Math.PI*2, true);
        this.ctx.fill();
        this.ctx.fillStyle = "#000";
        this.ctx.arc(x+Component.componentCenter, y+Component.componentCenter, 10, 0, Math.PI*2, true);
        this.ctx.stroke();
        this.ctx.fillText(component.id, x+Component.componentCenter-10, y+Component.componentCenter-20);
        this.ctx.fillText(component.value, x+Component.componentCenter-5, y+Component.componentCenter+25);
    }
}