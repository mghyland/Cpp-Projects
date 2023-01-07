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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Utils.h"
#include "Vehicle.h"

using namespace std;
namespace sdds {



   void Parking::setEmpty() { // set Parking to empty

      m_filename = nullptr;
      m_mainMenu = nullptr;
      m_vehicleMenu = nullptr;

   }

   bool Parking::isEmpty() { // check if filename is null or empty

      return m_filename == nullptr || m_filename[0] == '\0';

   }

   void Parking::parkingStatus() { // display the current status of parking

      cout << "****** Valet Parking ******" << endl;
      cout << "*****  Available spots: ";
      cout.width(4);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << m_numSpots - m_numParked;
      cout.unsetf(ios::left);
      cout << " *****" << endl;

   }

   void Parking::parkVehicle() { // display submenu if user chooses Park Vehicle 

      if (m_numParked == m_numSpots) {

         cout << "Parking is full";

      }
      else {

         int vehOption = this->m_vehicleMenu.run(); // call run function to display items and take user input

         if (vehOption == 1) {

            Car* tempCar = new Car;

            tempCar->setCsv(false);

            tempCar->read();
            cout << endl;

            int flag = 0;
            for (int i = 0; i < maxSpots && flag == 0; i++) {

               if (m_parkedVehicles[i] == nullptr) {

                  m_parkedVehicles[i] = tempCar;
                  m_parkedVehicles[i]->setParkingSpot(i + 1);

                  cout << "Parking Ticket" << endl;
                  m_parkedVehicles[i]->write();
                  m_numParked++;
                  flag = 1;

                  cout << endl;
                  ut.enterToContinue();

               }

            }

         }
         else if (vehOption == 2) {

            Motorcycle* tempMtrcyc = new Motorcycle;

            tempMtrcyc->setCsv(false);

            tempMtrcyc->read();
            cout << endl;

            int flag = 0;
            for (int j = 0; j < maxSpots && flag == 0; j++) {

               if (m_parkedVehicles[j] == nullptr) {

                  m_parkedVehicles[j] = tempMtrcyc;
                  m_parkedVehicles[j]->setParkingSpot(j + 1);

                  cout << "Parking Ticket" << endl;
                  m_parkedVehicles[j]->write();
                  m_numParked++;
                  flag = 1;

                  /*delete tempMtrcyc;*/

                  cout << endl;
                  ut.enterToContinue();

               }

            }

         }
         else {

            cout << "Parking cancelled" << endl;

         }

      }
  
   }
     
   void Parking::returnVehicle() { // if user chooses Return Vehicle

      char tempPlate[8];
      int flag = 0;

      cout << "Return Vehicle" << endl;

      cout << "Enter License Plate Number: ";

      cin >> tempPlate;
      cin.ignore();

      cout << endl;

      if (ut.strlen(tempPlate) < 1 || ut.strlen(tempPlate) > 8) {

         while (flag == 0) {

            cout << "Invalid License Plate, try again: ";
            cin >> tempPlate;

            if (ut.strlen(tempPlate) < 1 || ut.strlen(tempPlate) > 8) {

               flag = 0;

            }
            else {

               for (int i = 0; i < ut.strlen(tempPlate); i++) {

                  tempPlate[i] = toupper(tempPlate[i]);

               }

               flag = 1;

            }

         }

      }
      else {

         for (int i = 0; i < ut.strlen(tempPlate); i++) {

            tempPlate[i] = toupper(tempPlate[i]);

         }

      }

      flag = 0;
      for (int i = 0; i < maxSpots && flag == 0; i++) {

         if (m_parkedVehicles[i] != nullptr) {

            if (*m_parkedVehicles[i] == tempPlate) {

               cout << "Returning:" << endl;

               m_parkedVehicles[i]->setCsv(false);
               m_parkedVehicles[i]->write();
               cout << endl;
               flag = 1;

               delete m_parkedVehicles[i];
               m_parkedVehicles[i] = nullptr;
               m_numParked--;

               ut.enterToContinue();

            }

         }
         else if (i == maxSpots - 1 && flag == 0) {

            cout << "License plate " << tempPlate << " Not found" << endl << endl;

            ut.enterToContinue();

         }

      }

   }

   void Parking::listVehicle() { // if user chooses List Parked Vehicles

      cout << "*** List of parked vehicles ***" << endl;

      for (int i = 0; i < maxSpots; i++) {

         if (m_parkedVehicles[i] != nullptr) {

            m_parkedVehicles[i]->setCsv(false);
            m_parkedVehicles[i]->write();
            cout << "-------------------------------" << endl;

         }

      }
      
      ut.enterToContinue();

   }

   void Parking::findVehicle() { // if user chooses Find Vehicle

      char tempPlate[8];
      int flag = 0;

      cout << "Vehicle Search" << endl;

      cout << "Enter License Plate Number: ";

      cin >> tempPlate;
      cin.ignore();
      cout << endl;

      if (ut.strlen(tempPlate) < 1 || ut.strlen(tempPlate) > 8) {

         while (flag == 0) {

            cout << "Invalid License Plate, try again: ";
            cin >> tempPlate;

            if (ut.strlen(tempPlate) < 1 || ut.strlen(tempPlate) > 8) {

               flag = 0;

            }
            else {

               for (int i = 0; i < ut.strlen(tempPlate); i++) {

                  tempPlate[i] = toupper(tempPlate[i]);

               }

               flag = 1;

            }

         }

      }
      else {

         for (int i = 0; i < ut.strlen(tempPlate); i++) {

            tempPlate[i] = toupper(tempPlate[i]);

         }

      }

      flag = 0;
      for (int i = 0; i < maxSpots && flag == 0; i++) {

         if (m_parkedVehicles[i] != nullptr) {

            if (*m_parkedVehicles[i] == tempPlate) {

               cout << "Vehicle found:" << endl;

               m_parkedVehicles[i]->setCsv(false);
               m_parkedVehicles[i]->write();
               cout << endl;
               flag = 1;

               ut.enterToContinue();

            }

         }
         else if (i == maxSpots - 1 && flag == 0) {

            cout << "License plate " << tempPlate << " Not found" << endl << endl;

            ut.enterToContinue();

         }

      }

   }

   bool Parking::closeParking() { // if user chooses Close Parking

      char close; // char to take user input option
      bool valid = false; // bool to return valid option
      int flag = 0; // flag to exit loop

      if (m_parkedVehicles == nullptr) {

         cout << "Close Parking" << endl << endl;
         valid = true;

      }
      else {

         // display warning message and confirm user wants to Close Parking
         cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
         cout << "Are you sure? (Y)es/(N)o: ";

         while (flag == 0) { // while flag is equal 0

            cin >> close; // take user input
            cin.ignore();

            if (close == 'y' || close == 'Y') { // if Yes

               cout << "Closing Parking" << endl << endl; // display Ending application 
               flag = 1; // set flag equal to 1 to exit loop
               valid = true; // set valid to true

               for (int i = 0; i < maxSpots; i++) {

                  if (m_parkedVehicles[i] != nullptr) {

                     cout << "Towing request" << endl;
                     cout << "*********************" << endl;

                     m_parkedVehicles[i]->setCsv(false);
                     m_parkedVehicles[i]->write();
                     if (i < m_numParked) {
                        cout << endl;
                     }

                     delete m_parkedVehicles[i];
                     m_parkedVehicles[i] = nullptr;

                  }

               }

            }
            else if (close == 'n' || close == 'N') { // if No

               valid = false; // set valid to false
               flag = 1; // set flag equal to 1 to exit loop

            }
            else { // if invalid entry, display error and ask new input

               cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

            }

         }

      }

      
      
      return valid;
   }

   bool Parking::exitApp() { // if user chooses Exit Parking

      char exit; // char to take user input option
      bool valid = false; // bool to return valid option
      int flag = 0; // flag to exit loop

      // display warning message and comfirm user wants to Exit Parking
      cout << "This will terminate the program!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";

      while (flag == 0) { // while flag is equal to 0

         cin >> exit; // take user input

         if (exit == 'y' || exit == 'Y') { // if Yes

            cout << "Exiting program!" << endl; // display Exiting application
            //saveData(); // call saveData function

            flag = 1; // set flag equal to 1 to exit loop
            valid = true; // set valid to true

         }
         else if (exit == 'n' || exit == 'N') { // if No

            valid = false; // set valid equal to false
            flag = 1; // set flag equal to 1 to exit loop

         }
         else { // if invalid entry, display error and ask new input

            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

         }

      }

      return valid;
   }

   void Parking::saveData() { 

      if (!isEmpty()) {

         ofstream file;

         file.open(m_filename);

         if (file.is_open()) {

            for (int i = 0; i < maxSpots; i++) {

               if (m_parkedVehicles[i] != nullptr) {

                  m_parkedVehicles[i]->setCsv(true);
                  file << *m_parkedVehicles[i];

               }

            }

         }

         file.close();

      }

   }

   bool Parking::loadData() { // load the data from the data file

      bool load = false; // bool to return if data was loaded

      if (!isEmpty()) { // if the object is NOT empty, load the data

         ifstream file;

         file.open(m_filename, ios::in);

         if (file.is_open()) {

            char ch;

            for (int i = 0; i < m_numSpots; i++) {

               file.get(ch);
               file.ignore();

               if (file) {

                  if (ch == 'M') {

                     Motorcycle* mtrcyc = new Motorcycle;

                     mtrcyc->setCsv(true);

                     if (mtrcyc->read(file)) {

                        m_parkedVehicles[mtrcyc->getParkingSpot() - 1] = mtrcyc;
                        m_numParked++;
                        load = true;

                     }
                     else {

                        load = false;
                        delete mtrcyc;

                     }

                  }
                  else if (ch == 'C') {

                     Car* car = new Car;

                     car->setCsv(true);

                     if (car->read(file)) {

                        m_parkedVehicles[car->getParkingSpot() - 1] = car;
                        m_numParked++;
                        load = true;

                     }
                     else {

                        load = false;
                        delete car;

                     }

                  }
                  else {

                     load = false;

                  }

               }
               else {

                  load = true;

               }

            }

            file.close();

         }
         else {

            load = true;

         }

         
      }

      return load;
   }

   // one-argument Parking constructor that initializes the main menu and vehicle menu names also
   Parking::Parking(const char* filename, int numSpots) : m_mainMenu("Parking Menu, select an action:"),
   m_vehicleMenu("Select type of the vehicle:", 1) {

      m_numParked = 0;

      if (numSpots > 9 && numSpots <= maxSpots) {

         m_numSpots = numSpots;

      }
      else {

         setEmpty();

      }

      for (int i = 0; i < maxSpots; i++) {

         m_parkedVehicles[i] = nullptr;

      }

      if (filename != nullptr && filename[0] != '\0') { // checks if filename is valid

         int length = strlen(filename); // if valid, get length of filename for dynamic allocation

         m_filename = new char[length + 1]; // create new filename with new length
         strcpy(m_filename, filename); // copy new filename

      }
           
      if (loadData()) { // if the data was loaded, add the menu items with Menu::add function
         
         // Main menu items
         m_mainMenu.add("Park Vehicle");
         m_mainMenu.add("Return Vehicle");
         m_mainMenu.add("List Parked Vehicles");
         m_mainMenu.add("Find Vehicle");
         m_mainMenu.add("Close Parking (End of day)");
         m_mainMenu.add("Exit Program");

         // Vehicle submenu items
         m_vehicleMenu.add("Car");
         m_vehicleMenu.add("Motorcycle");
         m_vehicleMenu.add("Cancel");

      }
      else { // if filename is invalid, display error message and set to empty
         
         cout << "Error in data file" << endl;
         setEmpty();

      }
      
   }

   Parking::~Parking() { // destructor that deletes dynamically allocated filename

      saveData();

      for (int i = 0; i < maxSpots; i++) {

         delete m_parkedVehicles[i];
         m_parkedVehicles[i] = nullptr;

      }

      delete[] m_filename;

   }

   int Parking::run() { // runs the Parking application

      int valid = 1;
      int flag = 0;

      if (!isEmpty()) { // if object is NOT empty

         while (flag == 0) { // while flag is equal to 0

            parkingStatus(); // call Parking Status

            // get user option from calling Menu::run function with mainMenu
            int option = this->m_mainMenu.run();

            switch (option) { // call function based on user option
            case 1:

               parkVehicle(); // Park Vehicle
               
               break;

            case 2:

               returnVehicle(); // Return Vehicle
               
               break;

            case 3:

               listVehicle(); // List Parked Vehicles
               
               break;

            case 4:

               findVehicle(); // Find Vehicle
               
               break;

            case 5:

               if (closeParking()) { // Close Parking and remove vehicles

                  flag = 1;
                  valid = 0;

               }
               break;

            case 6:

               if (exitApp()) { // Exit Parking and save parked vehicles list

                  flag = 1;
                  valid = 0;

               }

            }

         }
 
      }

      return valid;
   }

}
