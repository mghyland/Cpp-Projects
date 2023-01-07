/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Milestone - Part 5

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include <iostream>
#include "Menu.h"
#include "Vehicle.h"

namespace sdds {

   const int maxSpots = 100;

   class Parking {
      char* m_filename{};
      int m_numSpots;
      Vehicle* m_parkedVehicles[maxSpots]{};
      int m_numParked;
      Menu m_mainMenu;
      Menu m_vehicleMenu;
      void setEmpty();
      bool isEmpty();
      void parkingStatus();
      void parkVehicle();
      void returnVehicle();
      void listVehicle();
      void findVehicle();
      bool closeParking();
      bool exitApp();
      bool loadData();
      void saveData();
   public:
      Parking(const char* filename, int numSpots);
      ~Parking();
      // no copying or assignment allowed
      Parking(const Parking&) = delete;
      void operator=(Parking&) = delete;
      int run();
   };

}

#endif