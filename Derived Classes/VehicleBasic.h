/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 7

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds {

   class VehicleBasic {

      char m_licensePlate[9];
      char m_location[64];
      int m_year;
      void setEmpty();
   public:
      VehicleBasic();
      VehicleBasic(const char* plate, int year);
      void NewAddress(const char* address);
      std::ostream& write(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);

   };
   std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& V);
   std::istream& operator>>(std::istream& istr, VehicleBasic& V);
}

#endif

