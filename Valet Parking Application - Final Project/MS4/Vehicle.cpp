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
#include <string>
#include <string.h>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;
namespace sdds {



   const char* Vehicle::getLicensePlate() const {

      return m_licensePlate;
      
   }

   const char* Vehicle::getMakeModel() const {

      return m_makeModel;
      
   }

   Vehicle::Vehicle() {

      m_licensePlate[0] = '\0';
      m_makeModel = nullptr;
      m_parkingSpotNum = 0;

   }

   Vehicle::Vehicle(const char* plate, const char* makeModel) {

      setEmpty();

      if (plate != nullptr && makeModel != nullptr && strlen(plate) > 0 &&
         strlen(plate) < 8 && strlen(makeModel) > 1 && strlen(makeModel) < 60) {

         strcpy(m_licensePlate, plate);

         delete[] m_makeModel;

         m_makeModel = new char[strlen(makeModel) + 1];
         strcpy(m_makeModel, makeModel);

      }
      else {

         setEmpty();

      }

   }

   Vehicle::~Vehicle() {

      delete[] m_makeModel;

   }

   Vehicle::Vehicle(const Vehicle& vehicle) {

      setEmpty(); 
      
      *this = vehicle;

   }

   Vehicle& Vehicle::operator=(const Vehicle& vehicle) {

      // Check for self assignment first, if not the same then 
      // deallocate, set empty, set static variables
      // then check if source is empty, if not then allocate and copy

      delete[] m_makeModel;

      setEmpty();

      setCsv(vehicle.isCsv());

      m_parkingSpotNum = vehicle.m_parkingSpotNum;
      strcpy(m_licensePlate, vehicle.m_licensePlate);

      if (vehicle.m_makeModel != nullptr) {

         m_makeModel = new char[strlen(vehicle.m_makeModel) + 1];

         strcpy(m_makeModel, vehicle.m_makeModel);

      }

      /*delete[] m_makeModel;

      setEmpty();

      m_makeModel = vehicle.m_makeModel; 

      delete[] vehicle.m_makeModel;

      strcpy(m_licensePlate, vehicle.m_licensePlate);*/

      return *this; 

   }

   int Vehicle::getParkingSpot() const {

      return m_parkingSpotNum;
      
   }

   void Vehicle::setEmpty() {

      /*if (!isEmpty()) {

         delete[] m_makeModel;

      }*/

      m_licensePlate[0] = '\0';
      m_makeModel = nullptr;
      m_parkingSpotNum = 0;

   }

   bool Vehicle::isEmpty() {

      return m_makeModel == nullptr;
      
   }

   void Vehicle::setMakeModel(const char* makeModel) {

      

      if (makeModel != nullptr && strlen(makeModel) > 1) {

         delete[] m_makeModel;

         m_makeModel = new char[strlen(makeModel) + 1];
         strcpy(m_makeModel, makeModel);

      }
      else {

         setEmpty();

      }

   }

   void Vehicle::setParkingSpot(int spotNum) {

      if (spotNum >= 0) {

         m_parkingSpotNum = spotNum;

      }
      else {

         setEmpty();

      }

   }

   std::ostream& Vehicle::write(std::ostream& ostr)const {
      
      if (m_makeModel == nullptr) {

         cout << "Invalid Vehicle Object" << endl;

      }
      else {

         writeType(ostr);

         if (isCsv()) {

            cout << m_parkingSpotNum << "," << m_licensePlate << "," << m_makeModel << ",";

         }
         else {

            cout << "Parking Spot Number: ";
            if (m_parkingSpotNum > 0) {

               cout << m_parkingSpotNum << endl;

            }
            else {

               cout << "N/A" << endl;

            }

            cout << "License Plate: " << m_licensePlate << endl;

            cout << "Make and Model: " << m_makeModel << endl;

         }

      }

      return ostr;

   }

      std::istream& Vehicle::read(std::istream& istr) {

      if (isCsv()) {

         char tempMakeModel[60];

         cin >> m_parkingSpotNum;
         istr.ignore();
         istr.getline(m_licensePlate, 8 , ',');
         istr.getline(tempMakeModel, 60, ',');
;
         if (istr) {

            setMakeModel(tempMakeModel);

         }

         int length = ut.strlen(m_licensePlate);

         for (int i = 0; i < length; i++) {
            m_licensePlate[i] = toupper(m_licensePlate[i]);
         }

      }
      else {

         cout << "Enter License Plate Number: ";

         int flag = 0;
         do {

            istr.getline(m_licensePlate, 8, '\n');
            if (istr) {

               int length = ut.strlen(m_licensePlate);

               for (int i = 0; i < length; i++) {
                  m_licensePlate[i] = toupper(m_licensePlate[i]);
               }
               flag = 1;

            }
            else {

               cout << "Invalid License Plate, try again: ";
               istr.clear();
               istr.ignore(1000, '\n');

            }

         } while (flag == 0);

         istr.clear();
         
         cout << "Enter Make and Model: ";

         flag = 0;
         do {

            char tempMakeModel[60];

            istr.getline(tempMakeModel, 60, '\n');
            if (istr) {

               if (strlen(tempMakeModel) > 1) {

                  setMakeModel(tempMakeModel);
                  flag = 1;

               }
               else {

                  cout << "Invalid Make and model, try again: ";

               }
               

            }
            else {

               cout << "Invalid Make and model, try again: ";
               istr.clear();
               istr.ignore(1000, '\n');

            }

         } while (flag == 0);

      }
      
      return istr;

   }

   bool Vehicle::operator==(const char* plate) const {

      bool status = false;

      //status = !_stricmp(this->m_licensePlate, plate); // Visual Studio
      status = !strcasecmp(m_licensePlate, plate); // Matrix

      return status;
   }

   bool Vehicle::operator==(const Vehicle& vehicle) const {

      bool status = false;

      //status = !_stricmp(this->m_licensePlate, vehicle.m_licensePlate); // Visual Studio
      status = !strcasecmp(m_licensePlate, vehicle.m_licensePlate); // Matrix

      return status;
   }

   


}