// Jack Carson
// CPSC 1071: 03
// The Carsonators
// 3 October 2021

#include "Retirement.h"
#include <bits/stdc++.h>
using namespace std;

// Takes 5 input arguments and returns savings and growth while iterating back to another function
double Retirement::estimateEarnings(int age, int retireAge, double principal, double contribution, double interestRate) {

double principalGrowth = 0; 
double retirementGrowth = 0;
double monthDifference = 12 * (retireAge - age); 

for (double i = 0; i < monthDifference; i++) {
    principalGrowth = principal*(interestRate/1200.0)+contribution; 
    principal += principalGrowth;  
    retirementGrowth += principalGrowth-contribution; 
}

// Increment through each month till retirement and contribute to counter variables, then display
cout << "Estimated Retirement Savings: $" << fixed << showpoint << setprecision(2) << principal << "\n";
cout << "Estimated Retirement Growth: $" << fixed << showpoint << setprecision(2) << retirementGrowth << "\n" << endl;  

return 0; 
}  

void Retirement::estimateDriver() {

// Declaration of variables, along with Retirement object to call estimateEarnings(), and an input char
double age, retirementAge, currentSavings, monthlyPayment, annualReturn; 
Retirement calc; 
char estimate = 'y'; // Initially set to "confirm" entering the while loop

while (estimate == 'Y' || estimate == 'y') { // Will continue iterating body until input variable is changed

cout << "Estimate Savings at Retirement" << "\n";
cout << "Disclaimer: This is only a rough estimate!" << "\n" << endl;

cout << "\t" << "Enter your current age in years: ";
cin >> age; 
while (age <= 0) {
    cout << "\t" << "Age cannot be 0 or less" << "\n";
    cout << "\t" << "Re-enter age in years: "; 
    cin >> age; 
}
cout << "\t" << "Enter your target retirement age: "; 
cin >> retirementAge; 
while (retirementAge <= 0) {
    cout << "\t" << "Retirement age cannot be 0 or less" << "\n";
    cout << "\t" << "Re-enter retirement age in years: "; 
    cin >> retirementAge; 
}
cout << "\t" << "How much have you saved towards retirement?: $"; 
cin >> currentSavings; 
while (currentSavings <= 0) {
    cout << "\t" << "Savings cannot be less than 0" << "\n";
    cout << "\t" << "Re-enter your retirement savings: "; 
    cin >> currentSavings; 
}
cout << "\t" << "Enter your monthly contribution to retirement: $"; 
cin >> monthlyPayment; 
while (monthlyPayment <= 0) {
    cout << "\t" << "Contributions cannot be 0 or less" << "\n";
    cout << "\t" << "Re-enter your contribution: "; 
    cin >> monthlyPayment; 
}
cout << "\t" << "Enter the estimate annual return on investment (in percent): ";
cin >> annualReturn; 
while (annualReturn <= 0) {
    cout << "Annual return cannot be 0 or less" << "\n";
    cout << "Re-enter your expected return: "; 
    cin >> annualReturn; 
}

cout << "." << "\n";
cout << "." << "\n"; 
cout << "..calculating" << "\n" << endl;

// Calls estimateEarnings() using Retirement class object calc with inputted arguments
calc.estimateEarnings(age, retirementAge, currentSavings, monthlyPayment, annualReturn); 

cout << "Calculate another estimate? (y/n): ";
cin >> estimate; // Allows editing of input char to leave or remain in the while loop

while (!(estimate == 'y' || estimate == 'Y' || estimate == 'n' || estimate == 'N')) {
    cout << "Calculate another estimate? (y/n): ";
    cin >> estimate; // Char input validation
}
}

}


