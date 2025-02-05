//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Karl Shiu, bkshiu1@myseneca.ca, 5/2/2025
#include <istream>
#include "cstr.h"  
#include "Canister.h"
using namespace std;
namespace seneca {

   const double PI = 3.14159265;
   

   bool Canister::isEmpty() const {
      return m_contentVolume < 0.00001;
   }

   bool Canister::usable() const
   {
      return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
   }

   void Canister::setToUnusable(){
      freeMem(m_contentName);
      m_diameter = m_height = -1.0;
   }

   double Canister::capacity() const {
      return PI * (m_height-0.267) * (m_diameter/2) * (m_diameter / 2);
   }

      bool Canister::hasSameContent(const Canister& C)const {
      return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
   }

   double Canister::volume() const {
      return m_contentVolume;
   }

   std::ostream& Canister::display() const {
      cout.setf(ios::fixed);
      cout.precision(1);
      cout.width(7);
      cout << capacity() << "cc (";
      cout.width(4);
      cout << m_height << "x";
      cout.width(4);
      cout << m_diameter << ") Canister";
      if (!usable()) {
         cout << " is  Unusable   recycle!";
      }
      else {
         cout << " of ";
         cout.width(7);
         cout << volume() << "cc   " << (m_contentName?m_contentName:"Sanetized and Empty");
      }
      return cout;
   }
   //eee
   Canister::Canister() : m_contentName(nullptr), m_diameter(10.0), m_height(13.0), m_contentVolume(0.0) {}

   // One-Argument Constructor
   Canister::Canister(const char* contentName) : Canister() {
       if (contentName != nullptr) {
           alocpy(m_contentName, contentName);
       }
   }

   // Three-Argument Constructor
   Canister::Canister(double height, double diameter, const char* contentName) : Canister() {
       if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
           m_height = height;
           m_diameter = diameter;
           if (contentName != nullptr) {
               alocpy(m_contentName, contentName);
           }
       }
       else {
           setToUnusable();
       }
   }

   // Destructor
   Canister::~Canister() {
       freeMem(m_contentName);
   }

   // Clear method
   Canister& Canister::clear() {
       freeMem(m_contentName);
       m_contentName = nullptr;
       m_contentVolume = 0.0;
       return *this;
   }

   // Set content method
   Canister& Canister::setContent(const char* contentName) {
       if (contentName != nullptr && usable()) {
           if (isEmpty() || m_contentName == nullptr) {
                alocpy(m_contentName, contentName);
           }
           else if (!hasSameContent(*this)) {
               setToUnusable();
           }
       }
       return *this;
   }

   // Pour method (by quantity)
   Canister& Canister::pour(double quantity) {
       if (usable()) {
           if (quantity > 0 && (m_contentVolume + quantity) < capacity()) {
               m_contentVolume += quantity;
           }
           else {
               setToUnusable();
           }
       }
       return *this;
   }

   // Pour method (from another Canister)
   Canister& Canister::pour(Canister& can) {
       if (usable()) {
           if (can.volume() > (capacity() - volume())) {
               double spaceAvailable = capacity() - volume();
               m_contentVolume += spaceAvailable;
               can.m_contentVolume -= spaceAvailable;
           }
           else {
               m_contentVolume += can.volume();
               can.m_contentVolume = 0.0;
           }
           setContent(can.m_contentName);
       }
       return *this;
   }
}
