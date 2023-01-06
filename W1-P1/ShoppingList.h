/*****************************************************************************
Full Name : Matthew Hyland
Student ID# : 035286046
Email : mhyland@myseneca.ca
Section : NAA

Authenticity Declaration :
I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.
*****************************************************************************/
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds { 
	
	

	

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}


#endif
