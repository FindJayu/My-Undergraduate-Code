// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 6
// Date: Feb 17, 2021
// Description: Utilizes nested loops to display 3 patterns in the console.

public class Pattern {
    public static void main(String[] args) {

        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }

    System.out.println();
    System.out.println();

        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }

    System.out.println();
    System.out.println();

        for (int i = 1; i <= 9; i++) {
            for (int j = 9; j >= i; j--) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    // Same initial loop for each nested grouping
        // Counts up from 1 to 9, runs inside loop, prints a new line
    // First nested loop prints until 9 and then moves to a new line
    // Second nested loop also starts at 1, and technically prints each increment of both i + j
    // Third nested loop starts at 9 and prints increments downwards until it hits that iteration of loop i (Works in reverse)
    }
}
