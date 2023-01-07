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
#include "LblShape.h"
#include "Utils.h"


using namespace std;
namespace sdds {

   const char* LblShape::label() const {

      return m_label;

   }

   LblShape::LblShape() {

      m_label = nullptr;

   }

   LblShape::LblShape(const char* label) {

      if (label) {

         m_label = new char[ut.strlen(label) + 1];
         ut.strcpy(m_label, label);

      }

   }

   LblShape::~LblShape() {

      delete[] m_label;
      
   }

   void LblShape::getSpecs(std::istream& istr) {

      delete[] m_label;

      const char* cstr{};
      string temp;

      getline(istr, temp, ',');

      cstr = temp.c_str();

      m_label = new char[ut.strlen(cstr) + 1];

      ut.strcpy(m_label, cstr);

   }

}

