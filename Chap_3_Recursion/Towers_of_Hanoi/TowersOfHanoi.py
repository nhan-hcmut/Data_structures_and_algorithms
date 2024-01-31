def move(n, source, destination, auxiliary):
    
    if (n == 1):
        print("Move a disk from " + source + " to " + destination)
    
    else:
        move(n-1, source, auxiliary, destination)
        move(1, source, destination, auxiliary)
        move(n-1, auxiliary, destination, source)
#
disk = int(input("Disk (>=1): "))

move(disk, "left tower", "right tower", "middle tower")
