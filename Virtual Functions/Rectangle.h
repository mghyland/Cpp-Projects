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
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include <fstream>
#include "LblShape.h"

namespace sdds {

   class Rectangle : public LblShape{
      int m_width;
      int m_height;
   public:
      Rectangle();
      Rectangle(const char* label, int width, int height);
      void getSpecs(std::istream& istr = std::cin);
      void draw(std::ostream& ostr = std::cout)const;
   };


}


#endif

