// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 8
// Date: March 3, 2021
// Description: Uses arrays to store various animal names and noises.
// Uses loops to print the song "Old MacDonald Had a Farm".

public class OldMacDonald {
    public static void main(String[] args) {

        final String e = "E-I-E-I-O";

        String[] myAnimals = {"cow", "dog", "cat", "horse", "lamb", "chicken"};
        String[] myNoises = {"moo", "woof", "meow", "neigh", "baa", "cluck"};

        for (int i = 0; i < myAnimals.length; i++) {
            System.out.println("Old MacDonald had a farm");
            System.out.println(e);
            System.out.println("And on that farm he had a " + myAnimals[i]);
            System.out.println(e);
            System.out.println("With a " + myNoises[i] + " " + myNoises[i] + " here");
            System.out.println("And a " + myNoises[i] + " " + myNoises[i] + " there");
            System.out.println("Everywhere a " + myNoises[i] + " " + myNoises[i]);
            System.out.println();
        }
    }
}
// 6 Paragraphs with each animal name and sound.
// For loop iterates through two arrays simultaneously.
// Uses constant e to keep one variable throughout iterations.