// Jack Carson
// CPSC 1070
// Project 2
// 10 October 2021

# ifndef WORKPAY_H
# define WORKPAY_H
#include <bits/stdc++.h>

class WorkPay {
    private:
        /* Initialization of the private data field hours, along with
        the integer vector v for data storage. 
        */
        int hours; 
        std::vector<int> v;
    public:
        /* Creation of Arg and No-Arg constructors, with an object created with
        no argument being assigned 0 to the data field hours using "this"
        */
        WorkPay() {
            this->hours = 0; 
        }
        WorkPay(int hrs) {
            this->hours = hrs;
        } 

        // Declaration of required functions, including addition of printData()
        void storeData(int);
        void printData(void);
        double retrieveDays(void);  
        double retrieveHours(void);
        
        /* Addition and subtraction overloaded operators. Both work by first taking in the address of the 
        calling object, and then creating a temporary object temp, which receives the operation of the two
        calling object(s) data fields into its' own, and then returns the result. 
        */
        WorkPay operator + (WorkPay const &obj) {
            WorkPay temp;
            temp.hours = hours + obj.hours;
            return temp;
        } 
        WorkPay operator - (WorkPay const &obj) {
            WorkPay temp;
            temp.hours = hours - obj.hours;
            return temp; 
        } 


        /* Post - Prefix increment operators respectively.
        The postfix operator simply adds 8 to the value stored at the address of the calling object
        and returns the value pointed at (hours) for the object. 
        The prefix operator then implicitly calls the overloaded postfix operator
        and uses a temporary object inc to point at the value of the calling object's hours. 
        The data field is then incremented and returned.  
        */
        WorkPay& operator ++ () {
            hours += 8; 
            return *this; 
        }
        WorkPay operator ++ (int) {
            WorkPay inc = *this; 
            ++*this;             
            return inc; 
        } 


        /* Post - Prefix decrement operators respectively. 
        Follow the same operations as the above increment operators, with 
        pointers, temporary objects, and memory addresses used to perform operations
        on the data fields of the calling objects. 
        */
        WorkPay& operator -- () {
            hours -= 8; 
            return *this;
        }
        WorkPay operator -- (int) {
            WorkPay dec = *this;
            --*this;
            return dec;
        } 
};

# endif
