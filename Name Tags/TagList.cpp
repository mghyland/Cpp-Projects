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
#include "TagList.h"
#include "NameTag.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	int numTags = 0;
	int recCount = 0;
	int longestTag = 0;
	

	void TagList::set() { // sets the entire list to safe empty

		m_nameTagList = nullptr;
		
		return;
	}

	void TagList::set(int num) { // dynamically creates array equal to number of records

		cleanup();
		m_nameTagList = new NameTag[num];
		numTags = num;
		
		return;
	}

	void TagList::add(const NameTag& nt) { // adds new tag to the list

		if (recCount < numTags) {
				
			m_nameTagList[recCount] = nt;
			recCount++;

			if (longestTag < nt.m_nameLength) { // finds the longest name for frame length

				longestTag = nt.m_nameLength;

			}
		
		}

		return;
	}

	void TagList::print() { // displays each name with proper frame

		for (int i = 0; i < numTags; i++) {

			printFrame(longestTag); // prints frame for name

			cout << "* "; // * and 'space' take up first two characters
			cout.fill(' '); // 'space' fills the rest of the string
			cout.width(longestTag); // width is the longest tag name
			cout.setf(ios::left); // name is set left
			cout << m_nameTagList[i].m_name << " *" << endl; // prints name and 'space' * as last two characters
			cout.unsetf(ios::left); // unsets from the left

			printFrame(longestTag); // prints frame for largest name

		}

		return;
	}

	void TagList::cleanup() { // deallocates and sets to safe empty

		delete[] m_nameTagList;
		
		set();

		return;
	}

	void TagList::printFrame(int longestTag) { // prints proper frame size

		for (int i = 0; i < longestTag + 4; i++) {

			cout << "*";

		}
		cout << endl;

		return;
	}


}