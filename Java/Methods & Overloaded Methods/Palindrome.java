// Name: Jack Carson
// Lab Partner: Lianna Anderson
// Course & Lab: CPSC 1061 Lab 7
// Date: Feb 24, 2021
// Description: Uses a method named isPal that checks if a word
// is a palindrome and returns the result as a boolean (Method is case-sensitive).

import java.util.Scanner;
public class Palindrome {

    public static void isPal(String s1) {

        String revs1 = "";

        for (int i = s1.length()-1 ; i >=0 ; i--) {
            revs1 = revs1 + s1.charAt(i);
        }
        if (revs1.equals(s1)) {
            System.out.println(true);
        }
        else
            System.out.println(false);
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Check if a word is palindromic (Capitalization matters): ");
        String s = input.next();
        isPal(s);
    }
}
// Method isPal prints the inputted string in reverse using a for loop
// If the reverse string and parameter string are equal, prints true
// If the reverse string and parameter string are not equal, prints false
