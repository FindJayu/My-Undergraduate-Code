// Name: Jack Carson
// Lab Partner: Brandon Lackey
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 3, 2021
// Description: Asks the user for a number (integer). If the user enters
// 10, prints “Jackpot!”. Otherwise prints “You lost.”.

import java.util.Scanner;
public class Ten {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please input an integer:  ");
        int guess = input.nextInt();

        if (guess == 10) {
            System.out.println("Jackpot!"); // If the guess (10) is correct, Jackpot is printed
        }
        else {
            System.out.println("You lost"); // Otherwise, you lost
        }

    }
}
