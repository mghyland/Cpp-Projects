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
#include "Assessment.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	FILE* fptr = nullptr;

	bool read(int& value, FILE* fptr) {

		bool flag = false;
		if (fscanf(fptr, "%d[^\n]", &value) == 1) {
			flag = true;
		}
		// return(fscanf(fptr, "%d[^\n]", &value)); // Read file for integer
		return flag;
	}

	bool read(double& value, FILE* fptr) {

		bool flag = false;
		if (fscanf(fptr, "%lf[^,]", &value) == 1) {
			flag = true;
		}
		return flag;
		// return(fscanf(fptr, "%lf[^,]", &value)); // Read file for double

	}

	bool read(char* cstr, FILE* fptr) {

		bool flag = false;
		if (fscanf(fptr, ",%60[^\n]\n", cstr) == 1) {
			flag = true;
		}
		return flag;
		// return(fscanf(fptr, ",%60[^\n]\n", cstr)); // Read file for cstring

	}

	bool read(Assessment& asmnt, FILE* fptr) {

		double tempGrade = 0;
		char tempCourse[60 + 1];
		bool success = false;

		// Create temp variables and assign them using read for double and cstring

		if (read(tempGrade, fptr) && read(tempCourse, fptr)) {

			int length = strlen(tempCourse); // If there is a file, find the cstring length

			asmnt.m_mark = new double;
			asmnt.m_title = new char[length + 1]; // Create new double and char array exact length of cstring

			*asmnt.m_mark = tempGrade;
			strcpy(asmnt.m_title, tempCourse); // Assign values

			success = true;
		}

		return success;
		
	}

	void freeMem(Assessment*& aptr, int size) { // Delete allocated memory

		int i = 1;

		for (i = 0; i < 13; i++) { // Loop through array and delete each index

			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;


		}
		delete[] aptr; // Delete the Assessment array

		return;
	}

	int read(Assessment*& aptr, FILE* fptr) {

		int arraySize = 0;
		int numOfReads = 0;
		int flag = 0;


		read(arraySize, fptr); // Read file for number of records upcoming

		aptr = new Assessment[arraySize]; // Create new Assessment array with arraySize

		for (int i = 0; i < arraySize && flag == 0; i++) {

			if (read(aptr[i], fptr)) { // Read file for double and cstring

				numOfReads++; // Increase number of records if record found

			}
			else {

				flag = 1; // Set exit flag if read is false

			}
		}


		if (arraySize != numOfReads) { // If array size and number of records are different, delete alocated memory

			freeMem(aptr, arraySize);
			arraySize = 0;

		}

		return arraySize;
	}





}