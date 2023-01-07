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
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds {
	
	class Dumper : public VehicleBasic {

		double m_maxKilos;
		double m_currentKilos;
		void setEmpty();
	public:
		Dumper();
		Dumper(const char* plate, int year, float capacity, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr = std::cin);

	};
	std::ostream& operator<<(std::ostream& ostr, const Dumper& D);
	std::istream& operator>>(std::istream& istr, Dumper& D);
		
}
#endif

