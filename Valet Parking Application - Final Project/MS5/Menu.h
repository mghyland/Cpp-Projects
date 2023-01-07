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
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>

namespace sdds {

#define MAX_NO_OF_ITEMS 10

   class Menu;

   class MenuItem {

      char m_itemName[50 + 1];
      MenuItem();
      MenuItem(const char* itemName);
      std::ostream& display(std::ostream& ostr = std::cout)const;
      MenuItem(const MenuItem&) = delete;
      void operator=(MenuItem&) = delete;
      bool isEmpty()const;
      void setEmpty();
      void set(const char* newItem);
      friend class Menu;

   };

   class Menu {

      char m_menuName[50 + 1];
      MenuItem m_itemList[MAX_NO_OF_ITEMS];
      int m_numItems;
      int m_indent;
      bool isEmpty()const;
      void setEmpty();
   public:
      Menu();
      Menu(const char* menuName, int indent = 0);
      Menu(const Menu&) = delete;
      void operator=(Menu&) = delete;
      operator bool()const;
      std::ostream& display(std::ostream& ostr = std::cout)const;
      Menu& operator=(const char* newName);
      void add(const char* newItem);
      Menu& operator<<(const char* newItem);
      int run()const;
      operator int()const;
      void clear();

   };

   void displayIndent(int indent);

}

#endif