// Name: Jack Carson
// Lab Partner: Brandon Lackey
// Course & Lab: CPSC 1061 Lab 4
// Date: Feb 3, 2021
// Description: Asks the user for a number between 0 and 6 and
//prints the corresponding day name. Program uses a switch statement.

import java.util.Scanner;
public class Days {
    public static void main(String[] args) {

        System.out.println("Pick an integer between 0 and 6:  ");
        Scanner input = new Scanner(System.in);
        int day = input.nextInt();

        switch (day) {
            case 0 -> System.out.println("Today is Sunday! Have a nice day :)");
            case 1 -> System.out.println("Today is Monday! Have a nice day :)");
            case 2 -> System.out.println("Today is Tuesday! Have a nice day :)");
            case 3 -> System.out.println("Today is Wednesday! Have a nice day :)");
            case 4 -> System.out.println("Today is Thursday! Have a nice day :)");
            case 5 -> System.out.println("Today is Friday! Have a nice day :)");
            case 6 -> System.out.println("Today is Saturday! Have a nice day :)");
        }   // Switch statement used for each integer case between 0 and 6
            // I found this different switch statement syntax while googling, and used it because it seems cleaner and more compressed, hope it is ok!
    }
}
