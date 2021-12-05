// Jack Carson
// CPSC 1071: 03
// The Carsonators
// 3 October 2021

#include "Loan.h"
#include <bits/stdc++.h>
using namespace std;

// Modified (Correct) version of the function used in lab 1, returns total loan payment + interest
int Loan::paymentMonths (double principal, double interestRate, double monthlyPayment) {

double func = (interestRate/1200);
double numerator = log(monthlyPayment) - log(monthlyPayment - (func * principal));
double numerator10 = log(monthlyPayment+10) - log((monthlyPayment+10) - (func * principal));
double denominator = log(func + 1);

double monthCount = ceil(numerator/denominator);
int monthDifference = monthCount - ceil(numerator10/denominator);
double years = monthCount/12;

double interestPaid = 0; 
double firstPrincipal = principal; 
for (int i = 0; i < monthCount; i++) {
    double interest = principal*func; 
    principal = principal + interest - monthlyPayment; 
    interestPaid += interest; 
} // Counter variable incremented for each month the loan is active for

cout << monthCount << " months "; 
cout << fixed << showpoint << setprecision(1) << "(" << years << " years) are needed to pay your loan off." << endl; 
cout << "\n";
cout << "Did you know if you paid an additional $10 per month, you would pay off your loan " << monthDifference << " months earlier?" << "\n" << endl;
cout << "The total interest paid is $" << fixed << showpoint << setprecision(2) << interestPaid << " and the total amount you'll pay is $" << (interestPaid+firstPrincipal) << endl;

return 0; 
}

// Inputs and validates variables required to calculate loan repayment (using :: notation for Loan class declaration)
void Loan::paymentDriver() {

Loan calc; // Creation of Loan object for calling Loan class methods using . notation
char estimate = 'y'; // Input char initially set to "confirm"
double principal, interestRate, monthlyPayment; 

while (estimate=='y'||estimate=='Y') {

cout << "Loan payment Calculator" << "\n" << endl;
cout << "Enter the principal amount: ";
cin >> principal; 
while (principal <= 0) {
    cout << "principal cannot be 0 or less" << "\n";
    cout << "Re-enter your principal: "; 
    cin >> principal; 
}
cout << "Enter the annual interest rate (in %): "; 
cin >> interestRate; 
while (interestRate <= 0) {
    cout << "Interest rate cannot be 0 or less" << "\n";
    cout << "Re-enter your interest rate: "; 
    cin >> interestRate; 
}
cout << "Enter the monthly payment: "; 
cin >> monthlyPayment; 
while (monthlyPayment <= 0) {
    cout << "Monthly payment cannot be 0 or less" << "\n";
    cout << "Re-enter your monthly payment: "; 
    cin >> monthlyPayment; 
}

cout << "\n" << "Calculating..." << endl;
cout << "\n";

// calls paymentMonths() using . notation and Loan object
calc.paymentMonths(principal, interestRate, monthlyPayment);

cout << "Calculate another loan payoff? (y/n): ";
cin >> estimate;

while (!(estimate == 'y' || estimate == 'Y' || estimate == 'n' || estimate == 'N')) {
    cout << "Calculate another loan payoff? (y/n): ";
    cin >> estimate; // Char input validation
}
}

}

