// Jack Carson
// CPSC 1060
// 15 April 2021
// Project 2

import java.io.File;
import java.lang.String;
import java.util.Scanner;
import java.util.ArrayList;

public class TakeTheQuiz {
    public static void main(String[] args) throws Exception {

        // Create ArrayList to hold QAndA Objects (Hold a Question & Answer String)
        ArrayList<QAndA> myFlashCards = new ArrayList<>();

        System.out.println("Which chapters would you like to study for?");

        Scanner a = new Scanner(System.in);
        System.out.println("Input 1 to choose Database:");
        String a1 = (a.nextLine());

        // If 1 is inputted, Database.txt is read from the String array in Subclass Chapter
        if (a1.equals("1")) {
            File f1 = new File(Chapter.ch[0]);
            Scanner s1 = new Scanner(f1);

            // Database.txt lines are stored as QAndA objects in myFlashCards ArrayList
            // Lines starting with Q: are stored as the question data field, and the next line is stored as the answer data field
            while (s1.hasNext()) {
                String name = s1.nextLine();
                if (name.startsWith("Q:")) {
                    myFlashCards.add(new QAndA (name, s1.nextLine()));
                }
            }
        }

        Scanner b = new Scanner(System.in);
        System.out.println("Input 1 to choose Chapter 10:");
        String b1 = (b.nextLine());

        // If 1 is inputted, Chapter10.txt is read from the String array in Subclass Chapter
        if (b1.equals("1")) {
            File f2 = new File(Chapter.ch[1]);
            Scanner s2 = new Scanner(f2);

            // Chapter10.txt lines are stored as QAndA objects in myFlashCards ArrayList
            // Lines starting with Q: are stored as the question data field, and the next line is stored as the answer data field
            while (s2.hasNext()) {
                String name = s2.nextLine();
                if (name.startsWith("Q:")) {
                    myFlashCards.add(new QAndA (name, s2.nextLine()));
                }
            }
        }

        Scanner c = new Scanner(System.in);
        System.out.println("Input 1 to choose Chapter 11:");
        String c1 = (c.nextLine());

        // If 1 is inputted, Chapter11.txt is read from the String array in Subclass Chapter
        if (c1.equals("1")) {
            File f3 = new File(Chapter.ch[2]);
            Scanner s3 = new Scanner(f3);

            // Chapter11.txt lines are stored as QAndA objects in myFlashCards ArrayList
            // Lines starting with Q: are stored as the question data field, and the next line is stored as the answer data field
            while (s3.hasNext()) {
                String name = s3.nextLine();
                if (name.startsWith("Q:")) {
                    myFlashCards.add(new QAndA (name, s3.nextLine()));
                }
            }
        }

        Scanner d = new Scanner(System.in);
        System.out.println("Input 1 to choose Chapter 12:");
        String d1 = (d.nextLine());

        // If 1 is inputted, Chapter12.txt is read from the String array in Subclass Chapter
        if (d1.equals("1")) {
            File f4 = new File(Chapter.ch[3]);
            Scanner s4 = new Scanner(f4);

            // Chapter12.txt lines are stored as QAndA objects in myFlashCards ArrayList
            // Lines starting with Q: are stored as the question data field, and the next line is stored as the answer data field
            while (s4.hasNext()) {
                String name = s4.nextLine();
                if (name.startsWith("Q:")) {
                    myFlashCards.add(new QAndA (name, s4.nextLine()));
                }
            }
        }

        // If no Files are chosen to be read, program exits
        if (myFlashCards.size() == 0) {
            System.out.println("You have chosen no sets to study :(");
            System.exit(1);
        }

        // Initialize counters for number of questions asked and number of questions correct
        int correct = 0;
        int prompts = 0;

        Scanner input = new Scanner(System.in);
        java.util.Collections.shuffle(myFlashCards); // Shuffles QAndA objects in myFlashCards

        ArrayList<QAndA> wrongGuesses = new ArrayList<>(); // Creates second ArrayList for questions guessed incorrectly

        // Initial for loop to ask each question once
        for (int i = 0; i < myFlashCards.size(); i++) {

            // Counts one question as being asked, and displays the question data field from the first shuffled index in myFlashCards
            prompts += 1;
            System.out.println(myFlashCards.get(i).question);
            System.out.println("What is the answer?:");
            String guess = ("A: ") + input.nextLine(); // String concatenation for String matching clarity

            // If inputted String matches the answer data field of the same index, question is correct
            if (guess.equalsIgnoreCase(myFlashCards.get(i).answer)) {
                System.out.println("Correct!");
                correct += 1;
            }
            // If inputted String does not match, myFlashCards ArrayList index is added to wrongGuesses ArrayList
            else {
                wrongGuesses.add(myFlashCards.get(i));
                System.out.println("Incorrect");
                System.out.println("The correct answer is: " + myFlashCards.get(i).answer);
            }
        }

        System.out.println();
        System.out.println("*** You will now review your incorrect questions ***");
        System.out.println();

        // Asks questions added to the wrongGuesses ArrayList until the size of the ArrayList is 0
        while (wrongGuesses.size() != 0) {
            // Reshuffles ArrayList each iteration, and allows first index to be accessed each iteration with a different question
            java.util.Collections.shuffle(wrongGuesses);

            prompts += 1;
            System.out.println(wrongGuesses.get(0).question);
            System.out.println("What is the answer?:");
            String guess = ("A: ") + input.nextLine(); // String concatenation for String matching clarity

            // If the guess is correct, first index is now removed from the ArrayList wrongGuesses
            if (guess.equalsIgnoreCase(wrongGuesses.get(0).answer)) {
                correct += 1;
                wrongGuesses.remove(0);
                System.out.println("Correct!");
            }
            else {
                System.out.println("Incorrect");
                System.out.println("The correct answer is: " + wrongGuesses.get(0).answer);
            }
        }

        // Prints counters of the number of correct answers (Total original QAndA objects in myFlashCards), and number of guesses
        System.out.println("You got all " + correct + " questions correct after " + prompts + " attempts!");

    }
}

    class QAndA {

        public String question;
        public String answer;

        // Arg Constructor of QAndA Class, invoked in each while loop to create QAndA objects in myFlashCards ArrayList
        QAndA(String q, String a) {
            question = q;
            answer = a;
        }

        @ Override // toString method that overrides the same method in the Object class
        public String toString() {
            return question + "\n" + answer;
        }
}

// Chapter subclass of superclass QAndA
class Chapter extends QAndA {

    // Arg constructor of Class Chapter, invoked by calling the superclass arg constructor
    Chapter(String q, String a) {
        super(q, a);
    }

    // Data field ch contains indexes of each .txt file that can be Scanned into the myFlashCards ArrayList
    public static String[] ch = {"Database.txt", "Chapter10.txt", "Chapter11.txt", "Chapter12.txt"};

}