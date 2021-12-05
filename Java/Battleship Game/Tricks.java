// Jack Carson
// CPSC 1060
// 22 March 2021
// Project 1

import java.util.Scanner;

public class Tricks {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int myNum = 1; // Initialize an input and integer variable, which will be looped in the while loop below

        while (myNum != 0) {
            System.out.println("Please input an integer 0-3: ");
            myNum = input.nextInt();

            if (myNum == 0) {
                zero();
            } else if (myNum == 1) {
                one();
            } else if (myNum == 2) {
                two();
            } else if (myNum == 3) {
                three();
            } // Based on the input, different methods will be invoked based on their corresponding number
        }
    }
    public static void zero() {
        System.out.println("You have chosen to terminate the program");
        System.exit(1);
    } // Prints a message and ends the program if 0 is the input integer

    public static void one() {
        Scanner input = new Scanner(System.in);
        System.out.println("Please input another integer: ");
        int num = input.nextInt();

        System.out.println("Below are even integers less than your integer: ");
        for (int i = 0; i < num; i++) {
            if ((i % 2) == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    } // Prompts the user for another integer using a scanner
      // Uses a for loop to calculate integers below your input integer that are divisible by 2 and prints these numbers

    public static void two () {
        Scanner input = new Scanner(System.in);
        System.out.println("Please input a letter grade A, B, C, D, or F:  ");
        char grade = input.next().charAt(0);

        switch (grade) {
            case 'A' : System.out.println("Your number is 4");
                break;
            case 'B' : System.out.println("Your number is 3");
                break;
            case 'C' : System.out.println("Your number is 2");
                break;
            case 'D' : System.out.println("Your number is 1");
                break;
            case 'F' : System.out.println("Your number is 0");
                break;
        }
    } // Asks the user for a character value using input.next().charAt(0)
      // Uses a switch statement to print a corresponding string for each possible character input (Case-Sensitive)

    public static void three () {
        Scanner input = new Scanner(System.in);

        double i = (97 + Math.random() * 26);
        int j = (int) i;
        char random = (char) j;

        char guess = 0;
        int count = 0;

        while (guess != random) {
            System.out.println("What is my random lowercase letter?  ");
            guess = input.next().charAt(0);

            if (random > guess) {
                System.out.println("Your guess is " + guess);
                System.out.println("The letter is later in the alphabet!");
                count += 1;
            }
            if (random < guess) {
                System.out.println("Your guess is " + guess);
                System.out.println("The letter is earlier in the alphabet!");
                count += 1;
            }
        }
        System.out.println("Congratulations! It took you " + (count + 1) + " guesses to get the correct answer");
    }
} // Creates a random integer between 97 and 122, and typecasts to a character. Also initializes two integers
  // While the input is not equal to the random character, re-prompts the user with a hint and adds to the count
  // After the user has matched their guess with the random character, exits the method and prints the guess count with a message
