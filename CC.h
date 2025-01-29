//Carl Shiu, 127456192, bkshiu@myseneca.ca, 29th Jan 2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
   private:
       char* m_name{};
       short m_cvv{};
       short m_expMon{};
       short m_expYear{};
       unsigned long long m_no{};
       int numRead{};
       unsigned int row{};
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      void prnNumber(unsigned long long no) const;
      bool validate(const char* name,
          unsigned long long cardNo,
          short cvv,
          short expMon,
          short expYear)const;

   public:

       void set();
       void cleanUp();
       bool isEmpty() const;
       void set(const char* cc_name,
           unsigned long long cc_no,
           short cvv,
           short expMon = 12,
           short expYear = 24);
       void display() const;


   };
}
#endif // !SENECA_CC_H_


