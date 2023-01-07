/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_WORD_H
#define SDDS_WORD_H


namespace sdds {

	const int MAX_DEFINITIONS = 8;
	const int MAX_WORD_LENGTH = 64;
	const int MAX_DEFINITION_LENGTH = 1024;


	struct Word {
		char m_wordName[MAX_WORD_LENGTH + 1];
		char m_wordType[MAX_DEFINITIONS][MAX_WORD_LENGTH + 1];
		char m_definition[MAX_DEFINITIONS][MAX_DEFINITION_LENGTH];
		int m_numDefinitions;


	};

	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
	int UpdateDefinition(const char* word, const char* type, const char* definition);
}


#endif
