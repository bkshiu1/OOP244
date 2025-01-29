#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
   private:
       char* name[71]{nullptr};
       unsigned long long *no{};
       short ccv{};
       short expMon{};
       short expYear{};
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
       CC() : name(), no(0), ccv(0), expMon(0), expYear(0), numRead(0), row(0) {}//constructor
       void set();
       void cleanUp();
       bool isEmpty() const;
       void set(const char* cc_name,
           unsigned long long cc_no,
           short cvv,
           short expMon = 12,
           short expYear = 24);
       void display() const;

       ~CC() {//destructor
           cleanUp();
       }

   };
}
#endif // !SENECA_CC_H_


