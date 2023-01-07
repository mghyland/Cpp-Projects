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
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include "word.h"
#include "dictionary.h"
#include "file.h"

using namespace std;

namespace sdds {



	void DisplayWord(const char* word) {

		int wordNum = 0;
		int i = 0;
		int success = 0;
		int flag = 0;
		int def = 1;



		while (flag == 0 && wordNum < MAX_WORDS) {

			if (record.m_numOfWords == 0) { // If dictionary empty, print NOT FOUND
				
				cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
				flag = 1;
			}
			else {
				success = strcmp(word, record.m_wordList[wordNum].m_wordName); // Check word against dictionary words

				if (success == 0) {
					cout << "FOUND: [" << record.m_wordList[wordNum].m_wordName << "] has ["
						<< record.m_wordList[wordNum].m_numDefinitions << "] definitions:" << endl; // If FOUND, print word and number of definitions

					for (i = 0; i < record.m_wordList[wordNum].m_numDefinitions; i++) {

						cout << def << ". {" << record.m_wordList[wordNum].m_wordType[i] << "} " << // Print type and definition until none remain
							record.m_wordList[wordNum].m_definition[i] << endl;
						def++;

					}

					flag = 1;

				}
				else if (success != 0 && wordNum == record.m_numOfWords - 1) {

					cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl; // If word is not in dictionary already
					flag = 1;

				}
				else {
					wordNum++;

				}
			}

			

		}

		return;

	}

	void AddWord(const char* word, const char* type, const char* definition) {

		int wordNum = 0;
		int success = 0;
		int flag = 0;

		while (flag == 0 && wordNum <= record.m_numOfWords) {

			success = strcmp(word, record.m_wordList[wordNum].m_wordName); // Check word against dictionary words

			if (success == 0) {

				strcpy(record.m_wordList[wordNum].m_wordType[record.m_wordList[wordNum].m_numDefinitions], type); // If found, add new type and def
				strcpy(record.m_wordList[wordNum].m_definition[record.m_wordList[wordNum].m_numDefinitions], definition);
				record.m_wordList[wordNum].m_numDefinitions++;
				flag = 1;

			}
			else if (wordNum == record.m_numOfWords) {  // If not found, set name and then run Add Word again

				strcpy(record.m_wordList[wordNum].m_wordName, word);

				AddWord(word, type, definition);

				record.m_numOfWords++;

				flag = 1;

			}
			else {

				wordNum++;

			}

		}

		return;

	}

	int UpdateDefinition(const char* word, const char* type, const char* definition) {

		int wordNum = 0;
		int success = 0;
		int flag = 0;
		int i = 0;
		int def = 1;

		while (flag == 0 && wordNum < MAX_WORDS) {

			success = strcmp(word, record.m_wordList[wordNum].m_wordName); // Check word against dictionary

			if (success == 0) {

				if (record.m_wordList[wordNum].m_numDefinitions > 1) { // If found, check for multiple definitions

					cout << "The word [" << word << "] has multiple definitions:" << endl; // Print how many if multiple

					for (i = 0; i < record.m_wordList[wordNum].m_numDefinitions; i++) {

						cout << def << ". {" << record.m_wordList[wordNum].m_wordType[i] << "} " << // Display all definitions number 1,2,3...etc
							record.m_wordList[wordNum].m_definition[i] << endl;
						def++;

					}

					cout << "Which one to update? "; // Ask user which definition to update
					cin >> def;
					
					strcpy(record.m_wordList[wordNum].m_wordType[def - 1], type); // Update type and definition
					strcpy(record.m_wordList[wordNum].m_definition[def - 1], definition);

					flag = 1;

				}
				else {

					strcpy(record.m_wordList[wordNum].m_wordType[record.m_wordList[wordNum].m_numDefinitions], type); // Update if only single definition
					strcpy(record.m_wordList[wordNum].m_definition[record.m_wordList[wordNum].m_numDefinitions], definition);

					flag = 1;

				}

			}
			else {

				wordNum++;

			}

		}

		return 0;
	}

}