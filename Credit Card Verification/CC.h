/*****************************************************************************
Full Name  : Matthew Hyland
Student ID#: 035286046
Email      : mhyland@myseneca.ca
Section    : NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_CC_H
#define SDDS_CC_H

namespace sdds {

	

	class CC {
	private:
		char* m_name{};
		unsigned long long m_cardNum{};
		short m_cvv{};
		short m_expMon{};
		short m_expYear{};
		bool validate(const char* name,
			unsigned long long cardNo,
			short cvv,
			short expMon,
			short expYear)const;
		void prnNumber()const;
	public:
		void set();
		void cleanUp();
		bool isEmpty() const;
		void set(const char* cc_name,
			unsigned long long cc_no,
			short cvv,
			short expMon,
			short expYear);
		bool read();
		void display(int row = 0) const;
	};

	

}

#endif