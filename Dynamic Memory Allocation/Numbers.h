/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 6 - Part 1

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <fstream>

namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& toCopy);
      Numbers& operator=(const Numbers& toCopy);
      Numbers& sort(bool ascnd);
      Numbers operator-()const;
      Numbers operator+()const;
      Numbers& operator+=(double num);
      std::ostream& display(std::ostream& ostr = std::cout)const;
      double average()const;
      double max()const;
      double min()const;
      int numberCount()const;
      bool load();
      void save();
      ~Numbers();
   };
   std::ostream& operator<<(std::ostream& ostr, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
   
}
#endif // !SDDS_NUMBERS_H_

