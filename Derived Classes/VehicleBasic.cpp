/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 7

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;
namespace sdds {
	

	VehicleBasic::VehicleBasic() { // no-argument constructor, sets to empty

		setEmpty();

	}

	VehicleBasic::VehicleBasic(const char* plate, int year) { // two-argument constructor

		setEmpty(); // sets to empty
		strcpy(m_licensePlate, plate); // sets license plate
		m_year = year; // sets year

	}

	void VehicleBasic::setEmpty() { // sets to empty

		const char factory[] = "Factory"; // sets default address Factory

		m_licensePlate[0] = '\0'; // sets license plate equal to null
		strcpy(m_location, factory); // sets location to default Factory
		m_year = 0; // sets year to 0

	}

	void VehicleBasic::NewAddress(const char* address) { // changes address if different from current address

		if (strcmp(m_location, address)) { // if addresses are different, display as follows

			cout << "|"; // fill with spaces, width 8, align right
			cout.fill(' ');
			cout.width(8);
			cout.setf(ios::right);
			cout << m_licensePlate;
			cout.unsetf(ios::right);

			cout << "| |";

			cout.fill(' '); // fill with spaces, width 20, align right
			cout.width(20);
			cout.setf(ios::right);
			cout << m_location;
			cout.unsetf(ios::right);

			cout << " ---> ";

			cout.fill(' '); // fill with spaces, width 20, align left
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout.unsetf(ios::left);

			cout << "|" << endl;

			strcpy(m_location, address); // set current address to new address
						
		}
			

	}

	std::ostream& VehicleBasic::write(std::ostream& ostr) const { // display vehicle status (year, plate, location)

		ostr << "| " << m_year << " | " << m_licensePlate << " | " << m_location;
		
		return ostr;

	}

	std::istream& VehicleBasic::read(std::istream& istr) { // take input and set new values

		setEmpty();

		cout << "Built year: "; // input and set new year
		istr >> m_year;
		cout << "License plate: "; // input and set new plate
		istr >> m_licensePlate;
		cout << "Current location: "; // input and set new location
		istr >> m_location;

		return istr;

	}

	std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& V) { // display status calling write function

		V.write();
		
		return ostr;

	}

	std::istream& operator>>(std::istream& istr, VehicleBasic& V) { // read input calling read function

		V.read();
		
		return istr;

	}

}
