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
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
#include "Vehicle.h"

namespace sdds {

   class Motorcycle : public Vehicle {
      bool m_sidecar;
   public:
      Motorcycle();
      Motorcycle(const char* plate, const char* makeModel);
      ~Motorcycle();
      Motorcycle(const Motorcycle& mtrcyc);
      Motorcycle& operator=(const Motorcycle& mtrcyc);
      std::ostream& writeType(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };

}

#endif