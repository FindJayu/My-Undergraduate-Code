// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 10, 2021
// Description: Asks the user for a character and displays the following:
/*
The unicode value of the character
If the character is a digit
If the character is a letter
If that letter is lowercase or uppercase
*/

import java.util.Scanner;
public class CharInfo {
    public static void main(String[] args) {

        Scanner system = new Scanner(System.in);
        System.out.println("Please input a character: ");
        char a = system.next().charAt(0);

        int i = a;
        System.out.println("The unicode value of your character is : \\u" + i);

        // Sorry, I have no idea how to get this into unicode, this is the closest example from the textbook :(

        System.out.println();

        if (Character.isDigit(a)) {
            System.out.println("You have entered the digit value " + a + "!"); // Original if statement for digit values
        }
        else if (Character.isLetter(a)) {
            System.out.println("Your character is the letter " + a + "!");
            if (Character.isUpperCase(a)) {
                System.out.println("Your character is uppercase");
            }
            if (Character.isLowerCase(a)) {
                System.out.println("Your character is lowercase");
            } //Uses nested if statements to read if the character is uppercase or lowercase if a character is read
        }
    }
}
