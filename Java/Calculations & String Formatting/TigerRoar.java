// Name: Jack Carson
// Lab Partner: Bryanna Fulton
// Course & Lab: CPSC 1061 Lab 2
// Date: Jan 25, 2021
// Description: Utilizes a conversion to convert 3km (The distance a tiger roar travels)
// into miles with the output being a full sentence!


public class TigerRoar {
    public static void main(String[] args) {
        double miles;
        double kilometers = 3.0;
        final double CONVERSION = 1.609344;

        miles = kilometers / CONVERSION;
        System.out.println("A Tiger roar can be heard from 3 kilometers away, or "
        + miles + " Miles!");
    }
}
