// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 25, 2021
// Description: Demonstrates which error occurs when the wrong input is submitted into the program

import java.util.Scanner;
public class WhichError {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a String:  ");

        double errortest = input.nextDouble();
        System.out.println(errortest);

    // The following program will produce a logic error
    // String values cannot be stored as the double data type
    }
}
