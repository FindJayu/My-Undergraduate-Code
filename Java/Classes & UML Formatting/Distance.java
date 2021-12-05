// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 9
// Date: March 24, 2021
// Description: Creates a class point based on given specifications.
// Uses methods in the class to compute the distance between 3 different points.

public class Distance {
    public static void main(String[] args) {

        Point a = new Point(1.2, - 0.4);
        Point b = new Point(11.7, - 0.4);
        Point c = new Point(1.2, 13.6); // Create 3 objects of the class Point using the Arg constructor

        System.out.println("Below are the coordinates of points a, b, and c respectively");
        a.printPoint();
        b.printPoint();
        c.printPoint(); // Invoke the printPoint method to format the coordinates of the objects as strings using dot notation

        System.out.println();

        System.out.println("Below are the distances between points (a & b), (b & c), and (c & a) respectively");
        a.distance(b);
        b.distance(c);
        c.distance(a); // Invoke the distance formula to perform the distance calculation between two points using dot notation
    }
}

class Point {

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




