// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 6
// Date: Feb 17, 2021
// Description: Asks the user for a number n (integer) and then prints all
// of the divisors of n, including 1 and n.

import java.util.Scanner;
public class Divisors {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please input an integer: ");
        int num = input.nextInt();

        System.out.println("Your integer is divisible by: ");
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                System.out.print(i + " ");
            }
        }

        // Initializes scanner variable
        // Loops through all numbers between 1 and the scanner integer
        // Prints all integers with a space if the remainder of division is 0
        // Prime numbers will only print 1 & num for their output
    }
}
