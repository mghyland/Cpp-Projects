/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 4 - Part 1

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
namespace sdds {
   int strlen(const char* str);
   // copies up to len chars from src to des
   // if len is negative, it will copy up to null char
   // resulting a cstring in des in any case
   void strcpy(char* des, const char* src, int len=-1);
   int strcmp(const char* s1, const char* s2);

}
#endif // !SDDS_UTILS_H_


