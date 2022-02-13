#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
	class Toy
	{
	public:
		typedef enum
		{
			ID,
			NAME,
			NUM,
			PRICE,
			SUBTOTAL,
			TAX,
			TOTAL,
			LAST
		} FIELD;
		int fieldLength[FIELD::LAST];
		int orderID;
		int noOfItems;
		string name;
		float price;
		float tax;
		const float tax_rate = 0.13f;

	private: 
		void trimSpace(std::string* tokenized);

	public:
		Toy();
		Toy(const std::string& toy);
		~Toy();
		void update(int numItems);
		friend ostream& operator<<(ostream& os, const Toy& rhs);
	};
}

#endif // !SDDS_TOY_H
