// Jack Carson
// CPSC 1060
// 22 March 2021
// Project 1

import java.util.Scanner;

public class Battleship {

    public static int row;
    public static int column; // Creates variables for row and column input values in order to simplify code

    public static int playerShips = 18;
    public static int computerShips = 18; // Initializes count of "S" squares remaining on both grids

    public static String[][] playerGrid = {
            {".", "S", "S", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", "S", "S", "S", "S", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", "S", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", "S", ".", ".", ".", "S", ".", ".", "."},
            {".", ".", "S", ".", "S", ".", "S", ".", ".", "."},
            {".", ".", "S", ".", ".", ".", "S", ".", ".", "."},
            {".", ".", "S", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", "S", "."},
            {".", ".", ".", "S", "S", ".", ".", ".", ".", "."}
    }; // Creates grid containing player's ships

    public static String[][] computerGrid = {
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", "S", "S", "S", "S", "S", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", "S", ".", "S", "."},
            {".", ".", "S", "S", ".", ".", "S", ".", "S", "."},
            {".", ".", ".", ".", ".", ".", "S", ".", ".", "."},
            {".", ".", "S", "S", "S", ".", "S", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", "S", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", "S", ".", ".", ".", ".", ".", ".", ".", "."}
    }; // Creates grid containing computer's ships

    public static String[][] attackGrid = {
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."},
            {".", ".", ".", ".", ".", ".", ".", ".", ".", "."}
    }; // Creates grid containing open sea. Displayed in the case that (displayShips == false)

    public static void main(String[] args) {

        System.out.println("*** Welcome to Battleship ***");
        System.out.println();

        System.out.println("   This is your grid");
        createGrid();

        while (playerShips > 0 || computerShips > 0) {
            battle();
        }
    } // main method prints initial game messages, prints the player's grid, and begins to loop through the battle() method

    public static void displayShips(boolean ships) {
        if (!ships) { // Prints grid with ships hidden
            printGrid();
        }
        if (ships) { // Prints grid with ships visible
            System.out.print("  ");
            for (int i = 0; i < 10; i++)
                System.out.print(i + " ");
            System.out.println();
            System.out.print("  ");
            for (int i = 0; i < 10; i++)
                System.out.print("- ");
            System.out.println();

            for (int i = 0; i < computerGrid.length; i++) {
                System.out.print(i + "|");
                for (int y = 0; y < computerGrid[i].length; y++) {
                    System.out.print(computerGrid[i][y] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    } // Prints either computer grid (Ships Visible) or attack grid (Ships Hidden)

    public static void createGrid() {
        System.out.print("  ");
        for (int i = 0; i < 10; i++)
            System.out.print(i + " ");
        System.out.println();
        System.out.print("  ");
        for (int i = 0; i < 10; i++)
            System.out.print("- ");
        System.out.println();

        for (int i = 0; i < playerGrid.length; i++) {
            System.out.print(i + "|");
            for (int y = 0; y < playerGrid[i].length; y++) {
                System.out.print(playerGrid[i][y] + " ");
            }
            System.out.println();
        }
        System.out.println();
    } // Print's the player's grid

    public static void printGrid() {
        System.out.print("  ");
        for (int i = 0; i < 10; i++)
            System.out.print(i + " ");
        System.out.println();
        System.out.print("  ");
        for (int i = 0; i < 10; i++)
            System.out.print("- ");
        System.out.println();

        for (int i = 0; i < attackGrid.length; i++) {
            System.out.print(i + "|");
            for (int y = 0; y < attackGrid[i].length; y++) {
                System.out.print(attackGrid[i][y] + " ");
            }
            System.out.println();
        }
        System.out.println();
    } // Prints the computer's grid with ships hidden, printed using the displayShips method if the method parameter is false

    public static void battle() {
        System.out.println("Where would you like to attack?");

        getUserInput();
        displayShips(false);

        getComputerInput();
        createGrid();
    } // On standard turns, prints 3 grids. (Your previous turn, the computer's turn, and your new turn)
      // Prompts user to choose inputs, loops through player and computer turns until the game is over
      // displayShips method is called here and in the getUserInput. For bug testing please change both method parameters to true

    public static void getUserInput() {
        displayShips(false);

        Scanner input = new Scanner(System.in);
        System.out.println("Choose your X coordinate: ");
        column = input.nextInt();
        System.out.println("Choose your Y coordinate: ");
        row = input.nextInt();

        attackCell();
    } // Prompts the user for coordinates and stores them as the global variables row and column
      // Calls the attackCell() method using these inputted coordinates

    public static void attackCell() {
        if (computerGrid[row][column].equals("S")) {
            computerShips -= 1;
            if (computerShips == 0) {
                gameOver();
            }
            System.out.println("Hit!!");
            attackGrid[row][column] = "X";
            computerGrid[row][column] = "X";
            getUserInput();
        } else
            System.out.println("You missed");
            attackGrid[row][column] = "~";
            computerGrid[row][column] = "~";
    } // Checks the status of the inputted location on the computerGrid
      // In the event of a hit, subtracts one for the amount of computerShips, checks if the game has ended, and prompts the user to input again
      // If the user misses, prints the ~ String to both the attackGrid and computerGrid, and ends the turn

    public static void getComputerInput() {
        column = (int) (Math.random() * 10);
        row = (int) (Math.random() * 10);

        if (playerGrid[row][column].equals("S")) {
            playerShips -= 1;
            if (playerShips == 0) {
                gameOver();
            }
            System.out.println("Computer hit!!");
            playerGrid[row][column] = "X";
            getComputerInput();
        } else if (playerGrid[row][column].equals("X")) {
            getComputerInput();
        } else if (playerGrid[row][column].equals("~")) {
            getComputerInput();
        } else
            System.out.println("Computer missed");
            playerGrid[row][column] = "~";
    } // Creates 2 random values contained within the 10x10 grid (0 x 9)
      // If the random area chosen has already been attacked, uses recursion to create a new random area
      // In the event of a hit, subtracts one for the amount of playerShips, checks if the game has ended, and takes another computer input

    public static void gameOver() {
        if (computerShips == 0) {
            System.out.println("Congratulations!! You have won the game of battleship :)");
            System.exit(1);
        }
        if (playerShips == 0) {
            System.out.println("The computer has won the game of battleship!!");
            System.exit(1);
        }
    } // Only invoked if the amount of computerShips or playerShips is 0
}     // Determines which case is true, and prints the appropriate victory message before exiting the game
