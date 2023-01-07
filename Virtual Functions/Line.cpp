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
#include <string>
#include "Line.h"
#include "Utils.h"

using namespace std;
namespace sdds {

   Line::Line() {

      m_length = 0;

   }

   Line::Line(const char* cstr, int length) :LblShape(cstr) {

      m_length = length;

   }

   void Line::getSpecs(std::istream& istr) {

      LblShape::getSpecs(istr);

      m_length = ut.getint(nullptr, istr);

   }

   void Line::draw(std::ostream& ostr) const {

      if (m_length > 0 && label() != nullptr) {

         cout.width(m_length);
         cout.fill('=');
         cout.setf(ios::left);
         cout << label();
         cout.unsetf(ios::left);

      }

   }


}