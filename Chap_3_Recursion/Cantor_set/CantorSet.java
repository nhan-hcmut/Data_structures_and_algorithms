import java.util.Scanner;

public class CantorSet {
    static int stop = 0;
    
    public static int power(int n) {
        
        if (n == 0) return 1;
        
        return 3 * power(n-1);
    }
    
    public static void print_space(int n) {
        for (int i=0; i<n; i++) {
            System.out.print(" ");
        }
    }
    
    public static void print_x(int n) {
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
