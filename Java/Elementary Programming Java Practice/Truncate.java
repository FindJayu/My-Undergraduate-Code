// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 28, 2021
// Description: Asks the user for a floating point number, then truncates the
// number down to one digit after the zero digit & displays the result!

import java.util.Scanner;

public class Truncate {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please input a floating point number:  ");
        float num = input.nextFloat();

        int num2 = (int) num;
        System.out.println(num2);






    }
}
