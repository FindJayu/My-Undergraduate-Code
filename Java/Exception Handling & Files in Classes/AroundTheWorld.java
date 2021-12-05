// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 11
// Date: April 7, 2021
// Description: Reads information from a separate file using documented methods
// and prints the number of lines in the novel "Around the World in 80 Days".

import java.io.File;
import java.util.Scanner;
public class AroundTheWorld {
    public static void main(String[] args) throws Exception {

        // Initializes counter variable for the number of lines (Begins with one since the last line is not registered in the written while loop later on)
        int count = 1;

        // Creates an object in the file Class with the JV.txt file as its pathname : String
        File myFile = new File("JV.txt");

        // Creates an object of the scanner Class and includes JV.txt in the object (Allows the file to be scanned)
        Scanner myBook = new Scanner(myFile);

        // Use of exists() method, pretty self-explanatory
        if (myFile.exists()) {
            System.out.println("This file exists!");
        }

        // hasNext() method is true if the file has another token to be read, nextLine() moves to this token and increments the counter. Proceeds until hasNext() returns false
        while (myBook.hasNext()) {
            myBook.nextLine();
            count += 1;
        }
        System.out.println("Your file has " + count + " lines!!");
    }
}


