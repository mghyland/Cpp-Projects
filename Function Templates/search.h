/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 10 - Part 1

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_SEARCH_H
#define SDDS_SEARCH_H
#include "Collection.h"

namespace sdds {

   template <typename T1, typename T2, typename T3>
   bool search(const T1 arr1[], int numElements, const T2 keyValue, Collection<T3>& arrObj);

   template<typename T1, typename T2, typename T3>
   bool search(const T1 arr1[], int numElements, const T2 keyValue, Collection<T3>& arrObj) {

      // Set the collection array to empty by setting size to 0
      arrObj.resize(0);

      // Assume false, that there will be no match
      bool match = false;

      // Iterate through array and check for matching keyValue
      for (int i = 0; i < numElements; i++) {

         // If match is found, add it to the collection
         if (arr1[i] == keyValue) {

            arrObj.add(arr1[i]);

         }

      }

      // If the array size is greater than zero, set match equal to true
      if (arrObj.size() > 0) {

         match = true;

      }

      return match;
   }

}



#endif