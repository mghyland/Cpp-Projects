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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include "Numbers.h"
using namespace std;
namespace sdds {


   Numbers::Numbers() { // no-argument constructor, sets to safe empty and isOriginal to false
      setEmpty();
      m_isOriginal = false;
   } 

   Numbers::Numbers(const char* filename) { // one-argument constructor
      setEmpty(); // sets to safe empty
      m_isOriginal = true; // sets isOriginal to true
      setFilename(filename); // sets filename
      m_numCount = numberCount(); // sets number of lines by numberCount
      if (m_numCount == 0 || !load()) { // if no load and nnumCount is zero, deallocate and set to safe empty state
         deallocate();
         setEmpty();
         m_isOriginal = false; 
      }
   }

   Numbers::Numbers(const Numbers& toCopy) { // copy constructor

       setEmpty(); // set to safe empty state
       m_isOriginal = false; // set isOriginal to false
       *this = toCopy;// call copy assignment operator

   }

   Numbers& Numbers::operator=(const Numbers& toCopy) { // copy assignment operator

       deallocate(); // deallocate memory and set to safe empty state
       setEmpty();
       m_numbers = new double[toCopy.m_numCount]; // create dynamic memory for new numbers array
       m_numCount = toCopy.m_numCount; // copy numCount
       m_isOriginal = false; // set isOriginal to false, indicating copy

       for (int i = 0; i < m_numCount; i++) { // copy numbers to new dynamic array

           m_numbers[i] = toCopy.m_numbers[i];

       }

       return *this; // return the current object
   }

   Numbers& Numbers::sort(bool ascnd) { // sort numbers ascending or descending

       double temp; // set local temp to hold number while sorting
       
       if (ascnd) { // if ascnd is true, sort in ascending

           for (int i = m_numCount - 1; i > 0; i--) {
               for (int j = 0; j < i; j++) {
                   if (m_numbers[j] > m_numbers[j + 1]) {
                       temp = m_numbers[j];
                       m_numbers[j] = m_numbers[j + 1];
                       m_numbers[j + 1] = temp;
                   }
               }
           }

       }
       else { // if false, sort in descending

           for (int i = m_numCount - 1; i > 0; i--) {
               for (int j = 0; j < i; j++) {
                   if (m_numbers[j] < m_numbers[j + 1]) {
                       temp = m_numbers[j];
                       m_numbers[j] = m_numbers[j + 1];
                       m_numbers[j + 1] = temp;
                   }
               }
           }

       }
       
       return *this; // return the current object
   }

   Numbers Numbers::operator-() const { // sort in descending order

       Numbers temp; // create temp instance

       temp = *this; // call copy operator to copy current object to temp

       temp.sort(false); // set sort argument false and sort temp descending

       return temp; // return temp
   }

   Numbers Numbers::operator+() const { // sort in ascending order

       Numbers temp; // create temp instance

       temp = *this; // call copy operator to copy current object to temp

       temp.sort(true); // set sort argument to true and sort temp ascending

       return temp; // return temp
   }

   Numbers& Numbers::operator+=(double num) { // add a number to the array

       double* numbers = new double[m_numCount + 1]; // create temp array to store numbers

       for (int i = 0; i < m_numCount; i++) { // loop through each number

           numbers[i] = m_numbers[i]; // set temp numbers equal to m_numbers

       }

       m_numCount++; // increment m_numCount to add new number

       numbers[m_numCount - 1] = num; // add new number to last index position

       delete[] m_numbers; // delete m_numbers array

       m_numbers = numbers; // set m_numbers equal to temp array

       return *this;
   }

   std::ostream& operator<<(std::ostream& ostr, const Numbers& num) {
       return num.display(ostr);
   }

   std::istream& operator>>(std::istream& istr, Numbers& N) { // add number to current object

       double num = 0.0; // create local variable to hold new double

       istr >> num; // set new num equal to istr

       if (istr) { // if istr successful, add num to current object

           N += num;

       }

       return istr; // return istr
   }

   std::ostream& Numbers::display(ostream& ostr) const { // displays numbers list or "Empty List"

       if (m_numCount == 0) { // if numCount equals zero, print "Empty List"

           ostr << "Empty list";

       }
       else {

           ostr << "=========================" << endl;

           if (!m_isOriginal) { // if this is a copy, print "*** COPY ***"

               ostr << "*** COPY ***" << endl;

           }
           else {

               ostr << m_filename << endl; // if this is original, print file name

           }

           for (int i = 0; i < m_numCount; i++) { // print numbers separated by comma

               ostr.setf(ios::fixed);
               ostr.precision(2);
               ostr << m_numbers[i];

               if (i < (m_numCount - 1)) {

                   ostr << ", ";

               }

               
           }
          
           ostr << endl;
                      
           ostr << "-------------------------" << endl;

           ostr << "Total of " << m_numCount << " number(s)" << endl; // print total number, largest, smallest, average

           ostr.fill(' ');
           ostr.width(17);
           ostr.setf(ios::left);
           ostr << "Largest number: " << max() << endl;
           ostr.fill(' ');
           ostr.width(17);
           ostr.setf(ios::left);
           ostr << "Smallest number: " << min() << endl;
           ostr.fill(' ');
           ostr.width(17);
           ostr.setf(ios::left);
           ostr << "Average: " << average() << endl;
           ostr << "=========================";

       }

       return ostr;
   }

   Numbers::~Numbers() { // destructor saves original and deallocates memory
      save();
      deallocate();
   }

   bool Numbers::isEmpty() const { // checks if in safe empty state
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { // sets to safe empty state
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() { // deallocates memory by deleting file name and numbers
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) { // sets file name
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

  

   double Numbers::average() const { // finds numbers average
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const { // finds smallest number
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }

   double Numbers::max() const { // finds largest number
       double maxVal = 0.0;
       if (!isEmpty()) {
           maxVal = m_numbers[0];
           for (int i = 1; i < m_numCount; i++)
               if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
       }
       return maxVal;
   }

   int Numbers::numberCount()const { // count number of lines in file

       char c;
       int numLines = 0;
       ifstream numCount; // create instance of ifstream

       numCount.open(m_filename); // open file

       if (numCount.is_open()) { // check the file opened

           while (numCount.get(c)) { // while there are characters to read

               if (c == '\n') { // if char equals new line, increment num

                   numLines++;

               }
           }
       }

       numCount.close(); // close file
       
       return numLines; // return number of new lines
   }

   bool Numbers::load() { // write numbers to file 

       int num = 0;

       if (m_numCount > 0) { // if number of lines is greater than zero

           m_numbers = new double[m_numCount]; // allocate array to store numbers
           ifstream file; // create instance of ifstream

           file.open(m_filename); // open file

           if (file.is_open()) { // check the file opened

               for (int i = 0; i < m_numCount; i++) { // loop through numbers from file

                   file >> m_numbers[i]; // write numbers into file
                   num++; // increment count

               }

           }

           file.close(); // close file

       }
       
       return num == m_numCount; // return whether count is equal to m_numCount
   }

   void Numbers::save() { // saves copy of original

       if (m_isOriginal && !isEmpty()) { // checks if original and not empty

           ofstream file; // create ofstream instance

           file.open(m_filename); // open file

           for (int i = 0; i < m_numCount; i++) { // write original numbers to file

               file.setf(ios::fixed);
               file.precision(2);
               file << m_numbers[i] << endl;

           }
                      
       }

       return;
   }

   
  

}
