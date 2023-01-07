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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TourTicket.h"
#include "TourBus.h"

using namespace std;

namespace sdds {

	bool TourBus::validTour()const { // checks whether the number of passengers is a valid amout

		bool success = true; // assume to be true

		if (this->m_numPassengers != 4 && this->m_numPassengers != 16 // bus size 4, 16 or 22
			&& this->m_numPassengers != 22) {

			success = false; // return false if not 4, 16 or 22

		}

		return success; 
	}

	TourBus& TourBus::board() { // assigns names and ticket numbers to passengers list

		char name[41];
		m_passengerList = new TourTicket[m_numPassengers]; // create new TourTicket

		

		cout << "Boarding " << m_numPassengers << " Passengers:" << endl;

		for (int i = 1; i <= m_numPassengers; i++) { // loop through and ask for each passengers name
			                                         // using i = 1 so that i can be used as list num

			cout << i << "/" << m_numPassengers << "- " << "Passenger Name: ";
			cin.getline(name, 41, '\n'); 
			m_passengerList[i - 1].issue(name); // take passenger name up to 40 chars and assign

		}

		return *this;
	}

	void TourBus::startTheTour()const {

		if (validTour()) { // check for valid tour bus

			if (m_numPassengers == 4) { // if private bus, display as follows

				cout << "Starting the tour...." << endl;
				cout << "Passenger List:" << endl;
				cout << "|";
				cout.width(4);
				cout.setf(ios::left);
				cout << "Row";
				cout << "| ";
				cout.unsetf(ios::left);
				cout.width(40);
				cout.setf(ios::left);
				cout << "Passenger Name" << " | " << "Num" << " |" << endl;
				cout.unsetf(ios::left);
				cout << "+----+------------------------------------------+-----+" << endl;

				for (int i = 0; i < m_numPassengers; i++) {

					cout << "|";
					cout.width(3);
					cout.setf(ios::right);
					cout << i + 1 << " ";
					cout.unsetf(ios::right);
					m_passengerList[i].display();
					cout << endl;

				}

				cout << "+----+------------------------------------------+-----+" << endl;

			}
			else { // if bus is not fully boarded, print error

				cout << "Cannot start the tour, the bus is not fully boarded!" << endl;

			}

		}

		return;
	}

	TourBus::TourBus(int numPassengers) { // sets passenger list to safe empty and number of passengers

		m_passengerList = nullptr;
		m_numPassengers = numPassengers;

	}

	TourBus::~TourBus() {

		delete[] m_passengerList; // deletes passenger list

	}

	

}