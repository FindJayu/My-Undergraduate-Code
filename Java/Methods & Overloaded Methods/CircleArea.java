// Name: Jack Carson
// Lab Partner: Lianna Anderson
// Course & Lab: CPSC 1061 Lab 7
// Date: Feb 24, 2021
// Description: Uses a method circleArea, returning the area of a circle
// with radius r.

public class CircleArea {
    public static void main(String[] args) {

        double radius1 = 2.5;
        double radius2 = 7;
        double radius3 = -2;

        System.out.println(circleArea(radius1));
        System.out.println(circleArea(radius2));
        System.out.println(circleArea(radius3));
    }

    public static double circleArea(double radius) {
            if (radius <= 0) {
                System.out.print("Please input a non negative radius: ");
                radius += Math.abs(radius);
                return radius;
            }
            else {
                System.out.print("The area of your circle is: ");
                return (radius * radius * Math.PI);
            }
    }
}
// If radius is less than 0, adds the absolute value to the radius and returns value.
// Performs area of circle calculation and returns the result in string format.