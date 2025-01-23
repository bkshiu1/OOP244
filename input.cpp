//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 22-1-2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "input.h"
using namespace std;
namespace seneca {
   int getInt() {
      int num = 0;
      bool done = false;
      do {
         // extract an integer from the console and put it in num
         cin >> num;
         // if this action fails (the integer is unreadable)
         if (cin.fail()) {
            cout << "Bad integer entry, please try again:\n> ";
            // clear the failure status to activate cin again
            cin.clear();
         }
         else {
            done = true;
         }
         // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
         cin.ignore(1000, '\n');
      } while (!done);
      return num;
   }

   //STEP 1
   int getInt(int minVal, int maxVal) {
       int num = 0;
       bool done = false;
       do {
           cin >> num;

           if (cin.fail() || num < minVal || num > maxVal) {
                cout << "Invalid value, [" << minVal << "<" << num << "<" << maxVal << "]" << endl;
               // clear the failure status to activate cin again
               cin.clear();
           }
           else {
               done = true;
           }
           // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
           cin.ignore(1000, '\n');
       } while (!done);
       return num;
       }

   //STEP 2
   int getInt(int &number, int minVal, int maxVal) {
       int num = 0;
       bool done = false;
           cin >> num;

           if (cin.fail() || num < minVal || num > maxVal) {
               cout << "Bad integer entry, please try again:" << endl;
               // clear the failure status to activate cin again
               cin.clear();
           }
           else {
               number = num;
               done = true;
           }
           // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
           cin.ignore(1000, '\n');
       return done;
   }
}

