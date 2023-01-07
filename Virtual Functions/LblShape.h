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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include <fstream>
#include <string>
#include "Shape.h"

namespace sdds {

   class LblShape : public Shape{
      char* m_label{};
   protected:
      const char* label()const;
   public:
      LblShape();
      LblShape(const char* label);
      ~LblShape();
      LblShape(const LblShape&) = delete;
      void operator=(LblShape&) = delete;
      void getSpecs(std::istream& istr = std::cin);
   };

}

#endif

