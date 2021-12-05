// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 10, 2021
// Description: Asks the user for a word, and returns the word with the
// first letter capitalized. Returns an error if the user inputs something
// that does not start with a letter.

import java.util.Scanner;
public class Capitalize {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please input a string:  ");
        String word = input.next();


        //10 If statements for each digit, reading the first index of the string. Exits the program if an integer is at the 0 index
        if (word.startsWith(String.valueOf(0))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(1))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(2))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(3))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(4))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(5))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(6))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(7))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(8))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }
        if (word.startsWith(String.valueOf(9))) {
            System.out.println("ERROR: Your String does not start with a letter");
            System.exit(1);
        }

        String word2 = word.toUpperCase();
        String word3 = word2.substring(0,1);
        System.out.println(word3 + word.substring(1));
        // Creates 2 more strings, one being the word in uppercase, and the second being the first character of the uppercase word
        // Concatenates the capital letter substring with the 1 index to end of the original string
    }
}
