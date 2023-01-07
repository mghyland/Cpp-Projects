/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Milestone - Part 4

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ReadWritable.h"

using namespace std;
namespace sdds {



   ReadWritable::ReadWritable() {

      csvFlag = false;

   }

   ReadWritable::~ReadWritable() {
   }

   bool ReadWritable::isCsv() const {

      return csvFlag;
      
   }

   void ReadWritable::setCsv(bool value) {

      csvFlag = value;

   }


   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& RW) {

      RW.write(ostr);
      
      return ostr;

   }

   std::istream& operator>>(std::istream& istr, ReadWritable& RW) {

      RW.read(istr);
      
      return istr;

   }


}