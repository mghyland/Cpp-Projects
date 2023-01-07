/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Milestone - Part 4

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include <iostream>

namespace sdds {

   class ReadWritable {
      bool csvFlag;
   public:
      ReadWritable();
      virtual ~ReadWritable();
      bool isCsv()const;
      void setCsv(bool value);
      virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
      virtual std::istream& read(std::istream& istr = std::cin) = 0;
   };
   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& RW);
   std::istream& operator>>(std::istream& istr, ReadWritable& RW);

}

#endif