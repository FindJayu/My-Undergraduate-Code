// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 9
// Date: March 24, 2021
// Description: Creates a rectangle with a default height and width, and a rectangle with a height and width chosen
// by the user. Also displays the area of each rectangle.

import java.util.Scanner;
public class TwoRectangles {
    public static void main(String[] args) {

        Rectangle myRectangle = new Rectangle(); // Creates an object in the class Rectangle
        System.out.println("I have created a rectangle with a height of " + myRectangle.height + " ,and a width of " + myRectangle.width);

        System.out.println();

        Scanner input = new Scanner(System.in);
        Rectangle yourRectangle = new Rectangle(); // Creates another object in the class Rectangles

        System.out.println("Please input a height for your rectangle: ");
        yourRectangle.height = input.nextDouble(); // Assigns height data field of yourRectangle to the next double

        System.out.println("Please input a width for your rectangle: ");
        yourRectangle.width = input.nextDouble(); // Assigns width data field of yourRectangle to the next double

        System.out.println();

        System.out.println("You have created a rectangle with a height of " + yourRectangle.height + " ,and a width of " + yourRectangle.width);

        System.out.println("The area of my rectangle is: " + myRectangle.getArea());
        System.out.println("The area of your rectangle is: " + yourRectangle.getArea());
    }
}

// Below is the Rectangle class used in the lecture.

class Rectangle { // Class is Defined (Rectangle Class Definition)

    double width;
    double height; // Creates attributes of the class (Data Fields)
                   // These attributes make the essence of our objects in this class

    Rectangle() { // Objects with no parameters (Rectangle aRectangle = new Rectangle();) Are created here
        width = 2;
        height = 1;
    } // This is a Constructor, and sets the initial values of the class attributes (No Arg Constructor)

    Rectangle(double w, double h) { // Objects with parameters (Rectangle aRectangle = new Rectangle(5.0, 3.0);) Are created here
        width = w;
        height = h;
    } // Constructor with Arguments, assigns parameter values to attributes in the class (Arg Constructor)

    double getArea() {
        return width * height;
    } // Method in the class that multiplies two attributes in the class Rectangle ()
      // We can access this method using the . Operator (aRectangle.getArea();)
}
