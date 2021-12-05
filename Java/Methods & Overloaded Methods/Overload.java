// Name: Jack Carson
// Lab Partner: Lianna Anderson
// Course & Lab: CPSC 1061 Lab 7
// Date: Feb 24, 2021
// Description: Utilizes 3 display methods that all display a string
// using different methods of conversion.

public class Overload {

    public static void display(String s1, String s2) {
        System.out.print(s1 + s2);
    }

    public static void display(String myString, int x) {
        for (int i = 0; (i < x); i++) {
            System.out.print(myString);
        }
    }

    public static void display(char c1, int y) {
        for (int i = 0; (i < y); i++) {
            System.out.print(c1);
        }
    }

    public static void main(String[] args) {
        display("Hello", "World");
        System.out.println();
        display("Hello!", 3);
        System.out.println();
        display('J', 5);
    }
}
// Method 1 concatenates 2 inputted strings
// Method 2 repeats parameter string on same line for parameter int iterations
// Method 3 repeats parameter character on same line for parameter int iterations