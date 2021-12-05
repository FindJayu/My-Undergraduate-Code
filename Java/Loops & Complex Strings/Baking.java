// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 6
// Date: Feb 17, 2021
// Description: Displays a celsius to fahrenheit conversion table using a for loop.

public class Baking {
    public static void main(String[] args) {

        System.out.println(" \u00B0C       \u00B0F");
        System.out.println("-------------");

        for (double celsius = 80; (celsius <= 240); celsius += 10) {
            double fahrenheit = ((celsius * 9/5) + 32);
            int celsius1 = (int) celsius;
            int fahrenheit1 = (int) fahrenheit;

            if (celsius1 < 100) {
                System.out.println(celsius1 + "        " + fahrenheit1);
            } else {
                System.out.println(celsius1 + "       " + fahrenheit1);
            }
        }
        // Prints celsius in increments of 10 and uses double celsius to convert to fahrenheit
        // Typecasts celsius and fahrenheit back to int and prints values for celsius <= 240
        // if else used to solve double digit celsius spacing issue
    }
}
