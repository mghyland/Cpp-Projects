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
#ifndef SDDS_TAGLIST_H
#define SDDS_TAGLIST_H
#include "NameTag.h"

namespace sdds {

	class TagList {
	private:
		NameTag* m_nameTagList;
	public:
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
		void printFrame(int longestTag);
	};


}



#endif