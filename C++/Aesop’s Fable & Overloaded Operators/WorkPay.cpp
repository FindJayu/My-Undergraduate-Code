// Jack Carson
// CPSC 1070
// Project 2
// 10 October 2021

#include <bits/stdc++.h>
#include "WorkPay.h"
using namespace std;

int main() {
    WorkPay a(8), b(12), c(16);

    a.retrieveHours(); 

    c.retrieveHours();

    WorkPay j = a + b; 

    j.retrieveHours();

}

/* printData function which uses a range-based for loop to 
display the value of "hours" stored by the calling object. 
This value is printed by implicitly accessing the array of the vector v
in which the integer value is stored. 
*/
void WorkPay::printData() {
    for (int n : v) {
        cout << n << ' ';
    }
    cout << '\n';
}

/* storeData() is called by an object of class WorkPay, and inputs the parameter int n 
into the private vector using "this". If the value passed is negative, then the value is
converted to 0 (negative hours cannot be worked).
*/
void WorkPay::storeData(int n) {  
    if (n < 0) {
        n = 0; 
    }
    this->v.push_back(n); 
}

/* retrieveDays() typecasts the data field hours of the calling object into 
type double, and converts into days by performing (hours/8.0). If the value of convert
is negative, then 0 is assigned to the double variable (negative days cannot be worked).
Using this error method, the subtraction and decrement operators which may cause the data field
hours of an object to become negative will instead remain positive. 
*/
double WorkPay::retrieveDays() {
    double convert = ((double)hours/8.0);
    if (convert < 0) {
        convert = 0; 
    }
    cout << "You have worked for " << convert << " days" << endl;
    return convert; 
}

/* Sister function to retrieveDays, and called by an object instance of the class. 
Does not perform (/8), and returns the value of the data field hours as a positive double. 
Essentially acts as the getter function within the class. 
*/
double WorkPay::retrieveHours() {
    double h = (double) hours; 
    if (h < 0) {
        h = 0; 
    }
    cout << "You have worked for " << h << " hours" << endl; 
    return h; 
}



