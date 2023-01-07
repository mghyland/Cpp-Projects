/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "file.h"
#include "dictionary.h"
#include "file.h"

using namespace std;

namespace sdds {

	FILE* dfp = nullptr;

	bool openFileForRead(const char* filename) {

		dfp = fopen(filename, "r");
		return dfp != NULL;
	}

	bool openFileForOverwrite(const char* filename) {
		dfp = fopen(filename, "w");
		return dfp != NULL;
	}

	void closeFile() {
		if (dfp) fclose(dfp);
	}

	bool freadDictionary(Dictionary* record, const char* filename) {

		int name = 0;
		int success = 0;
		int wordNum = 0;
		int i = 0;
		int flag = 0;
		int tab = 0;

		flag = 1;
		while (wordNum < MAX_WORDS && flag == 1) {

			name = fscanf(dfp, "%[^\n]%*c", record->m_wordList[wordNum].m_wordName);
			record->m_numOfWords++;

			i = 0;
			flag = 0;
			while (flag == 0) {

				if (name == 1) { // Continue if any name is found
					tab = 0;
					tab = fgetc(dfp); // Checking for tab, which is ASCII 9

					if (tab == 9) {

						fscanf(dfp, "%[^:]s", record->m_wordList[wordNum].m_wordType[i]);
						fscanf(dfp, "%*c%*c%[^\n]%*c", record->m_wordList[wordNum].m_definition[i]);
						record->m_wordList[wordNum].m_numDefinitions++;
						i++;

					}
					else if (tab == 10) { // If its newline (ASCII 10)

						flag = 1;
						wordNum++;

					}
					else { // If it's anything else (EOF)

						flag = 2;
						success = 1;

					}

				}


			}

		}

		return success;

	}

	void fwriteDictionary(const Dictionary* record) {

		int wordNum = 0;
		int i = 0;


		for (wordNum = 0; wordNum < record->m_numOfWords; wordNum++) {

			fprintf(dfp, "%s\n", record->m_wordList[wordNum].m_wordName); // Prints name and newline to new file

			for (i = 0; i < record->m_wordList[wordNum].m_numDefinitions; i++) {

				fprintf(dfp, "\t%s: %s\n", record->m_wordList[wordNum].m_wordType[i], // Prints tab, type, colon, space, definition and newline
					record->m_wordList[wordNum].m_definition[i]);

			}

			if (wordNum < record->m_numOfWords - 1) { // Check if this is the last word

				fprintf(dfp, "\n"); // If not, print newline between words

			}

		}

		

		return;
	}

}*/