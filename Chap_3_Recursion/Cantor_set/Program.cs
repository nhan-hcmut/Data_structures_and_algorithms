/*
Print Cantor set by X(s) and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => Line = 0. Stop = 9. There are 9 Xs. 9 = 3^2 = power(order-1-line)
XXX   XXX => Line = 1. Stop = 3. There are 3 Xs. 3 = 3^1 = power(order-1-line)
X X   X X => Line = 2. Stop = 1. There is 1 X. 1 = 3^0 = power(order-1-line)
*/
using System;

public class Cantor
{
    public static int stop; // A flag to stop the recursion

    public static int power(int n) // 3 raised to the power of n
    {
        if (n == 0) return 1;
        return 3 * power(n - 1);
    }

    public static void print_space(int n) { // Just print n spaces
        for (int i = 0; i < n; i++)
        {
            Console.Write(" ");
        }
    }

    public static void print_x(int n) // Print n X(s) recursively
    {
        if (n == stop)
        {
            for (int i = 0; i < stop; i++) {
                Console.Write("X");
            }
        }
        else
        {
            print_x(n / 3);
            print_space(n / 3);
            print_x(n / 3);
        }
    }

    public static void Main(string[] args)
    {
        int order = 0; // Order of Cantor set

        while (order<1 || 5<order) {
            Console.Write("Order (from 1 to 5): ");
            order = Convert.ToInt32(Console.ReadLine());
        }

        for (int line = 0; line < order; line++) {
            stop = power(order - 1 - line);
            print_x(power(order - 1));
            Console.WriteLine();
        }
        Console.ReadLine();
    }
}