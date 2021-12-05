// Name: Jack Carson
// Lab Partner: Anthony Davis
// Course & Lab: CPSC 1061 Lab 6
// Date: Feb 17, 2021
// Description: Simulates 100 iterations of a coin toss using a while loop
// and prints out the number of heads and tails after each iteration.

public class CoinTosses {
    public static void main(String[] args) {

        int count = 0;
        int heads = 0;
        int tails = 0;

        while (count < 100) {
            count++;
            double toss = (int) (1 + Math.random() * 2);
            if (toss == 2.0) {
                heads++;
            }
            if (toss == 1.0) {
                tails++;
            }
        }
        System.out.println("The number of heads is: " + heads);
        System.out.println("The number of tails is: " + tails);

        // adds to count and runs Math.random each iteration
        // Math.random of 1 and 2
        // Adds 1 to the variable heads for a 2.0 value and 1 to the variable tails for a 1.0 value of toss
        // After 100 iterations exits the while loop and prints each count
    }
}
