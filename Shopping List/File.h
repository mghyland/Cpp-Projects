/*****************************************************************************
Full Name : Matthew Hyland
Student ID# : 035286046
Email : mhyland@myseneca.ca
Section : NAA

Authenticity Declaration :
I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.
*****************************************************************************/
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds
{
	
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif
