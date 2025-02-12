//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Karl Shiu, bkshiu1@myseneca.ca, 11/2/2025
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;

   }
   // Type Conversion Operators
   Account::operator bool() const {
       return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
   }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }

   // Unary Operator
   bool Account::operator~() const {
       return m_number == 0;
   }

   // Assignment Operators
   Account& Account::operator=(int number) {
       if (m_number == 0 && number >= 10000 && number <= 99999) {
           m_number = number;
       }
       return *this;
   }

   Account& Account::operator=(Account& other) {
       if (this != &other && ~(*this) && bool(other)) {
           m_number = other.m_number;
           m_balance = other.m_balance;
           other.m_number = 0;
           other.m_balance = 0.0;
       }
       return *this;
   }

   // Binary Member Operators
   Account& Account::operator+=(double amount) {
       if (*this && amount > 0) {
           m_balance += amount;
       }
       return *this;
   }

   Account& Account::operator-=(double amount) {
       if (*this && amount > 0 && m_balance >= amount) {
           m_balance -= amount;
       }
       return *this;
   }

   Account& Account::operator<<(Account& other) {
       if (*this && other && this != &other) {
           m_balance += other.m_balance;
           other.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& other) {
       if (*this && other && this != &other) {
           other.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   // Overloading the Output Operator for Proper Printing
   std::ostream& operator<<(std::ostream& os, const Account& acc) {
       return acc.display();
   }

   // Friend Functions (Standalone Operators)
   double operator+(const Account& lhs, const Account& rhs) {
       return (lhs && rhs) ? lhs.m_balance + rhs.m_balance : 0.0;
   }

   double& operator+=(double& lhs, const Account& rhs) {
       if (rhs) {
           lhs += rhs.m_balance;
       }
       return lhs;
   }


 
}