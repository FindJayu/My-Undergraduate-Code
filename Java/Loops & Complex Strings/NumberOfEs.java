// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 6
// Date: Feb 17, 2021
// Description: Asks the user for a word and prints the number of uppercase E's & lowercase e's.

import java.util.Scanner;
public class NumberOfEs {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please input a word: ");
        String s = input.next();

        int i = 0;
        int enumber = 0;
        int Enumber = 0;

        while (i < s.length()) {
            if (s.charAt(i) == 'e') {
                enumber += 1;
            }
            if (s.charAt(i) == 'E') {
                Enumber += 1;
            }
        i++;
        }
        System.out.println("There are " + enumber + " e's in your word");
        System.out.println("There are " + Enumber + " E's in your word");

        // input a string
        // initialize counts of 'e' and 'E'
        // index occurrences of 'e' and 'E'
        // get a count of each index
        // Adds to each Enumber & enumber variable if incremented method == 'E' or 'e' respectively
        // prints counts after i matches string length (no addition required) first and last indexes are read
    }
}
