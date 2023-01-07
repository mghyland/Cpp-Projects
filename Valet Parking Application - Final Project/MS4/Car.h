/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Milestone - Part 4

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds {

   class Car : public Vehicle {
      bool m_carwash;
   public:
      Car();
      Car(const char* plate, const char* makeModel);
      ~Car();
      Car(const Car& car);
      Car& operator=(const Car& car);
      std::ostream& writeType(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };

}

#endif