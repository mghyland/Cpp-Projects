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
#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H

namespace sdds {

	class NameTag {
	public:
		char m_name[51] = { '\0' };
		int m_nameLength;
		void set(const char* name);
	};



}



#endif