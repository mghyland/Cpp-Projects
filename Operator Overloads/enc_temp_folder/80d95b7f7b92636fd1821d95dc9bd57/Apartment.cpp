/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Workshop 5 - Part 1

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }
   Apartment::operator bool() const {

       return (m_number >= 1000 && m_number <= 9999
           && m_balance >= 0);
   }
   Apartment::operator int() const {

       return 0;
   }
   Apartment::operator double() const {

       return 0.0;
   }
   bool Apartment::operator~() const {

       return false;
       
   }

   Apartment& Apartment::operator=(int aprtNum) {

       return *this;
   }

   Apartment& Apartment::operator=(Apartment&) {

       return *this;
   }

   Apartment& Apartment::operator+=(double balance) {

       if (balance > 0) {
           m_balance = m_balance + balance;
       }
       
       
       return *this;
   }

   Apartment& Apartment::operator-=(double balance) {

       if (m_balance > balance && balance > 0) {
           m_balance = m_balance - balance;
       }

       return *this;
   }

   Apartment& Apartment::operator<<(Apartment& balance) {

       return *this;
   }

   Apartment& Apartment::operator>>(Apartment& balance) {

       return *this;
   }


   double operator+(const Apartment& one, const Apartment&) {

       return 0.0;
   }

   double operator+=(double& balance, const Apartment&) {

       return 0.0;
   }


}