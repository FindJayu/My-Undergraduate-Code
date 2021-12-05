// Jack Carson
// CPSC 1070
// Project 1
// 16 Sept 2021

#include <cmath>
#include <string>
#include <time.h> 
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std; 

int flipCount = 0;  

int counter = 0; 
double myTimes[10]; 
double myCharges[10]; // Initialize global variables and arrays for use across functions

void printCoinToss(int n) { 
    if (n == 0) {
        cout << "Heads!" << "\n"; 
    }
    else {
        cout << "Tails!" << "\n"; 
    } 
} // Print Heads! if the input (n) is zero, and Tails! otherwise

int flip(void) { 
    srand(time(NULL)); // Seed the RNG with the time passed since Jan 1, 1970. 

    for (int i = 0; i < flipCount; i++) {
    int flips = (rand() % 2); 
    printCoinToss(flips);      
    } // Reinitialize the loop with a random number 0 or 1 and pass it to printCoinToss()
      // Loop is repeated for each digit entered into the function runCoinToss()
    return 0; 
}

void runCoinToss(int n) {
    flipCount = n; 
    flip(); 
} // Initialize flipCount global variable with the argument of the function, and cal flip()

void calculateCharges(double times[]) {

    for (int i = 0; i < counter; i++) { // Loop fills myCharges[] global array based on values of array argument
        if (times[i] < .5) {
            myCharges[i] = 0; 
            continue;  
        } // Set matching index array to 0 for charges below .5
        else if (times[i] < 1.0) {
            myCharges[i] = 2.0;
            continue; 
        } // Otherwise set charge to 2
        else if (1.0 <= times[i] < 13.0) {
            myCharges[i] = (ceil(times[i]) + 2.0);
            if (myCharges[i] > 15) {
                myCharges[i] = 15; 
                continue; 
            }
        } // For values above 1, remove the decimal value and add 2 for charge
        else {
            myCharges[i] = 15.0; 
        } // Any argument above 15 is changed to 15
    }   

    double hoursCount = 0; 
    double chargeCount = 0; 
    for (int i = 0; i < counter; i++) {
        hoursCount += times[i]; 
    }
    for (int i = 0; i < counter; i++) {
        chargeCount += myCharges[i]; 
    } // Initialize counter variables for hours and charge, used in total count

    cout << "\n"; 
    cout << "Car" << setw(20) << right << "Hours" << setw(26) << right << "Charge ($)" << "\n"; 
    for (int i = 0; i < counter; i++) {
        int space = 20;
        int space2 = 22;
        if (i+1 > 9) space -= 1; 
        if (myCharges[i] > 9) space2 +=1; 
        if (times[i] > 9) {
            space2 -= 1;
            space += 1; 
        }  
        if (times[i] > 99) {
            space2 -= 1;
            space += 1; 
        }  
        if (times[i] > 999) {
            space2 -= 1;
            space += 1; 
        } // Lots of formatting spaces based on if arguments inputted are single, double, or triple digits
 
        cout << (i+1); 
        cout << setw(space) << right;
        cout << fixed << showpoint << setprecision(1);
        cout << times[i];
        cout << setw(space2) << right;
        cout << fixed << showpoint << setprecision(2);
        cout << myCharges[i] << "\n"; // Set decimal precisions and output arrays with car counter

        if (i == (counter-1)) {
            if (i+1 > 9) { 
                space += 3;
                space2 -= 1; 
            } else {
                space += 2;
                space2 -= 1;  
            }   
            if (hoursCount > 9) { 
                space += 1; 
                if (hoursCount < 99) {
                    space -= 1; 
                    space2 += 1; 
                }
            }  // Resize width spaces based on whether totals are single, double, or triple. 
            cout << "Total:";
            cout << setw(space-6) << right; 
            cout << fixed << showpoint << setprecision(1); 
            cout << hoursCount; 
            cout << setw(space2) << right; 
            cout << fixed << showpoint << setprecision(2); 
            cout << chargeCount; 
        } // Output totals 
    } 
}

void putCarInfo(void) { 
    cout << "Enter 10 customers's times: " << endl; 

    for (int i = 0; i < 10; i++) { // fill the array myTimes with user inputs
        counter += 1; // Increment counter for each member of the array
        cin >> myTimes[i]; 
        if (myTimes[i] == -999 ) {   
            counter -= 1; // Decrement counter when sentinel is called 
            break;
        }
    }
    calculateCharges(myTimes); // Call calculateCharges with the myTimes[] array
} 

int main() { 
    cout << "How many coin tosses? "; 
    cin >> flipCount; 

    runCoinToss(flipCount); 
    cout << "\n"; 
    putCarInfo(); 
} // Call runCoinToss(), and putCarInfo(). This is turn calls the other functions. 