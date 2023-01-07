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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TourTicket.h"

using namespace std;
namespace sdds {
   int next_ticketNumber = 100;
   void TourTicket::copyName(const char* str) { // copies name up to 40 char
      int i=0;
      for(i=0;i < 40 && str[i]; m_name[i] = str[i], i++);
      m_name[i] = 0;
   }
   TourTicket::TourTicket() { // constructor, sets to safe empty
      m_name[0] = char(0);
      m_ticketNumber = -1;
   }
   TourTicket& TourTicket::issue(const char* passengerName) { // issues ticket number and assigns names to
      if(passengerName && passengerName[0]) {                 // the passenger list
         copyName(passengerName);
         m_ticketNumber = next_ticketNumber++;
      }
      return *this;
   }
   std::ostream& TourTicket::display(std::ostream& coutRef) const { // displays name and ticket number
      if(valid()) {
         cout << "| ";
         coutRef.width(40);
         coutRef.setf(ios::left);
         coutRef << m_name << " | " << m_ticketNumber << " |";
         coutRef.unsetf(ios::left);
      }
      else {
         coutRef << "Invalid TourTicket information" << endl; // error message if invalid ticket info
      }
      return coutRef;
   }
   bool TourTicket::valid() const { // checks if name is valid
      return bool(m_name[0]);
   }
}