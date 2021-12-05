// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 8
// Date: March 3, 2021
// Description: Creates a method with two arrays of the same size as parameters and sums the corresponding elements of each.
// If the vectors are different lengths, method prints an error and returns array of length 1 with a value of 0.

import java.util.Arrays;
public class AddVectors {
    public static void main(String[] args) {

        int[] u1 = {1, 2, 3, 4};
        int[] v1 = {-5, -6, -7, -8};
        int[] u2 = {4, 8, 15};
        int[] v2 = {16, 23, 42};

    addV(u1, v1);
    addV(u1, u2);
    addV(v1, v2);

    }
    public static void addV(int[] list1, int[] list2) {

        if (list1.length != list2.length) {
            int[] errorArray = {0};
            System.out.print("ERROR: Inputted arrays are of different sizes: ");
            System.out.print(errorArray[0]);
            System.out.println();
            return;
        }

        int[] newArray = new int[list1.length];
        for (int i = 0; i < list1.length; i++) {
            newArray[i] = list1[i] + list2[i];
        }
        System.out.println(Arrays.toString(newArray));
    }
}
// Method addV takes two int arrays as parameters.
// breaks out of method if the two array parameters are not equal length.
// Prints an error and array of size 1 with 0 stored as index 0.
// Otherwise, creates a new array with the size of parameter arrays and initializes values with a for loop.
// Formats the newArray and prints to console.
