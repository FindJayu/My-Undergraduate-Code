// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 28, 2021
// Description: Your phone tells you it is 11pm so you
// set a timer to go off in (x) hours. What time will the alarm go off?
// this program will answer that question!

import java.util.Scanner;
public class Alarm {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Your phone says it is 11pm, how many hours would you like to set your timer for?");
        int time = input.nextInt();

        int whattime = (11 + time) % 12;

        if(whattime == 0)
            System.out.println("Your alarm will go off at 12 o'clock!");
        else
            System.out.println("Your alarm will go off at " + whattime + " o'clock!");

    }
}
