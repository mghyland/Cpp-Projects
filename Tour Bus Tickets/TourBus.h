/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 4 - Part 2

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_TOURBUS_H
#define SDDS_TOURBUS_H
#include <iostream>
#include "TourTicket.h"

namespace sdds {

	class TourBus {
		int m_numPassengers{};
		TourTicket* m_passengerList;
		
	public:
		TourBus(int numPassengers);
		~TourBus();
		bool validTour()const;
		TourBus& board();
		void startTheTour()const;
	};

}

#endif