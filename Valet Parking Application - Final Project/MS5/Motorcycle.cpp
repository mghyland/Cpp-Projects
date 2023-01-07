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
#include "Motorcycle.h"

using namespace std;
namespace sdds {



   Motorcycle::Motorcycle() :Vehicle::Vehicle() {

      m_sidecar = false;

   }

   Motorcycle::Motorcycle(const char* plate, const char* makeModel) :Vehicle::Vehicle(plate, makeModel) {

      m_sidecar = false;

   }

   Motorcycle::~Motorcycle() {
   }

   Motorcycle::Motorcycle(const Motorcycle& mtrcyc) {

      *this = mtrcyc;

   }

   Motorcycle& Motorcycle::operator=(const Motorcycle& mtrcyc) {
      
      m_sidecar = mtrcyc.m_sidecar;

      Vehicle::operator=(mtrcyc);

      return *this;

   }

   std::ostream& Motorcycle::writeType(std::ostream& ostr) const {
      
      if (isCsv()) {

         ostr << "M,";

      }
      else {

         ostr << "Vehicle type: Motorcycle" << endl;

      }

      return ostr;

   }

   std::istream& Motorcycle::read(std::istream& istr) {
      
      if (isCsv()) {

         Vehicle::read(istr);

         istr >> m_sidecar;
         istr.ignore(1000, '\n');

      }
      else {

         string temp;

         cout << endl;
         cout << "Motorcycle information entry" << endl;

         Vehicle::read(istr);

         cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

         cin >> temp;
         cin.ignore();

         while (temp != "Y" && temp != "y" && temp != "N" && temp != "n") {

            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

            cin >> temp;
            cin.ignore();

         }

         if (temp == "Y" || temp == "y") {

            m_sidecar = true;

         }
         else {

            m_sidecar = false;

         }

      }

      return istr;

   }

   std::ostream& Motorcycle::write(std::ostream& ostr) const {
      
      if (this->getMakeModel() != nullptr) {

         Vehicle::write(ostr);

         if (isCsv()) {

            ostr << m_sidecar << endl;

         }
         else {

            if (m_sidecar) {

               ostr << "With Sidecar" << endl;

            }

         }

      }
      else {

         ostr << "Invalid Motorcycle Object" << endl;

      }

      return ostr;

   }


}