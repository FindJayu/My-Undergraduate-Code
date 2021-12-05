// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 28, 2021
// Description: Enter the coordinates of two points
// and the program gives you the distance between them!

import java.util.Scanner;
public class Distance {
        public static void main(String[] args) {
                System.out.println("Hello! Please Input 2 Cartesian Coordinates sequentially when prompted");

                Scanner input = new Scanner(System.in);
                System.out.println("Input your first x coordinate:  ");
                double x1 = input.nextDouble();
                System.out.println("Input your first y coordinate:  ");
                double y1 = input.nextDouble();
                System.out.println("Input your second x coordinate:  ");
                double x2 = input.nextDouble();
                System.out.println("Input your second y coordinate:  ");
                double y2 = input.nextDouble();

                double newx = (x2 - x1);
                double newy = (y2 - y1);

                double squarex = Math.pow(newx, 2);
                double squarey = Math.pow(newy, 2);

                double distanceplus = (squarex + squarey);
                double finaldistance = Math.pow(distanceplus, 0.5);

                System.out.println("The distance between your two points is " + finaldistance + "!!!");
        }
}
