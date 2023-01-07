/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 4 - Part 2

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#ifndef SDDS_TOURTICKET_H_
#define SDDS_TOURTICKET_H_
#include <iostream>
namespace sdds {
   class TourTicket {
      char m_name[41];
      int m_ticketNumber;
      void copyName(const char* str);
   public:
      TourTicket();
      TourTicket& issue(const char* passengerName);
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      bool valid()const;
   };
}
#endif // !SDDS_TOURTICKET_H_


