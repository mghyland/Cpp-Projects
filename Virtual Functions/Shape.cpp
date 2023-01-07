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
#define _CRT_SECURE_NO_WARNINGS
#include "Shape.h"

using namespace std;
namespace sdds {

   std::ostream& operator<<(std::ostream& ostr, const Shape& S) {

      S.draw(ostr);
      
      return ostr;

   }

   std::istream& operator>>(std::istream& istr, Shape& S) {

      S.getSpecs(istr);
      
      return istr;

   }

   Shape::~Shape() {

   }


}