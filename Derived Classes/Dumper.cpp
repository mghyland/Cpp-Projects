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
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds {
	
	
		
	Dumper::Dumper() { // no-argument constructor, sets to empty

		setEmpty();

	}

	Dumper::Dumper(const char* plate, int year, float capacity, const char* address) : VehicleBasic(plate, year) {
		// two-argument constructor that also calls VehicleBasic two-argument constructor

		setEmpty(); // sets to empty
		m_maxKilos = capacity; // sets capacity
		m_currentKilos = 0; // sets current cargo to 0
		this->NewAddress(address); // sets new address by calling NewAddress()

	}

	void Dumper::setEmpty() { // sets to empty

		m_maxKilos = 0; // sets max capacity to 0
		m_currentKilos = 0; // sets current cargo to 0

	}

	bool Dumper::loaddCargo(double cargo) { // checks whether there is space to add cargo, only adds if it can

		bool loaded = false; // set loaded to presume false

		if ((m_currentKilos + cargo) < m_maxKilos) { // if current cargo plus new cargo is less than max capacity

			m_currentKilos += cargo; // add cargo to current cargo
			loaded = true; // set loaded to true

		}
		

		return loaded;

	}

	bool Dumper::unloadCargo() { // sets current cargo equal to 0 if there is cargo to unload (greater than 0)

		bool unloaded = false; // set unloaded to presume false

		if (m_currentKilos > 0) { // if current cargo is greater than 0

			m_currentKilos = 0; // set current cargo to 0
			unloaded = true; // set unloaded to true

		}

		return unloaded;
	}

	std::ostream& Dumper::write(std::ostream& ostr) const { // write status of dumper vehicle

		VehicleBasic::write(ostr); // call VehicleBasic write to display year, plate, location

		ostr << " | " << m_currentKilos << "/" << m_maxKilos; // display current cargo and max capacity
		
		return ostr;

	}

	std::istream& Dumper::read(std::istream& istr) { // take input and set new values

		setEmpty(); // set to empty

		VehicleBasic::read(istr); // call VehicleBasic read to take year, plate, location

		cout << "Capacity: "; // input and set capacity
		istr >> m_maxKilos;
		cout << "Cargo: "; // input and set current cargo
		istr >> m_currentKilos;
		
		
		return istr;

	}
		
	std::ostream& operator<<(std::ostream& ostr, const Dumper& D) { // display status calling write function

		D.write();
		
		return ostr;

	}

	std::istream& operator>>(std::istream& istr, Dumper& D) { // read input calling read function

		D.read();
		
		return istr;

	}

}

