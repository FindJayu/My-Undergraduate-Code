// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 10, 2021
// Description: Asks for two integers and returns
// the maximum of the two numbers using the max() method.

import java.util.Scanner;
public class Maximum {
    public static void main(String[] args) {

        System.out.println("Input your first integer:  ");
        Scanner system = new Scanner(System.in);
        int first = system.nextInt();

        System.out.println("Input your second integer:  ");
        int second = system.nextInt();

        System.out.println("The highest value of your two integers is " + Math.max(first, second));
        // Initializes two int variables and computes the highest value using the Math.max function with a string for clarity.
    }
}
