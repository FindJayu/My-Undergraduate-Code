// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 10, 2021
// Description: Prints a random lowercase letter.

public class RandomLetter {
    public static void main(String[] args) {

        double i = (97 + Math.random() * 26); // Creates a random double between 97 & 122
        int j = (int) i; // Casts the random double to an integer
        char k = (char) j; // Casts the integer to a character
        System.out.println("Your random lowercase letter is: " + k); // prints the character

    }
}
