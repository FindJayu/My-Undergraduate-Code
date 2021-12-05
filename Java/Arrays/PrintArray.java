// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 8
// Date: March 3, 2021
// Description: Creates a method with an array as the parameter.
// Asks the user for double values in this array, and prints the array using the method.

import java.util.Scanner;
import java.util.Arrays;
public class PrintArray {
    public static void main(String[] args) {

        double[] myList = new double[5];

        Scanner input = new Scanner(System.in);
        System.out.println("Enter " + myList.length + " double values: ");
        for (int i = 0; i < myList.length; i++) {
            myList[i] = input.nextDouble();
        }

        format(myList);
    }

    public static void format(double[] list) {
        System.out.println(Arrays.toString(list));
    }
}
// Creates initial array of size 5 and fills array with scanner inputs using for loop.
// Calls format method to format the inputted double values in the array
// Method uses Arrays.toString method and returns the organized array.

