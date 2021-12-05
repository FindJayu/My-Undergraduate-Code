// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 28, 2021
// Description: Saves the number of ants on earth as an int variable and displays the result
// then displays the same value as a long datatype, then displays the amount of bacteria in the most appropriate way!

public class Ants {
    public static void main(String[] args) {
        int ants = (int) 5e+15;
        System.out.println("The # of ants in the world in int form is: ");
        System.out.println(ants);
// The number will still print using this method, but only to the maximum value allowed of type int

        long ants2 = (long) 5e+15;
        System.out.println("The # of ants in the world in long form is: ");
        System.out.println(ants2);
// This number will also print, but only to the maximum value of type long

        double bacteria = 5e+30;
        System.out.println("The real # of bacteria on earth is:");
        System.out.println(bacteria);
    }
}
