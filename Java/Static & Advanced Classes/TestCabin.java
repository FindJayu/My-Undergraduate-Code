// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 10
// Date: March 31, 2021
// Description: Contains a second class Cabin, and determines the cabin with the cheapest cost per person
// based on the UML diagram for the class.

public class TestCabin {
    public static void main(String[] args) {

        // Create first cabin, call pricePerPerson() method, and print the nbOfCabins in the Cabin Class
        Cabin firstCabin = new Cabin("Lake Lure", 460, 4);
        System.out.println("The " + firstCabin.name + " cabin costs " + firstCabin.rate + " per night and lodges " + firstCabin.occupancy + " people");
        firstCabin.pricePerPerson();
        System.out.println("There are now " + Cabin.nbOfCabins + " cabins in your database");
        System.out.println();

        // Create second cabin, call pricePerPerson() method, and print the nbOfCabins in the Cabin Class
        Cabin secondCabin = new Cabin("Asheville", 525, 5);
        System.out.println("The " + secondCabin.name + " cabin costs " + secondCabin.rate + " per night and lodges " + secondCabin.occupancy + " people");
        secondCabin.pricePerPerson();
        System.out.println("There are now " + Cabin.nbOfCabins + " cabins in your database");
        System.out.println();

        // Create third cabin, call pricePerPerson() method, and print the nbOfCabins in the Cabin Class
        Cabin thirdCabin = new Cabin("Greensboro", 950, 10);
        System.out.println("The " + thirdCabin.name + " cabin costs " + thirdCabin.rate + " per night and lodges " + thirdCabin.occupancy + " people");
        thirdCabin.pricePerPerson();
        System.out.println("There are now " + Cabin.nbOfCabins + " cabins in your database");
        System.out.println();

        System.out.println("The " + thirdCabin.name + " cabin has the lowest price per person of the available cabins");
    }
}

class Cabin {

    String name;
    double rate;
    int occupancy;

    // Create static counter to be added for each object in the class
    static int nbOfCabins = 0;

    // Create arg constructor to give values to data fields, increment nbOfCabins object counter
    public Cabin(String n, double r, int o) {
        name = n;
        rate = r;
        occupancy = o;
        nbOfCabins++;
    }

    // Create void method to calculate rate/occupancy data fields
    public void pricePerPerson() {
        System.out.println("The price per person of cabin " + name + " is: " + (rate/occupancy));
    }
}
