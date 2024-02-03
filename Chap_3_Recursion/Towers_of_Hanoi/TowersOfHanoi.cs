using System;

public class TowersOfHanoi {
    static int step =0 ;
    
    public static void move(int n, string source, string destination, string auxiliary) {
        
        if (n == 1) Console.WriteLine("Step {0}: Move a disk from {1} to {2}", source, destination);
        
        else {
            move(n-1, source, auxiliary, destination);
            move(1, source, destination, auxiliary);
            move(n-1, auxiliary, destination, source);
        }
    }
    public static void Main(string[] args) {
        int disk = 0;
        
        while (disk < 1) {
            Console.Write("Disk (>=1): ");
            disk = Convert.ToInt32(Console.ReadLine());
        }
        move(disk, "left tower", "right tower", "middle tower");
    }
}
