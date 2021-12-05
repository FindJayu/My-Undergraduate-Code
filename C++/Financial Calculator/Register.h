// Jack Carson
// CPSC 1071: 03
// The Carsonators
// 3 October 2021

#ifndef REGISTER_H
#define REGISTER_H
#include <string>

class Register {
public:
    enum Transactions {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER}; 
    Transactions Transact; // Declaration of Enum, Enum variable, and Functions

    std::string getFileName(); 
    void setFileName(std::string); 
    void printTransAct(Transactions); // Auxiliary function for Register display
    bool processTransaction(); 
    bool readFromFile(); 
    void printFile();
private:
    std::string transaction; 
};

# endif