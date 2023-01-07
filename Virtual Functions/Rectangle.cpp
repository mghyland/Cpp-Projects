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
#include "Rectangle.h"
#include "Utils.h"

using namespace std;
namespace sdds {

   Rectangle::Rectangle() {

      m_width = 0;
      m_height = 0;

   }

   Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label) {

      if (height >= 3 || width >= (ut.strlen(label) + 2)) {

         m_height = height;
         m_width = width;

      }
      else {

         m_height = 0;
         m_width = 0;

      }

   }

   void Rectangle::getSpecs(std::istream& istr) {

      LblShape::getSpecs(istr);

      istr >> m_width;
      istr.ignore(1, ',');
      istr >> m_height;
      istr.ignore(1000, '\n');

   }

   void Rectangle::draw(std::ostream& ostr) const {

      if (m_height > 0 && m_width > 0) {

         cout << '+';
         cout.width(m_width - 1);
         cout.fill('-');
         cout << '+';

         cout << endl;

         cout << '|';
         cout.width(m_width - 2);
         cout.fill(' ');
         cout.setf(ios::left);
         cout << label();
         cout.unsetf(ios::left);
         cout << '|';

         cout << endl;

         for (int i = 0; i < (m_height - 3); i++) {

            cout << '|';
            cout.width(m_width - 1);
            cout.fill(' ');
            cout << '|';
            cout << endl;

         }

         cout << '+';
         cout.width(m_width - 1);
         cout.fill('-');
         cout << '+';

      }

   }

}

