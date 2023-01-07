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

	void NameTag::set(const char* name) { // gets the length of the name and sets it along with the name

		int length = strlen(name); 
		strcpy(m_name, name);
		m_nameLength = length;

		return;
	}


}