#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

   void CC::prnNumber(unsigned long long no) const {
      //cout << "THIS IS TEST NO 0:" << no << endl;
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      //cout << "THIS IS TEST NO 1:" << no << endl;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      //cout << "THIS IS TEST NO 2:" << no << endl;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      //cout << "THIS IS TEST NO 3:" << no << endl;
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
   // Public method to set the object to a safe empty state
   void CC::set() {
       //cout << "set name before nullptr" <<name << endl;
       for (int i = 0; i < 71; ++i) {
           name[i] = nullptr; // Reset each pointer to nullptr
       }
       //cout << "set name after nullptr:" << name << endl;
       ccv = {};
       //cout << "ccv: " << ccv;
       expMon = {};
       expYear = {};
       no = {};
       //cout << "no: " << no;
   }
   void CC::cleanUp() {
       freeMem(name[71]);
       //cout << "* name after freeMem: " << *&name[71] << endl;
       CC::set();
   }
   bool CC::isEmpty() const {
       if (name[71] == nullptr) {
           return true;
       }
       return false;
   }
   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short Mon, short Year) {
       cleanUp();
       if (validate(cc_name, cc_no, cvv, Mon, Year) == true) {
           //cout << "before alocpy name: " << cc_name << "||||";
           alocpy(name[71], cc_name);
           //cout << "after alocpy name: " << *&name[71] << "||||";
           ccv = cvv;
           expMon = Mon;
           expYear = Year;
           *no = cc_no;
           //prnNumber(cc_no);
           //prnNumber(no);
       }
   }
   void CC::display() const {
       if (isEmpty() == true) {
           cout << "Invalid Credit Card Record" << endl;
       }
       else {
           //cout << "*&name[71]: " << *&name[71] << endl;
           //cout << "*no: " << *no << endl;

           display(name[71], *no, expYear, expMon, ccv);
       }
   }
}