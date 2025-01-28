/*
Print Cantor set by characters X and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => line = 0, stop = 9. There are 9 Xs. 9 = 3^2 = three_power(order - 1 - line)
XXX   XXX => line = 1, stop = 3. There are 3 Xs. 3 = 3^1 = three_power(order - 1 - line)
X X   X X => line = 2, stop = 1. There is 1 X. 1 = 3^0 = three_power(order - 1 - line)
*/

import java.util.Scanner; // Library to take input from users

public class CantorSet {
    static int stop = 0; // A flag to stop the recursion
    
    public static int three_power(int n) { // Calculate 3 raised to power of n
        
        if (n == 0) return 1;
        
        return 3 * three_power(n - 1);
    }
    
    public static void print_space(int n) { // Print n spaces
        for (int i = 0; i < n; i++) {
            System.out.print(" ");
        }
    }
    
    public static void print_x(int n) { // Print X(s) recursively
        if (n == stop) {
            for (int i = 0; i < n; i++) {
                System.out.print("X");
            }
        }
        
        else {
            print_x(n / 3);
            print_space(n / 3);
            print_x(n / 3);
        }
    }
    
	public static void main(String[] args) {
	    
	    int order = 0;
	    
	    Scanner input = new Scanner(System.in);
	    
	    while (order < 1 || order > 5) {
	        System.out.print("Order (from 1 to 5): ");
	        order = input.nextInt();
	    }
	    
	    for (int line = 0; line < order; line++) {
	        stop = three_power(order - 1 - line);
            
	        print_x(three_power(order - 1));
	        System.out.print("\n");
	    }
	}
}
