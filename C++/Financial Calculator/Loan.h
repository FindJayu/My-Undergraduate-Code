// Jack Carson
// CPSC 1071: 03
// The Carsonators
// 3 October 2021

#ifndef LOAN_H
#define LOAN_H

class Loan {
public:
  void paymentDriver();
private:
  int paymentMonths(double, double, double);
}; // Declaration of Loan functions with paymentMonths encapsulated

#endif
