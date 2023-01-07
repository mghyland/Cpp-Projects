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
   Apartment::Apartment(int number, double balance) //sets apartment number and rent balance
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Apartment::display() const //displays apartment number and rent balance
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
   Apartment::operator bool() const { // checks whether apartment number is valid and rent 
                                      // balance is greater than zero, returns true or false

       return (m_number >= 1000 && m_number <= 9999
           && m_balance >= 0);

   }
   Apartment::operator int() const {

       int num = 0;

       if (operator bool()) { // checks for valid number and balance

           num = m_number; // if valid, returns apartment number

       }
       else {

           num = -1; // if invalid, returns -1

       }

       return num;

   }
   Apartment::operator double() const { 

       double balance = 0.0;

       if (operator bool()) { // checks if apartment and balance are valid

           balance = m_balance; // if valid, returns rent balance

       }
       else {

           balance = 0.0; // if invalid, returns 0.0

       }

       return balance;
   }
   bool Apartment::operator~() const {

       bool empty = true; // assume true to start

       if (m_balance > 0.00001) { // checks if rent balance is zero

           empty = false; // if not greater than zero, returns false, else returns true

       }

       return empty;
   }

   Apartment& Apartment::operator=(int aprtNum) { // assigns new apartment number

       m_number = aprtNum;

       return *this;
   }

   Apartment& Apartment::operator=(Apartment& one) { // swaps values of two different apartments

       int tempNum = 0;
       double tempBal = 0.0;

       tempNum = m_number;
       m_number = one.m_number; // swaps apartment number
       one.m_number = tempNum;

       tempBal = m_balance;
       m_balance = one.m_balance; // swaps rent balance
       one.m_balance = tempBal;

       return *this;
   }

   Apartment& Apartment::operator+=(double balance) { // adds two rent balances together

       if (balance > 0) { // if balance is not zero, adds the two together

           m_balance = m_balance + balance;

       }
       
       return *this;
   }

   Apartment& Apartment::operator-=(double balance) { // subtracts from rent balance

       if (m_balance > balance && balance > 0) { // checks that rent balance is greater than
                                                 // deduction and deduction is greater than zero

           m_balance = m_balance - balance; // if true, deducts from rent balance

       }

       return *this;
   }

   Apartment& Apartment::operator<<(Apartment& rBalance) { // adds rent balance from right to left
                                                           // and makes one balance equal zero

       // checks that its not the same apartment
       if (m_balance != rBalance.m_balance && m_number != rBalance.m_number) {

           // if not the same, deducts from the left, makes right equal zero
           m_balance = m_balance + rBalance.m_balance;
           rBalance.m_balance = rBalance.m_balance - rBalance.m_balance;

       }
       
       return *this;
   }

   Apartment& Apartment::operator>>(Apartment& rBalance) { // adds rent balance from left to right
                                                           // and makes right equal zero

       rBalance.m_balance = m_balance + rBalance.m_balance;
       m_balance = m_balance - m_balance;

       return *this;
   }


   double operator+(const Apartment& one, const Apartment& two) { // adds the rent balance of two apartments
                                                                  // and returns total

       double total = 0.0;

       total = double(one) + double(two);

       return total;
   }

   double operator+=(double& balance, const Apartment& one) { // adds the rent balance from each apartment one
                                                              // at a time

       balance = double(balance) + double(one);

       return balance;
   }


}