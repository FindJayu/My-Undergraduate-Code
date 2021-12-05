// Jack Carson
// CPSC 1071: 03
// The Carsonators
// 3 October 2021

#include "Register.h"
#include <bits/stdc++.h>
using namespace std;

void Register::setFileName(string t) {
    transaction = t;
} // Set inputted string to private undeclared data field of class Register

void Register::printFile() {
    cout << "Printing transaction ledger" << "\n"; 
    readFromFile();
} // Prints confirmation message and begins filling vectors using readFromFile()

string Register::getFileName() { 
    string input;
    
    while (input!="transactions.txt") { // Input validation using while loop
    cout << "\t";
    cout << "Please enter the filename: ";
    cin >> input; 
    cout << "\t" << "Opening the file <" << input << ">" << "\n";
    if (input == "transactions.txt") {
        break;
    }
    cout << "Error opening file. Please retry" << "\n";
    }
    setFileName(input); // Call setter method with user input
    return input;
}

bool Register::processTransaction() {
    char estimate = 'y'; // While loop input confirmation 
    while (estimate=='y'||estimate=='Y') {
    getFileName(); // Calls to auxiliary functions in the driver body
    printFile();

    cout << "Process another transaction register? (y/n): ";
    cin >> estimate;

    while (!(estimate == 'y' || estimate == 'Y' || estimate == 'n' || estimate == 'N')) {
        cout << "Process another transaction register? (y/n): ";
        cin >> estimate; // Char input validation to leave or remain in the driver function
}
}
    return true;
}

bool Register::readFromFile() {
    fstream file;
    string word, filename;
    filename = transaction;
    int counter = 0;
    // Construct variables and fstream object, prepare to read in transaction private data field

    vector<string> Dates; 
    vector<Transactions> Trans;
    vector<string> Location;
    vector<string> Charges;
    // Initialize vectors

    file.open(filename.c_str());
    // Split .txt file by whitespace onto different lines

    while (file >> word) { // Keep reading .txt file while more lines exist
        if (counter == 0) {
            Dates.push_back(word);
            counter++;
            continue;
        } // Begin filling vectors based on the line count
        if (counter == 1) {
            if (word == "RESTAURANT") {
                Trans.push_back(RESTAURANT);
            }
            if (word == "MERCHANDISE") {
                Trans.push_back(MERCHANDISE);
            }
            if (word == "UTILITY") {
                Trans.push_back(UTILITY);
            }
            if (word == "COFFEESHOP") {
                Trans.push_back(COFFEESHOP);
            }
            if (word == "AUTOMOTIVE") {
                Trans.push_back(AUTOMOTIVE);
            }
            if (word == "DEPOSIT") {
                Trans.push_back(DEPOSIT);
            }
            if (word == "OTHER") {
                Trans.push_back(OTHER);
            } 
            counter++;
            continue;
        }
        if (counter == 2) {
            Location.push_back(word);
            counter++;
            continue;
        }
        if (counter == 3) {
            Charges.push_back(word);
            counter = 0;
        } // Reset counter after 4 total inputs 
    }
    void printFile();
    for (int i = 0; i < Charges.size(); i++) {
        cout << " " << Dates[i] << " |"; 
        cout << setw(15) << right << Location[i] << " |";
        cout << setw(10) << right << Charges[i] << " |" << setw(20);
        printTransAct(Trans[i]); // Auxiliary function displaying enumerated types
        cout << "\n" << endl;
    } // For loop and Vector.size() operator with formatting is used to print the ledger
    return true;
}

void Register::printTransAct(Transactions Transact) {
    switch (Transact) { // Switch statement with enumerated argument for formatting
        case 0: cout << "Restaurant";
            break;
        case 1: cout << "Merchandise";
            break;
        case 2: cout << "Utility";
            break;
        case 3: cout << "Coffeeshop";
            break;
        case 4: cout << "Automotive";
            break;
        case 5: cout << "Deposit";
            break;
        case 6: cout << "Other";
            break;
        default: cout << "Error with Transaction";
    }
}

// Using any object . notation in this file results in ""Register.cpp:(.text+0x108): undefined reference to `Register::Register()'
// /usr/bin/ld: Register.o: in function `Register::processTransaction()':""

// Again, if you have any comments please let me know! I have no idea what is different in this instance



