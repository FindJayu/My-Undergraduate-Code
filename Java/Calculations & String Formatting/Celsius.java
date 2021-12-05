// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 25, 2021
// Description: Asks the user to input a temperature value in Fahrenheit & converts to Celsius

import java.util.Scanner;
public class Celsius {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Input a temperature in Fahrenheit:  ");

        double fahrenheit = input.nextDouble();
        double celsius = (fahrenheit - 32.0) * (5.0/9.0);

        System.out.println("The temperature in Celsius is:  " + celsius);

    }
}
