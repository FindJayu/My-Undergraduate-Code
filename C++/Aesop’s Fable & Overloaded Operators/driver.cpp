// Jack Carson
// CPSC 1070
// Project 2
// 10 October 2021

#include <bits/stdc++.h>
#include "WorkPay.h"
#include "Simulation.h"
using namespace std;

int main() {
    /* The first section of this driver will demonstrate
    the use of the WorkPay class by creating objects of the class, 
    storing and printing data with the objects created, 
    using the retrieveHours() and retrieveDays() functions
    on these objects, and demonstrating the six overloaded operators
    that were created in this class
    */
    WorkPay a(10), b(-20), c(30), d(40); 

    a.storeData(10);
    b.storeData(-20);
    
    a.printData();
    b.printData();  

    a++; 
    b--; 
    ++c;
    --d; 

    cout << '\n';
    a.retrieveHours();
    b.retrieveDays();
    c.retrieveHours();
    d.retrieveDays();

    WorkPay i = a + a + b;
    WorkPay j = c - d; 

    cout << '\n';
    i.retrieveHours();
    j.retrieveDays();
    cout << '\n';

    /* The second portion of this driver.cpp calls the 
    runOneGame() function in class Simulation using an 
    instance of a Simulation object call
    */
    Simulation call;
    call.runOneGame();
}
