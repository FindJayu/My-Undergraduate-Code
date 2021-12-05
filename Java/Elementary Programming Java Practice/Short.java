// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 28, 2021
// Description: Saves largest possible value of type short as (s) then multiplies by 2 *=.
// Explanation of the output of this calculation is provided!

public class Short {
    public static void main(String[] args) {

        short s = 32767;
        s *= 2;
        System.out.println(s);

        System.out.println("The data type short is a 16-bit value, which means it is stored as the 15th power of 2 ((2^15)-1).");
        System.out.println("This is how the number 32767 is stored in the computer, so when it is multiplied by 2, the -1 is also multiplied");
        System.out.println("by two, and the 2^15 becomes incompatible with the short datatype. Therefore, the only number");
        System.out.println("that is printed is the -2 remaining in the operation.");
    }
}
