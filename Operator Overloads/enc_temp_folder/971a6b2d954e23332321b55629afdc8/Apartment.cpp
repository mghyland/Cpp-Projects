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

       if (operator bool()) {

           return m_number;

       }

   }
   Apartment::operator double() const {

       return m_balance;
   }
   bool Apartment::operator~() const {

       return false;
       
   }

   Apartment& Apartment::operator=(int aprtNum) {

       m_number = aprtNum;

       return *this;
   }

   Apartment& Apartment::operator=(Apartment& one) {

       int tempNum = 0;
       double tempBal = 0.0;

       tempNum = m_number;
       m_number = one.m_number;
       one.m_number = tempNum;

       tempBal = m_balance;
       m_balance = one.m_balance;
       one.m_balance = tempBal;

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

   Apartment& Apartment::operator<<(Apartment& rBalance) {

       if (m_balance != rBalance.m_balance && m_number != rBalance.m_number) {
           m_balance = m_balance + rBalance.m_balance;
           rBalance.m_balance = rBalance.m_balance - rBalance.m_balance;
       }
       
       return *this;
   }

   Apartment& Apartment::operator>>(Apartment& rBalance) {

       rBalance.m_balance = m_balance + rBalance.m_balance;
       m_balance = m_balance - m_balance;

       return *this;
   }


   double operator+(const Apartment& one, const Apartment& two) {

       double total = 0.0;

       total = double(one) + double(two);

       return total;
   }

   double operator+=(double& balance, const Apartment& one) {


       balance = double(balance) + double(one);

       return balance;
   }


}