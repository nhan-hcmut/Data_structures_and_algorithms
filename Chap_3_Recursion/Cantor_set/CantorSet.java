/*
Print Cantor set by characters X and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => Line = 0. Stop = 9. There are 9 Xs. 9 = 3^2 = power(order-1-line)
XXX   XXX => Line = 1. Stop = 3. There are 3 Xs. 3 = 3^1 = power(order-1-line)
X X   X X => Line = 2. Stop = 1. There is 1 X. 1 = 3^0 = power(order-1-line)
*/

import java.util.Scanner; // Library to take input from users

public class CantorSet {
    static int stop = 0; // A flag to stop the recursion
    
    public static int power(int n) { // Calculate 3 raised to power of n
        
        if (n == 0) return 1;
        
        return 3 * power(n-1);
    }
    
    public static void print_space(int n) { // Print n spaces
        for (int i=0; i<n; i++) {
            System.out.print(" ");
        }
    }
    
    public static void print_x(int n) { // Print X(s) recursively
        if (n == stop) {
            for (int i=0; i<n; i++) {
                System.out.print("X");
            }
        }
        
        else {
            print_x(n/3);
            print_space(n/3);
            print_x(n/3);
        }
    }
    
	public static void main(String[] args) {
	    
	    int order = 0;
	    
	    Scanner input = new Scanner(System.in);
	    
	    while (order < 1) {
	        System.out.print("Order (>0): ");
	        order = input.nextInt();
	    }
	    
	    for (int line = 0; line < order; line++) {
	        stop = power(order-1-line);
	        print_x(power(order-1));
	        System.out.print("\n");
	    }
	}
}
