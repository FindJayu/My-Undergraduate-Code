// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 10
// Date: March 31, 2021
// Description: Encapsulates the Cabin class and creates getter and mutator methods. Then uses OOP principles
// to try and find the lowest cabin cost in a different class.

public class TestSummer {
    public static void main(String[] args) {

        // Create first cabin in Summer Class, use setter methods to assign values to private data fields
        Summer firstCabin = new Summer();
        firstCabin.setName("Lake Lure");
        firstCabin.setRate(460);
        firstCabin.setOccupancy(4);

        // Call pricePerPerson() for the first cabin, and print the number of cabins in the Summer Class
        System.out.println("The " + firstCabin.getName() + " cabin costs " + firstCabin.getRate() + " per night and lodges " + firstCabin.getOccupancy() + " people");
        firstCabin.pricePerPerson();
        System.out.println("There are now " + Summer.nbOfCabins + " cabins in your database");
        System.out.println();

        // Create second cabin in Summer Class, use setter methods to assign values to private data fields
        Summer secondCabin = new Summer();
        secondCabin.setName("Asheville");
        secondCabin.setRate(525);
        secondCabin.setOccupancy(5);

        // Call pricePerPerson() for the second cabin, and print the number of cabins in the Summer Class
        System.out.println("The " + secondCabin.getName() + " cabin costs " + secondCabin.getRate() + " per night and lodges " + secondCabin.getOccupancy() + " people");
        secondCabin.pricePerPerson();
        System.out.println("There are now " + Summer.nbOfCabins + " cabins in your database");
        System.out.println();

        // Create third cabin in Summer Class, use setter methods to assign values to private data fields
        Summer thirdCabin = new Summer();
        thirdCabin.setName("Greensboro");
        thirdCabin.setRate(950);
        thirdCabin.setOccupancy(10);

        // Call pricePerPerson() for the third cabin, and print the number of cabins in the Summer Class
        System.out.println("The " + thirdCabin.getName() + " cabin costs " + thirdCabin.getRate() + " per night and lodges " + thirdCabin.getOccupancy() + " people");
        thirdCabin.pricePerPerson();
        System.out.println("There are now " + Summer.nbOfCabins + " cabins in your database");
        System.out.println();

        System.out.println("The " + thirdCabin.getName() + " cabin has the lowest price per person of the available cabins");

    }
}

class Summer {

    // Assigned private modifiers to the data fields
    private String name;
    private double rate;
    private int occupancy;

    static int nbOfCabins = 0;

    // Changed constructor to no arg in order to showcase setter methods
    public Summer() {
        name = " ";
        rate = 0;
        occupancy = 0;
        nbOfCabins++;
    }

    public void pricePerPerson() {
        System.out.println("The price per person of cabin " + name + " is: " + (rate/occupancy));
    }

    // Name Getter
    public String getName() {
        return name;
    }

    // Name Setter
    public void setName(String newName) {
        this.name = newName;
    }

    // Rate Getter
    public double getRate() {
        return rate;
    }

    // Rate Setter
    public void setRate(double newRate) {
        this.rate = newRate;
    }

    // Occupancy Getter
    public int getOccupancy() {
        return occupancy;
    }

    // Occupancy Setter
    public void setOccupancy(int newOccupancy) {
        this.occupancy = newOccupancy;
    }

} // All getter and setter methods are public, and can be used to change the values of private data fields (Cool!!)


