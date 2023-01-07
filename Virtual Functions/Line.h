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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include <fstream>
#include "LblShape.h"

namespace sdds {

   class Line : public LblShape{
      int m_length;
   public:
      Line();
      Line(const char* label, int length);
      void getSpecs(std::istream& istr = std::cin);
      void draw(std::ostream& ostr = std::cout)const;
   };

}


#endif

