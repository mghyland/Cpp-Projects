/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 8

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
#include <fstream>

namespace sdds {

   class Shape {
   public:
      virtual void draw(std::ostream& ostr = std::cout)const = 0;
      virtual void getSpecs(std::istream& istr = std::cin) = 0;
      virtual ~Shape();
   };
   std::ostream& operator<<(std::ostream& ostr, const Shape& S);
   std::istream& operator>>(std::istream& istr, Shape& S);

}

#endif


