let step = 0;

function move(n, source, destination, auxiliary) {
    
    if (n == 1)
        console.log("Step " + (++step) + ": Move a disk from " + source + " to " + destination);
    
    else {
        move(n-1, source, auxiliary, destination);
        move(1, source, destination, auxiliary);
        move(n-1, auxiliary, destination, source);
    }
}

let disk = 3;

console.log("Disk = 3");

move(disk, "left tower", "right tower", "middle tower");
