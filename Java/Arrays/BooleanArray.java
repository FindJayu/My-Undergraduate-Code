// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 8
// Date: March 3, 2021
// Description: Creates an array of 10 randomly assigned boolean values.
// Prints the number of true values each iteration as well as the entire array.

public class BooleanArray {
    public static void main(String[] args) {

        int count = 0;
        boolean[] myArray = new boolean[10];

        for (int i = 0; i < myArray.length; i++) {
            double toss = (int) (1 + Math.random() * 2);
            if (toss == 2) {
                myArray[i] = true;
                count += 1;
            }
            System.out.println(myArray[i]);
        }

        System.out.println();
        System.out.println("The number of true values is: " + count);
        System.out.println("The number of false values is: " + (10 - count));

    }
}
// Creates a count value outside of the for loop scope + boolean array of length 10.
// Initializes a coin toss (1 or 2) every iteration and assigns the indexed value to true if the coin toss is "heads".
// Adds 1 to count for each heads + prints every iteration.
// Exits the loop and displays the number of true and false values using the count value.
