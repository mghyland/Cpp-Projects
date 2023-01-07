/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string.h>
#include "CC.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	const long long minCardNum = 4000000000000000; // min and max for card number
	const long long maxCardNum = 4099999999999999;
	

	bool CC::validate(const char* name,
		unsigned long long cardNo,
		short cvv,
		short expMon,
		short expYear)const {

		int length = 0;
		bool success = true;

		if (name == NULL) { // checks name for NULL
			success = false;
		}
		else {
			length = strlen(name); // if name is not NULL, get length and check
			if (length <= 2) {
				success = false;
			}
		}
		if (cardNo > maxCardNum || cardNo < minCardNum) { // check card number
			success = false;
		}
		if (cvv < 100 || cvv > 999) { // check cvv
			success = false;
		}
		if (expMon < 1 || expMon > 12) { // check expiry month
			success = false;
		}
		if (expYear < 22 || expYear > 32) { // check expiry year
			success = false;
		}

		return success; // return true only if all are valid
	}

	void CC::prnNumber()const {

		int num = 0;
		unsigned long long remaining = 0;

		num = m_cardNum / 1000000000000;  // get first 4 digits by division
		remaining = m_cardNum % 1000000000000; // get the remaining by modulus
		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right); // set output parameters

		cout.width(4);
		cout << num << " ";
		num = remaining / 100000000; // same process as above, just in relation to new length
		remaining = remaining % 100000000;
		cout.width(4);
		cout << num << " ";
		num = remaining / 10000;
		remaining = remaining % 10000;
		cout.width(4);
		cout << num << " ";
		num = remaining / 1;
		cout.width(4);
		cout << num;
		
		cout.fill(' ');
		cout.unsetf(ios::right);
		

		return;
	}

	void CC::set() { // sets all values to safe empty state

		m_name = nullptr;
		m_cardNum = {};
		m_cvv = {};
		m_expMon = {};
		m_expYear = {};

		return;

	}

	void CC::cleanUp() { // deletes name and sets all values to safe empty state
		delete[] m_name;
		set();
		return;

	}

	bool CC::isEmpty()const { // checks whether the name is NULL to determine if record exists
		bool success = true;
		if (this->m_name != nullptr) {
			success = false;
		}
		return success; // returns true if name is equal to NULL

	}

	void CC::set(const char* cc_name, // sets all values
		unsigned long long cc_no,
		short cvv,
		short expMon,
		short expYear) {

		cleanUp(); // first deletes name and sets values to safe empty state

		if (validate(cc_name, cc_no, cvv, expMon, expYear)) { // validates the values

			int length = strlen(cc_name); // if they are all valid, they are set
			char* nameCopy = new char[length + 1];
			this->m_name = new char[length + 1];
			strcpy(nameCopy, cc_name);

			strcpy(this->m_name, nameCopy, length + 1);
			this->m_cardNum = cc_no;
			this->m_cvv = cvv;
			this->m_expMon = expMon;
			this->m_expYear = expYear;

			delete[] nameCopy;
		}
		

		return;

	}

	bool CC::read() {

		char name[71 + 1];
		unsigned long long cardNum;
		short cvv;
		short expMon;
		short expYear;
		bool success = false;

		cleanUp();

		cout << "Card holder name: "; // takes name
		cin.getline(name, 71);

		if (cin) {

			cout << "Credit card number: "; // takes card number
			cin >> cardNum;

			if (cin) {

				cout << "Card Verification Value (CVV): "; // takes cvv
				cin >> cvv;

				if (cin) {

					cout << "Expiry month and year (MM/YY): "; // takes expiry
					cin >> expMon;
					cin.ignore(1, '\n');
					cin >> expYear;

					if (cin) { // if cin gets valid entry, they are validated and set to safe empty state

						success = validate(name, cardNum, cvv, expMon, expYear);
						set();
					}
				}
			}
			
		}
		if (success == true) { // if they are valid, they are set

			set(name, cardNum, cvv, expMon, expYear);


		}
		else { // if they are not valid, cin is cleared

			cin.clear();

		}
		

		cin.ignore(10000, '\n'); // ignore 10000 characters just in case

		if (isEmpty()) { // checks that the record is empty (has no name)

			success = false;

		}


		return success;

	}

	void CC::display(int row)const { 

		if (isEmpty()) {

			cout << "Invalid Credit Card Record" << endl; // displays invalid if empty

		}
		else {

			if (row > 0) { // displays in tabular format when row is greater than 0

				char tempName[30 + 1]{};

				strcpy(tempName, m_name, 30);
				
				cout << "| ";
				cout.fill(' ');
				cout.width(3);
				cout.setf(ios::right);
				cout << row << " | ";
				cout.unsetf(ios::right);

				//cout.fill(' ');
				cout.width(30);
				cout.setf(ios::left);
				cout << tempName << " | ";
				cout.unsetf(ios::left);

				prnNumber();

				cout << " | " << m_cvv << " | ";

				//cout.fill(' ');
				cout.width(2);
				cout.setf(ios::right);
				cout << m_expMon;
				cout.unsetf(ios::right);
				cout << "/" << m_expYear << " |" << endl;
			}
			else {

				cout << "Name: " << m_name << endl; // diaplays in form format when row is 0
				cout << "Creditcard No: ";
				prnNumber();
				cout << endl;
				cout << "Card Verification Value: " << m_cvv << endl;
				cout << "Expiry Date: " << m_expMon << "/" << m_expYear << endl;
			}
		}

		return;
	}

	



}