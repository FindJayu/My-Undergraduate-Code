// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 11
// Date: April 7, 2021
// Description: Contains the classes Point and Triangle, and creates an object of point triangle
// that is defined by the points in class Point. Displays the perimeter of this triangle.

public class Perimeter {
    public static void main(String[] args) {

        // Creates three objects of Class point
        Point a = new Point(1.2, - 0.4);
        Point b = new Point(11.7, - 0.4);
        Point c = new Point(1.2, 13.6);

        // Creates an object of class Triangle defined by the objects in class Point
        Triangle myTriangle = new Triangle(a, b, c);

        // Prints the objects of the
        myTriangle.printTriangle();

        System.out.println();

        // Displays the perimeter of the triangle
        myTriangle.perimeter();
    }
}

class Point { // Same Point class as used in lab 9, moved to Perimeter.java for clarity, but can still be called from Distance.java

    double x;
    double y;

    public Point(double one, double two) {
        x = one;
        y = two;
    }

    public void printPoint() {
        System.out.println("(" + x + ", " + y + ")");
    }

    public void distance(Point one) {
        double v1 = (one.x - x) * (one.x - x);
        double v2 = (one.y - y) * (one.y - y);

        System.out.println(Math.sqrt(v1 + v2));
    }
}

class Triangle {

    // Creates data fields that are objects of class Point
    Point p1;
    Point p2;
    Point p3;

    // Arg constructor that requires objects of class Point
    public Triangle(Point one, Point two, Point three) {
        p1 = one;
        p2 = two;
        p3 = three;
    }

    public void printTriangle() {
        System.out.println("The points of your triangle are located at the coordinates:");
        System.out.println("[(" + p1.x + ", " + p1.y + ")," + " (" + p2.x + ", " + p2.y + "), " + "(" + p3.x + ", " + p3.y + ")]");
    }

    public void perimeter() {
        double a1 = Math.pow((p1.x - p2.x), 2) + Math.pow((p1.y - p2.y), 2);
        double a2 = Math.sqrt(a1);
        double b1 = Math.pow((p1.x - p3.x), 2) + Math.pow((p1.y - p3.y), 2);
        double b2 = Math.sqrt(b1);
        double c1 = Math.pow((p2.x - p3.x), 2) + Math.pow((p2.y - p3.y), 2);
        double c2 = Math.sqrt(c1);

        System.out.println("The perimeter of your triangle is: " + (a2 + b2 + c2));
    }
}

