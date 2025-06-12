#include<stdio.h>

void move(int n, const char* const source, const char* const destination, const char* const auxiliary) {
    static int step = 0;
    
    if (n == 1) printf("Step %d: Move a disk from %s to %s.\n", ++step, source, destination);
    
    else {
        move(n - 1, source, auxiliary, destination);
        move(1, source, destination, auxiliary);
        move(n - 1, auxiliary, destination, source);
    }
}

int main() {
    
    int disk = 0;

    while (disk < 1) {
        printf("disk (>=1): ");
        scanf("%d", &disk);
    }
    
    move(disk, "left tower", "right tower", "middle tower");
    
    return 0;
}
