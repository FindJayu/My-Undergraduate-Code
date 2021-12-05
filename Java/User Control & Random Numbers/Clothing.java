// Name: Jack Carson
// Lab Partner: Brandon Lackey
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 3, 2021
// Description: Asks the user for a temperature in Fahrenheit and prints
// a clothing recommendation based on the temperature.

import java.util.Scanner;
public class Clothing {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("What is the temperature in Fahrenheit?  ");
        int temp = input.nextInt();

        if (40 > temp) {
            System.out.println("It is " + temp + " degrees. Don't forget your jacket!");
        }
        else if (70 >= temp) {
            System.out.println("It is " + temp + " degrees. Wear some pants!");
        }

        if (temp > 70) {
            System.out.println("It is " + temp + " degrees. Wear shorts and a t-shirt!");
        } // Uses two less than operators for two limited variable ranges, then the final greater than operator in the case the integer is anywhere above the specified temperature

    }
}
