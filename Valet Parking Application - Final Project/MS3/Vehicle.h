/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Milestone - Part 3

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"

namespace sdds {

   class Vehicle : public ReadWritable {
      char m_licensePlate[8];
      char* m_makeModel{};
      int m_parkingSpotNum;
      void setEmpty();
      bool isEmpty();
      void setMakeModel(const char* makeModel);
   protected:
      
   public:
      const char* getLicensePlate()const;
      const char* getMakeModel()const;
      Vehicle();
      Vehicle(const char* plate, const char* makeModel);
      ~Vehicle();
      Vehicle(const Vehicle& vehicle);
      Vehicle& operator=(const Vehicle& vehicle);
      int getParkingSpot()const;
      void setParkingSpot(int spotNum);
      std::ostream& write(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      virtual std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
      bool operator==(const char* plate)const;
      bool operator==(const Vehicle& vehicle)const;
   };
   
}

#endif