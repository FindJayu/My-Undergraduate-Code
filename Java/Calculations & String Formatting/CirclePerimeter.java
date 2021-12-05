// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 25, 2021
// Description: Computes & displays the perimeter of
// a circle with a radius of 1.5 cm while declaring & utilizing a constant

public class CirclePerimeter {
    public static void main(String[] args) {
        double perimeter;
        double radius = 1.5;
        final double PI = 3.14159;

        perimeter = 2.0 * radius * PI;

        System.out.println("The perimeter of a circle with radius " + radius
        + " is " + perimeter);
    }
}
