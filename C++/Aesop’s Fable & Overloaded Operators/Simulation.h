// Jack Carson
// CPSC 1070
// Project 2
// 10 October 2021

# ifndef SIMULATION_H
# define SIMULATION_H
typedef unsigned int ui; // Typedef used in .h and .cpp Simulation files

class Simulation {
    public:
        unsigned int square;
        Simulation() {
            this->square = 1; 
        } 
        // Declaration of square data field, and No-Arg constructor
        // Which assigns the data field square of the constructed
        // Object to 1 using the "this" implicit pointer

        void runOneGame();
        void moveHare(ui *harePtr);
        void moveTortoise(ui *turtlePtr);

        bool hareWin(ui *harePtr); 
        bool turtleWin(ui *turtlePtr);
        void displayRace(ui *harePtr, ui *turtlePtr);

        // Functions created with stated parameters
        // 3 Functions added to track and display the game state 
        // hareWin(), turtleWin(), and displayRace()
};

# endif