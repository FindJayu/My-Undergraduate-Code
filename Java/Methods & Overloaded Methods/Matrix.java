// Name: Jack Carson
// Lab Partner: Lianna Anderson
// Course & Lab: CPSC 1061 Lab 7
// Date: Feb 24, 2021
// Description: Uses methods r, line, and matrix to print an n-by-n
// matrix where each element is randomly 0 or 1.

import java.util.Scanner;
public class Matrix {

    public static int r() {
        int num = (int) (Math.rint(Math.random()));
        return num;
    }

    public static String line(int size) {
        String s = "";
        for (int i = 0; i < size; i++) {
            s += (r() + " ");
        }
        return s;
    }

    public static void matrix(int size) {
        for (int i = 0; i < size; i++) {
            System.out.print(line(size));
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Choose your matrix size: ");
        int size = input.nextInt();

        matrix(size);
    }
}
// Method r creates a random int of either 0 or 1
// Method line calls method r and creates a string by concatenating r result with a space (Loops until input size is met)
// Method matrix reprints line with the inputted number with a line after each iteration
// matrix(size) calls all three methods (2 indirectly)