/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Milestone - Part 2

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include "string.h"
#include <iostream>
#include "Parking.h"

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

   }

   void Parking::parkVehicle() { // display submenu if user chooses Park Vehicle 

      int vehOption = this->m_vehicleMenu.run(); // call run function to display items and take user input

      switch (vehOption) {
      case 1: // if user chooses Car

         cout << "---------------------------------" << endl;
         cout << "Parking Car" << endl;
         cout << "---------------------------------" << endl;
         break;

      case 2: // if user chooses Motorcycle

         cout << "---------------------------------" << endl;
         cout << "Parking Motorcycle" << endl;
         cout << "---------------------------------" << endl;
         break;

      case 3: // if user chooses Cancel

         cout << "---------------------------------" << endl;
         cout << "Cancelled parking" << endl;
         cout << "---------------------------------" << endl;
         break;

      }
       
   }
     
   void Parking::returnVehicle() { // if user chooses Return Vehicle

      cout << "---------------------------------" << endl;
      cout << "Returning Vehicle" << endl;
      cout << "---------------------------------" << endl;

   }

   void Parking::listVehicle() { // if user chooses List Parked Vehicles

      cout << "---------------------------------" << endl;
      cout << "Listing Parked Vehicles" << endl;
      cout << "---------------------------------" << endl;

   }

   void Parking::findVehicle() { // if user chooses Find Vehicle

      cout << "---------------------------------" << endl;
      cout << "Finding a Vehicle" << endl;
      cout << "---------------------------------" << endl;

   }

   bool Parking::closeParking() { // if user chooses Close Parking

      char close; // char to take user input option
      bool valid = false; // bool to return valid option
      int flag = 0; // flag to exit loop

      // display warning message and confirm user wants to Close Parking
      cout << "This will close the parking; All the vehicles will be removed!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";

      while (flag == 0) { // while flag is equal 0

         cin >> close; // take user input

         if (close == 'y' || close == 'Y') { // if Yes

            cout << "Ending application!" << endl; // display Ending application 
            flag = 1; // set flag equal to 1 to exit loop
            valid = true; // set valid to true

         }
         else if (close == 'n' || close == 'N') { // if No

            valid = false; // set valid to false
            flag = 1; // set flag equal to 1 to exit loop

         }
         else { // if invalid entry, display error and ask new input

            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

         }

      }
      
      return valid;
   }

   bool Parking::exitApp() { // if user chooses Exit Parking

      char exit; // char to take user input option
      bool valid = false; // bool to return valid option
      int flag = 0; // flag to exit loop

      // display warning message and comfirm user wants to Exit Parking
      cout << "This will terminate the application and save the data!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";

      while (flag == 0) { // while flag is equal to 0

         cin >> exit; // take user input

         if (exit == 'y' || exit == 'Y') { // if Yes

            cout << "Exiting application!" << endl; // display Exiting application
            saveData(); // call saveData function

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

   void Parking::saveData() { // display Saving Data to current filename

      cout << "---------------------------------" << endl;
      cout << "Saving data into " << m_filename << endl;
      cout << "---------------------------------" << endl;

   }

   bool Parking::loadData() { // load the data from the data file

      bool load = false; // bool to return if data was loaded

      if (!isEmpty()) { // if the object is NOT empty, load the data

         cout << "---------------------------------" << endl;
         cout << "loading data from " << m_filename << endl;
         cout << "---------------------------------" << endl;
         cout << endl;
         load = true; // set load equal to true

      }

      return load;
   }

   // one-argument Parking constructor that initializes the main menu and vehicle menu names also
   Parking::Parking(const char* filename) : m_mainMenu("Parking Menu, select an action:"),
   m_vehicleMenu("Select type of the vehicle:", 1) {

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
               cout << endl;
               break;

            case 2:

               returnVehicle(); // Return Vehicle
               cout << endl;
               break;

            case 3:

               listVehicle(); // List Parked Vehicles
               cout << endl;
               break;

            case 4:

               findVehicle(); // Find Vehicle
               cout << endl;
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
