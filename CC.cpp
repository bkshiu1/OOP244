////Karl Shiu, 131531246, bkshiu1@myseneca.ca, 29th Jan 2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }
   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const{
       if (name == nullptr || strlen(name) < 2
           || cardNo < 4000000000000000ull || cardNo > 4099999999999999ull
           || expMon < 1 || expMon > 12
           || expYear < 24 || expYear > 32) {
           return false;
       }
       return true;
   }
   void CC::set() {
       //for (int i = 0; i < 71; ++i) {
       //    name[i] = nullptr; // Reset each pointer to nullptr
       //}

       //ccv = {};

       //expMon = {};
       //expYear = {};
       //no = {};

       m_name = nullptr;
       m_cvv= 0;
       m_expMon = 0;
       m_expYear = 0;
       m_no = 0;
   }
   void CC::cleanUp() {
       //freeMem(name[71]);
       //CC::set();

       freeMem(m_name);
       set();
   }
   bool CC::isEmpty() const {
       //if (name[71] == nullptr) {
       //    return true;
       //}
       //return false;

       return m_name == nullptr;
   }
   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short Mon, short Year) {
       cleanUp();
       //if (validate(cc_name, cc_no, cvv, Mon, Year) == true) {
       //    alocpy(name[71], cc_name);
       //    ccv = cvv;
       //    expMon = Mon;
       //    expYear = Year;
       //    *no = cc_no;
       //}
       if (validate(cc_name, cc_no, cvv, Mon, Year)) {
         alocpy(m_name, cc_name);
         m_cvv = cvv;
         m_expMon = Mon;
         m_expYear = Year;
         m_no = cc_no;
       }

   }
   void CC::display() const {
       if (isEmpty()) {
           cout << "Invalid Credit Card Record" << endl;
       }
       else {
           //cout << "*&name[71]: " << *&name[71] << endl;
           //cout << "*no: " << *no << endl;

           //display(name[71], *no, expYear, expMon, ccv);
           display (m_name, m_no, m_expYear, m_expMon, m_cvv);
       }
   }
}