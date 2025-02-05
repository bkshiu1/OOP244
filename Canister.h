//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Karl Shiu, bkshiu1@myseneca.ca, 5/2/2025
#ifndef SENECA_CANISTER_H
#define SENECA_CANISTER_H
#include <iostream>
namespace seneca {
   class Canister {
      char* m_contentName;
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs

      /// <summary>
      /// renders the canister unusable by freeing the conent name memory and setting diamieter and height to -1
      /// </summary>
      void setToUnusable();
      /// <summary>
      /// Returns true if canister volume is below 0.00001
      /// </summary>
      /// <returns>true if the canister is emtpy</returns>
      bool isEmpty()const;
      /// <summary>
      /// Returns true if height and diameters are within accepable values
      /// </summary>
      /// <returns>true if canister is usable</returns>
      bool usable()const;
      /// <summary>
      /// Returns true if the conent name of the two canisters are the same
      /// </summary>
      /// <param name="C">const Canister& to compare to</param>
      /// <returns>True if the name is the same</returns>
      bool hasSameContent(const Canister& C)const;
      /// <summary>
      /// returns the capacity of the canister
      /// </summary>
      /// <returns>Capacity of Canister</returns>
      double capacity()const;
      /// <summary>
      /// Returns the content volume. Always less than capacity
      /// </summary>
      /// <returns>Conent Volume</returns>
      double volume()const;
   public:
       // No-Argument Constructor (Default)
       Canister();
       // One-Argument Constructor
       Canister(const char* contentName);
       // Three-Argument Constructor
       Canister(double height, double diameter, const char* contentName = nullptr);

       // Destructor
       ~Canister();

       // Clear method
       Canister& clear();
       // Set content method
       Canister& setContent(const char* contentName);
       // Pour method (by quantity)
       Canister& pour(double quantity);
       // Pour method (from another Canister)
       Canister& pour(Canister& can);
      std::ostream& display()const;
   };
}

#endif // !SENECA_BOX_H
