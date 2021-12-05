// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 10, 2021
// Description: Asks the user for a word and displays the following:
/*
The length of the word
The first letter
The last letter
If the word is "aardvark" or not
If the letter 'e' is in the word
 */

import java.util.Scanner;
public class WordInfo {
    public static void main(String[] args) {

        Scanner system = new Scanner(System.in);
        System.out.println("Please input a word: ");
        String a = system.next();

        System.out.println("Your word is " + a.length() + " letters long");
        System.out.println("The first letter of your word is " + a.charAt(0)); // Reads the first index of the string as the first character
        System.out.println("The last letter of your word is " + a.charAt(a.length() - 1)); // Uses the length function to read the last index of any word length

        if (a.equals("aardvark")) {
            System.out.println("Your word is aardvark");
        }
        if (a.indexOf('e') != -1) { // Method returns -1 if 'e' is not matched, so if -1 is not returned, the console prints the below string
            System.out.println("Your word has an 'e' character in it");
        }
    }
}
