/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Milestone - Part 2

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include "string.h"
#include <iostream>
#include "Menu.h"

using namespace std;
namespace sdds {

   MenuItem::MenuItem() { // no-argument constructor for MenuItem

      setEmpty(); // set MenuItem to empty

   }

   MenuItem::MenuItem(const char* itemName) { // one-argument constructor

      setEmpty(); // set MenuItem to empty
      strncpy(m_itemName, itemName, 50); // copy new item name to MenuItem name

   }

   std::ostream& MenuItem::display(std::ostream& ostr) const { // display item name

      if (!isEmpty()) { // check itemName is not NULL

         ostr << m_itemName; // display item name

      }

      return ostr;

   }

   bool MenuItem::isEmpty()const { // checks if itemName is equal to NULL

      return m_itemName[0] == '\0';

   }

   void MenuItem::setEmpty() { // sets item name equal to null

      m_itemName[0] = '\0';

   }

   Menu::Menu() { // no-argument constructor for Menu

      setEmpty(); // set Menu to empty

   }

   Menu::Menu(const char* menuName, int indent) { // two-argument constructor for Menu, indent is 0 by default

      setEmpty(); // set Menu to empty
      strncpy(m_menuName, menuName, 50); // set menu name
      m_indent = indent; // set indent

   }

   Menu::operator bool()const { // bool overload to check if Menu is NOT empty

      return(!isEmpty());

   }

   bool Menu::isEmpty()const { // checks if Menu is empty, returns true if empty, false otherwise

      return m_menuName[0] == '\0';

   }

   void Menu::setEmpty() { // sets Menu to empty

      m_menuName[0] = '\0'; // set menu name to NULL
      m_numItems = 0; // set number of items to 0

   }

   void MenuItem::set(const char* newItem) { // set MenuItem name

      strncpy(m_itemName, newItem, 50); // copy new name to MenuItem name

   }

   void Menu::clear() { // clear Menu and set entire Menu to empty

      setEmpty();

   }

   std::ostream& Menu::display(std::ostream& ostr)const { // display Menu

      int count = 1; // count used to set option numbers (ex. 1- Option One, 2- etc...)

      if (!isEmpty()) { // checks that Menu is not empty

         if (m_numItems > 0) { // checks that number of items is greater than 0

            if (m_indent == 0) { // if no indent, display aligned left

               ostr << m_menuName << endl; // display menu name
               for (int i = 0; i < m_numItems; i++) {

                  ostr << count << "- "; // display option number and dash (ex. #- )
                  m_itemList[i].display() << endl; // display menu item
                  count++; // increase count number

               }

               cout << "> "; // display before input

            }
            else { // if indent value is given

               displayIndent(m_indent); // display indent

               cout << m_menuName << endl; // display menu name after indent

               for (int i = 0; i < m_numItems; i++) { // display all items after indent on each line

                  displayIndent(m_indent);

                  ostr << count << "- ";
                  m_itemList[i].display() << endl;
                  count++;

               }

               displayIndent(m_indent); // display indent

               cout << "> "; // display before input

            }

         }
         else { // if menu has no menu items

            ostr << m_menuName << endl; // display menu name
            ostr << "No Items to display!" << endl; // display no items message

         }

      }
      else { // if menu is empty

         ostr << "Invalid Menu!" << endl; // display invalid menu message

      }

      return ostr;

   }

   Menu& Menu::operator=(const char* newName) { // assign new name to Menu

      setEmpty(); // set Menu to empty
      if (newName != nullptr) { // checks that new name is not NULL

         strncpy(m_menuName, newName, 50); // if valid, copy new name to menu name

      }

      return *this;

   }

   void Menu::add(const char* newItem) { // add menu item to item list

      if (newItem != nullptr && !this->isEmpty()) { // checks that new item is valid and object is NOT empty

         if (m_numItems < MAX_NO_OF_ITEMS) { // checks that there is space to add item

            m_numItems++; // increase number of items
            m_itemList[m_numItems - 1].set(newItem); // set item name in item list

         }

      }
      else { // if empty, clear Menu

         clear();

      }

   }

   Menu& Menu::operator<<(const char* newItem) { // add menu item to menu list with left shift operator

      add(newItem); // run add to add new item

      return *this;

   }

   int Menu::run()const { // display menu and options and request user input option

      int optionNum = 0;
      int flag = 0;

      this->display(); // display menu name and menu items

      while (m_numItems > 0 && flag == 0) { // while number of items is greater than 0 and flag is equal 0

         cin >> optionNum; // set optionNum to user input

         if (!cin) { // if cin fails

            cout << "Invalid Integer, try again: "; // display invalid integer message
            cin.clear(); // clear cin
            cin.ignore(1000, '\n'); // ignore anything in the buffer

         }
         else { // if cin is successful

            if (optionNum < 1 || optionNum > m_numItems) { // if option is 0 or greater than number of items

               cout << "Invalid selection, try again: "; // display invalid integer message

            }
            else { // if option is valid

               flag = 1; // set flag equal to 1 to exit loop
               cin.ignore(1000, '\n'); // clear buffer

            }

         }

      }

      return optionNum; // return the option number chosen

   }

   Menu::operator int()const { // integer operator cast

      return run(); // return the integer value chosen

   }

   void displayIndent(int indent) { // display the indent, depending on the value given

      for (int i = 0; i < (indent * 4); i++) { // multiply indent value by 4 and out that many spaces

         cout << " ";

      }

   }


}