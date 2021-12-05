// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 10
// Date: March 31, 2021
// Description: Asks the user for a double value and prints 20 random numbers inclusive of 0
// and exclusive of the given number.

import java.util.Scanner;
import java.util.Random;
public class UseRandom {
    public static void main(String[] args) {

        // Create a Scanner value of type double
        Scanner input = new Scanner(System.in);
        System.out.println("Please input a positive number of your choice");
        double num = input.nextDouble();

        // Create an object in the Random Class (nextDouble() method is public)
        System.out.println();
        Random myObj = new Random();

        // Invoke object in for loop to call the nextDouble() method
        System.out.println("Here are 20 numbers between 0 and your integer");
        for (int i = 0; i < 20; ++i) {
            System.out.println(myObj.nextDouble() * num);
        }

    }
}