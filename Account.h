//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Karl Shiu, bkshiu1@myseneca.ca, 11/2/2025
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // Type Conversion Operators
      operator bool() const;
      operator int() const;
      operator double() const;

      // Unary Operator
      bool operator~() const;

      // Assignment Operators
      Account& operator=(int number);
      Account& operator=(Account& other);

      // Binary Member Operators
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& other);
      Account& operator>>(Account& other);

      // Friend Functions (Standalone Operators)
      friend std::ostream& operator<<(std::ostream& os, const Account& acc);
      friend double operator+(const Account& lhs, const Account& rhs);
      friend double& operator+=(double& lhs, const Account& rhs);
  
   };


}
#endif // SENECA_ACCOUNT_H_