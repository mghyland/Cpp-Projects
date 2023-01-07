/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 4 - Part 1

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Seat.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	char validSeatsBus[] = { 'A', 'B', 'E', 'F' };
	char validSeatsEco[] = { 'A', 'B', 'C', 'D', 'E', 'F' };


	bool Seat::validate(int row, char letter)const { // validation of row and seat

		bool success = false;
		int flag = 0;

		if (row > 0 && row < 5) { // rows 1 - 4

			for (int i = 0; i < 4 && flag == 0; i++) { // loop through validSeatBus char array

				if (letter == validSeatsBus[i]) { // seat must be one of A, B, E, F

					success = true; // return true if valid
					flag = 1;

				}
			}
		}
		
		if (row > 6 && row < 16) { // rows 7 - 15

			for (int i = 0; i < 6 && flag == 0; i++) { // loop through validSeatEco char array

				if (letter == validSeatsEco[i]) { // seat must be one of A, B, C, D, E, F

					success = true; // return true if valid
					flag = 1;

				}
			}
		}

		if (row > 19 && row < 39) { // rows 20 - 38

			for (int i = 0; i < 6 && flag == 0; i++) { // loop through validSeatEco char array

				if (letter == validSeatsEco[i]) { // seat must be one of A, B, C, D, E, F 

					success = true; // return true if valid
					flag = 1;

				}
			}
		}

		return success;
	}

	Seat& Seat::alAndCp(const char* str) { // allocates dynamic memory and copies

		reset(); // reset object to safe empty state

		if (isEmpty() && str != NULL) { // make sure it's empty and not equal to null
			
			int length = strlen(str); // get name length

			if (length > 0) { // check that name is not empty string

				m_name = new char[length + 1];
				strcpy(m_name, str); // create new char and copy string to name attribute

			}
			
		}

		return *this;

	}

	Seat& Seat::reset() { // resets object to safe empty state

		delete[] m_name; // delete name and set to nullptr, set row and seat to 0
		m_name = nullptr;
		m_rowNum = 0;
		m_seatLetter = 0;


		return *this;

	}

	bool Seat::isEmpty()const { // checks to see if name attribute is empty

		bool success = true;
		if (this->m_name != nullptr) {
			success = false;
		}

		return success;

	}

	bool Seat::assigned()const { // checks if seats are invalid, returns true or false
		
		bool success = true;
		if (!validate(this->m_rowNum, this->m_seatLetter)) { // validate row and seat
			success = false;
		}

		return success;

	}

	Seat::Seat() { // zero-argument constructor that sets object to safe empty

		reset();

		return;
	}

	Seat::Seat(const char* passengerName) { // single-argument constructor that takes passenger name

		reset(); // resets to safe empty state
		alAndCp(passengerName); // allocates dynamic memory and sets passenger name attribute

		return;
	}

	Seat::Seat(const char* passengerName, int row, char letter) { // three-argument constructor taking name, row, seat

		reset(); // reset to safe empty state
		alAndCp(passengerName); // allocates dynamic memory and sets passenger name attribute
		set(row, letter); // sets row and seat letter

		return;
	}

	Seat::~Seat() { // deconstructor that deletes name
		
		delete[] m_name;

		return;
	}

	Seat& Seat::set(int row, char letter) { // sets the row and seat if valid

		if (validate(row, letter)) { // validates and sets if valid

			m_rowNum = row;
			m_seatLetter = letter;

		}
		else { // if invalid, sets row and seat to 0

			m_rowNum = 0;
			m_seatLetter = 0;

		}

		return *this;

	}

	int Seat::row()const { // returns row number

		return m_rowNum;

	}

	char Seat::letter()const { // returns seat letter

		return m_seatLetter;

	}

	const char* Seat::passenger()const { // returns passenger name

		return m_name;

	}

	std::ostream& Seat::display(std::ostream& coutRef)const { // displays passenger data
		
		char tempName[40 + 1]{}; // temp char array to copy 40 chars of name only

		if (isEmpty() || m_name == NULL) { // checks if empty or name is equal to null

			coutRef << "Invalid Seat!"; // if invalid, error is shown

		}
		else {

			strcpy(tempName, m_name, 40); // copy 40 chars of passenger name

			coutRef.fill('.'); // fill with '.', 40 chars wide, left justified
			coutRef.width(40);
			coutRef.setf(ios::left);
			coutRef << tempName;
			coutRef.unsetf(ios::left); // unset left justified
			coutRef << " "; // print space between seat info
			coutRef.fill(' '); // fill with ' ' before row number
			

			if (validate(m_rowNum, m_seatLetter)) { // validates row and seat

				coutRef << m_rowNum << m_seatLetter; // sets if valid

			}
			else {
				coutRef << "___"; // prints '___' if invalid
			}

		}
			

		return coutRef;
	}

	std::istream& Seat::read(std::istream& cinRef) { // reads user input or file

		char tempName[71]; // temp name up to 70 chars, temp row and temp seat letter
		int tempRow = 0;
		char tempLetter = 0;

		reset(); // resets to safe empty state

		cinRef.getline (tempName, 71, ','); // reads passenger name up to 70 chars
		
		if (cinRef) { // if name is valid, reads the row number
			cinRef >> tempRow;

			if (cinRef) { // if row number is read, reads the seat letter
				cinRef >> tempLetter;
				cinRef.ignore(100, '\n'); // ignore anything in buffer

				if (cinRef) { // if cin does not fail, allocate, copy and set row and seat letter

					alAndCp(tempName);
					set(tempRow, tempLetter);
				}
			}
		}

		

		return cinRef;
	}


}