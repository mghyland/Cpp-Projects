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
#include "Car.h"
#include "Utils.h"

using namespace std;
namespace sdds {



   Car::Car() :Vehicle::Vehicle() {
      
      m_carwash = false;

   }

   Car::Car(const char* plate, const char* makeModel) :Vehicle::Vehicle(plate, makeModel) {

      m_carwash = false;

   }

   Car::~Car() {
   }

   Car::Car(const Car& car) {

      *this = car;

   }

   Car& Car::operator=(const Car& car) {
      
      m_carwash = car.m_carwash;

      Vehicle::operator=(car);

      return *this;

   }

   std::ostream& Car::writeType(std::ostream& ostr) const {
      
      if (isCsv()) {

         ostr << "C,";

      }
      else {

         ostr << "Vehicle type: Car" << endl;

      }

      return ostr;

   }

   std::istream& Car::read(std::istream& istr) {
      
      if (isCsv()) {

         Vehicle::read(istr);

         istr >> m_carwash;
         istr.ignore(1000, '\n');

      }
      else {

         string temp;

         cout << endl;
         cout << "Car information entry" << endl;

         Vehicle::read(istr);

         cout << "Carwash while parked? (Y)es/(N)o: ";

         cin >> temp;
         cin.ignore();

         while (temp != "Y" && temp != "y" && temp != "N" && temp != "n") {

            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

            cin >> temp;
            cin.ignore();

         }

         if (temp == "Y" || temp == "y") {

            m_carwash = true;

         }
         else {

            m_carwash = false;

         }
         
      }

      return istr;
   }

   std::ostream& Car::write(std::ostream& ostr) const {
      
      if (this->getMakeModel() != nullptr) {

         Vehicle::write(ostr);

         if (isCsv()) {

            ostr << m_carwash << endl;

         }
         else {

            if (m_carwash) {

               ostr << "With Carwash" << endl;

            }
            else {

               ostr << "Without Carwash" << endl;

            }

         }

      }
      else {

         ostr << "Invalid Car Object" << endl;

      }

      return ostr;
   }


}