// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 9
// Date: March 24, 2021
// Description: Uses the rectangle class, and creates an array holding three rectangles.
// A for loop is then used to find the rectangle with the largest area.

public class RectangleArray {
    public static void main(String[] args) {

        Rectangle[] myArray = new Rectangle[3]; // Creates an array in the Rectangle class

        Rectangle rectangle1 = new Rectangle(3.0, 4.0);
        Rectangle rectangle2 = new Rectangle(5.5, 2.0);
        Rectangle rectangle3 = new Rectangle(2.5, 4.0); // Creates 3 objects in the Rectangle class with the specified dimensions
                                                              // These dimensions can be added by using the Arg Constructor in the Class
        myArray[0] = rectangle1;
        myArray[1] = rectangle2;
        myArray[2] = rectangle3; // Stores 3 objects of the Rectangle class in the Rectangle array myArray

        double max = myArray[0].getArea(); // Assigns a counter to the first index of myArray
        for (int i = 1; i < myArray.length; ++i) {
            if (myArray[i].getArea() > max) {
                max = myArray[i].getArea(); // .getArea() matches the return type of double max, so an array containing reference variables can be expressed as a double (Cool!!!)
            }
        }
        System.out.println("The area of the largest rectangle stored in the array is " + max);
    }
}

