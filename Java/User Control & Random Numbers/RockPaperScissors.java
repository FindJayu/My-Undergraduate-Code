// Name: Jack Carson
// Lab Partner: Brandon Lackey
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 3, 2021
// Description: The program
// randomly generates a number 0, 1, or 2. The number 0 represents rock, 1 represents paper, and 2 represents scissors. The program asks the user to enter
// a number 0, 1, or 2. It then displays a message indicating what the computer
// randomly chose (rock, paper, or scissors), what the user chose, and whether the
// user wins, loses, or if it is a draw.

import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please enter 0, 1, or 2:  ");
        int man = input.nextInt();

        if (man == 0) {
            System.out.println("You chose rock!");
        }
        else if (man == 1) {
            System.out.println("You chose paper!");
        }
        else if (man == 2) {
            System.out.println("You chose scissors!");
        } // Prints 3 possibilities in terms of rock, paper, or scissors

        int mech = (int) (3 * Math.random()); // Creates a random integer between 0 & 2 by storing the Math.random as an int (Will round down to zero if x < 1)

        if (mech == 0) {
            System.out.println("Computer chooses rock!");
        }
        else if (mech == 1) {
            System.out.println("Computer chooses paper!");
        }
        else if (mech == 2) {
            System.out.println("Computer chooses scissors!");
        } // Prints 3 possibilities in terms of rock, paper, and scissors based on the random integer


        if (man == mech) {
            System.out.println("It's a tie!");
        }
        else if (man == 0 && mech == 2) {
            System.out.println("Rock beats scissors, you win!");
        }
        else if (man == 1 && mech == 0) {
            System.out.println("Paper beats rock, you win!");
        }
        else if (man == 2 && mech == 1) {
            System.out.println("Scissors beats paper, you win!");
        }
        else if (mech == 0 && man == 2) {
            System.out.println("Rock beats scissors, you lost :(");
        }
        else if (mech == 1 && man == 0) {
            System.out.println("Paper beats rock, you lost :(");
        }
        else if (mech == 2 && man == 1) {
            System.out.println("Scissors beats paper, you lost :(");
        } // prints all possible outcomes of a rock paper scissors game using all possible move combinations (7 Combinations)

    }
}
