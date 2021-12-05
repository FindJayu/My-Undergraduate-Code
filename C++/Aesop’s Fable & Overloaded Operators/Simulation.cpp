// Jack Carson
// CPSC 1070
// Project 2
// 10 October 2021

#include "Simulation.h"
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui; 

/* Function runOneGame() is called in the driver and calls other functions in the class.
Creates objects hare, and turtle and assigns pointers to their square data fields, then
begins a repeating while loop while game victory conditions remain "false"
*/
void Simulation::runOneGame() {
    Simulation hare;
    Simulation turtle;

    ui *harePtr = &hare.square; 
    ui *turtlePtr = &turtle.square;

    while (true) {
        /* Calls moveHare and moveTortoise using their respective pointers, and displays the race using displayRace()
        with the same pointer parameters. Checks the state of the game each iteration for a victor (either or both pointers == 70).
        Also uses usleep(1000000) with 10^6 microseconds as an argument to delay each loop iteration by 1 second
        */
        hare.moveHare(harePtr); 
        turtle.moveTortoise(turtlePtr); 

        displayRace(harePtr, turtlePtr);

        if (hare.hareWin(harePtr) && turtle.turtleWin(turtlePtr)) {
            cout << "WOW!!! A TIE!!!"; 
            break;
        }
        if (hare.hareWin(harePtr)) {
            cout << "HARE WINS!!!";
            break;
        }
        if (turtle.turtleWin(turtlePtr)) {
            cout << "TORTOISE WINS!!!!";
            break;
        }
        usleep(1000000);
    }   
}

/* moveTortoise() takes in the pointer to turtle.square and seeds a random number generator.
Based on the output of this generator stored as num (1-4), a switch statement performs arithmetic on the
pointer to turtle.square, and resets the pointer if it goes above 70, or jumps below 0 
(In this case, pointer is reset to 1 since an unsigned int will overflow if turtlePtr jumps back 6 squares near the start of the race)
*/
void Simulation::moveTortoise(ui *turtlePtr) {
    srand(time(NULL));
    ui num = (rand() % 4) + 1;  

    switch (num) {
        case 1 ... 2: *turtlePtr += 3;
            if (*turtlePtr > 70) {
                *turtlePtr = 70; 
            } 
            break;
        case 3: *turtlePtr += 1;   
            if (*turtlePtr > 70) {
                *turtlePtr = 70; 
            }
            break;
        case 4: *turtlePtr -= 6; 
            if (*turtlePtr > 80) {
                *turtlePtr = 1; 
            }
            break;
    }
}

/* moveHare() performs a similar function to moveTortoise(), instead performing aritmetic on harePtr.
The random number generated here is converted to between 1 and 20, and probabilites are assinged based on
the specific hare requirements. Again, edge cases where the hare "jumps" above 70 and below 0 (Overflow)
are reset with if statements in each case of the switch statement
*/
void Simulation::moveHare(ui *harePtr) {
    srand(time(NULL));
    ui num = (rand() % 20) + 1; 

    switch (num) {
        case 1 ... 5: break;
        case 6 ... 11: *harePtr += 1;
            if (*harePtr > 70) {
                *harePtr = 70; 

            } 
            break;
        case 12 ... 15: *harePtr += 9; 
            if (*harePtr > 70) {
                *harePtr = 70;  
            } 
            break;
        case 16 ... 19: *harePtr -= 2; 
            if (*harePtr > 80) {
                *harePtr = 1; 
            }
            break;
        case 20: *harePtr -= 12;
            if (*harePtr > 80) {
                *harePtr = 1; 
            }
            break; 
    }
}

/* Function returning a boolean based on the condition of harePtr. 
Will return false each iteration until (harePtr == 70), and will then return
true. 
*/
bool Simulation::hareWin(ui *harePtr) {
    bool victor; 
    
    if (*harePtr == 70) {
        victor = true; 
    } else {
        victor = false; 
    }
    return victor; 
}

/* Sister function to hareWin(), will return the boolean variable victor as false
each iteration turtlePtr != 70.
*/
bool Simulation::turtleWin(ui *turtlePtr) {
    bool victor; 

    if (*turtlePtr == 70) {
        victor = true; 
    } else {
        victor = false; 
    }
    return victor; 
}

/* displayRace() takes in the pointers harePtr and turtlePtr, which point to the data fields
hare.square, and turtle.square respectively, and prints the state of the race based on three conditions:
1. The hare is winning
2. The turtle is winning
3. The hare and turtle pointers have the same value
*/
void Simulation::displayRace(ui *harePtr, ui *turtlePtr) {
    /* First case of the race in which the hare is winning. 
    In this case, and all other cases, three for loops are used
    with a character in between each loop. 
    Loop 1 will print '-' until it reaches the value of turtlePtr (Losing) then a 
    'T' will be printed after the loop breaks. 
    Loop 2 will print '-' for the difference separating harePtr and turtlePtr (Space between the two racers)
    then will print an 'H' for the winning Hare. 
    Loop 3 will print '-' for the difference bewtween the end of the race and the leader (harePtr), 
    and will then print a new line for the next displayRace() iteration. 
    */
    if (*harePtr > *turtlePtr) {
        for (int i = 1; i < *turtlePtr; i++) { 
            cout << '-'; 
        } 
        cout << 'T'; 
        for (int i = 1; i < (*harePtr - *turtlePtr); i++) { 
            cout << '-';
        } 
        cout << 'H';
        for (int i = 1; i <= (70 - *harePtr); i++) {
            cout << '-';
        } 
        cout << "\n"; 
    }
    /* Second case in which the turtle is winning the race, which follows the same structure as the above 3 loop system.
    First loop prints the distance between the start and harePtr followed by 'H', the second loop prints
    the difference between the first and second place racers, and the final loop prints the difference between
    the finish line and the leader (turtle). 
    */
    if (*harePtr < *turtlePtr) {
        for (int i = 1; i < *harePtr; i++) {
            cout << '-'; 
        }
        cout << 'H'; 
        for (int i = 1; i < (*turtlePtr - *harePtr); i++) {
            cout << '-';
        }
        cout << 'T';
        for (int i = 1; i <= (70 - *turtlePtr); i++) {
            cout << '-';
        }
        cout << "\n";
    } 
    /* Edge case in which the harePtr and turtlePtr have the same unsigned int value.
    In this case, only two for loops are needed. First printing the difference between 
    the value of the pointer(s) and the start line, and the second printing the
    difference between the two pointer(s) and the finish line with 'O' separting the two
    loops and representing both entities. After, OUCH! is printed on a new line and another
    new line is generated for the next displayRace() iteration. 
    */
    if (*harePtr == *turtlePtr) {
        for (int i = 1; i < *harePtr; i++) {
            cout << '-';
        }
        cout << 'O'; 
        for (int i = 1; i <= (70 - *harePtr); i++) {
            cout << '-'; 
        }
        cout << '\n' << "OUCH!" << '\n'; 
    }
}


