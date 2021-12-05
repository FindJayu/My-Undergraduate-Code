// Name: Jack Carson
// Lab Partner: Brandon Lackey
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 3, 2021
/* Description: The computer chooses a random integer between 1 and 4.
The user is asked to guess the number.
If the user guesses correctly, “You won!”
If the user does not guess correctly, the computer gives a tip in the form of:
“The answer is not x.” where x is a number other than the one the computer
chose or the one the user chose.
The user is asked to guess the number again. If the user guesses correctly,
“You won at your second attempt!” Otherwise, the user has lost
the game */

import java.util.Scanner;
public class Guess {
    public static void main(String[] args) {

        int num = (int) ((4 * Math.random()) + 1); // Stores the Math.random as an integer, multiples by 4, and adds 1 to get a final range of 1 - 4

        Scanner input = new Scanner(System.in);
        System.out.println("Guess an integer between 1 and 4:  ");
        int guess = input.nextInt();

        if (guess == num) {
            System.out.println("You won!!");
            System.exit(1); // Stops execution in the case you win on the first guess
        }
        else {
            System.out.println("The answer is not " + guess + ". Try again!");
        }

        System.out.println("Guess your second integer between 1 and 4:  ");
        int guess2 = input.nextInt();

        if (guess2 == num) {
            System.out.println("You won, but on your second attempt");
        }
        else {
            System.out.println("You lose :(");
        } // Program uses two if - else statements separated by initializing a new variable for the second guess
    }
}
