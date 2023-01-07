/*****************************************************************************
Full Name : Matthew Hyland
Student ID# : 035286046
Email : mhyland@myseneca.ca
Section : NAA

Authenticity Declaration :
I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.
*****************************************************************************/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}


#endif
