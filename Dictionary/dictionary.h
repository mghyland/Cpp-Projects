/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include "word.h"

namespace sdds {

	const int MAX_WORDS = 100;

	extern struct Dictionary record;

	struct Dictionary {
		int m_numOfWords;
		Word m_wordList[MAX_WORDS];
	};

	int LoadDictionary(const char* filename);
	void SaveDictionary(const char* filename);

}


#endif