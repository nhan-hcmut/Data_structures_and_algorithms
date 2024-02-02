import java.util.Scanner;

public class TowersOfHanoi {
    public static void move(int n, String source, String destination, String auxiliary) {
        if (n == 1) System.out.println("Move a disk from " + source + " to " + destination);
        else {
            move(n-1, source, auxiliary, destination);
            move(1, source, destination, auxiliary);
            move(n-1, auxiliary, destination, source);
        }
    }
	public static void main(String[] args) {
	    int disk = 0;
	    Scanner input = new Scanner(System.in);
	    
	    while (disk < 1) {
	        System.out.print("Disk (>0): ");
	        disk = input.nextInt();
	    }
	    move(disk, "left tower", "right tower", "middle tower");
	}
}
