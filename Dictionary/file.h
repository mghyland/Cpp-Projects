/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "dictionary.h"

namespace sdds {

	bool openFileForRead(const char* filename);
	bool openFileForOverwrite(const char* filename);
	void closeFile();
	bool freadDictionary(Dictionary* record, const char* filename);
	void fwriteDictionary(const Dictionary* record);
}


#endif