/*****************************************************************************
Full Name : Matthew Hyland
Student ID# : 035286046
Email : mhyland@myseneca.ca
Section : NAA

Authenticity Declaration :
I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.
*****************************************************************************/
#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H



namespace sdds {

	const int MAX_TITLE_LENGTH = 50;
	const int MAX_QUANTITY_VALUE = 50;

	struct ShoppingRec
	{
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};
	


	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);

}

#endif
