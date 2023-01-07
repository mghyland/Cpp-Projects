/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 5 - Part 1

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      Apartment(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator~()const;
      Apartment& operator=(int aprtNum);
      Apartment& operator=(Apartment& one);
      Apartment& operator+=(double balance);
      Apartment& operator-=(double balance);
      Apartment& operator<<(Apartment& balance);
      Apartment& operator>>(Apartment& balance);
   };

   double operator+(const Apartment& one, const Apartment& two);
   double operator+=(double& balance, const Apartment& one);
}

#endif // SDDS_APARTMENT_H_