// Jack Carson
// CPSC 1071: 03
// The Carsonators
// 3 October 2021

#include <bits/stdc++.h>
#include "Loan.h"
#include "Register.h"
#include "Retirement.h"
using namespace std;
// Include all .h files 

void runMenuSystem() {

char input;

Loan myLoan; 
Register myReg;
Retirement myRetirement; 
// Create Objects of each respective .h file

cout << "Starting Clementine Financial Bank" << "\n";
while(true) { // Will be used as default driver function until 'Q' or 'q' calls exit(0)
cout << "******* Welcome to Clementine Financial *******" << endl <<"\n";  
cout << "Menu:" << "\n"; 
cout << "\t" << "[E] Estimate how much money at retirement" << "\n"; 
cout << "\t" << "[L] Loan payoff calculator" << "\n"; 
cout << "\t" << "[R] Run transaction classifier" << "\n";
cout << "\t" << "[Q] Quit program" << "\n";
cout << "\n" << " Enter your choice and press enter: ";
cin >> input; 

// Char input validation
while(!(input=='E'||input=='e'||input =='L'||input=='l'||input=='R'||input=='r'||input=='Q'||input=='q')) { 
    cout << "******* Welcome to Clementine Financial *******" << endl <<"\n";  
    cout << "Menu:" << "\n"; 
    cout << "\t" << "[E] Estimate how much money at retirement" << "\n"; 
    cout << "\t" << "[L] Loan payoff calculator" << "\n"; 
    cout << "\t" << "[R] Run transaction classifier" << "\n";
    cout << "\t" << "[Q] Quit program" << "\n";
    cout << "\n" << " Enter your choice and press enter: ";
    cin >> input;
}

// Switch statement using Constructed objects and . notation to access .h class methods
switch (input) {
    case 'q': case 'Q': exit(0);
        break;
    case 'e': case 'E': myRetirement.estimateDriver();
        break; 
    case 'l': case 'L': myLoan.paymentDriver();
        break; 
    case 'r': case 'R': myReg.processTransaction(); 
        break;      
    }
  } 
}

int main() { 
    runMenuSystem();  
} // Single call to primary driver function


