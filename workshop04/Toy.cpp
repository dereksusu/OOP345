#include <iostream>
#include <sstream>
#include "Toy.h"



namespace sdds
{
	void Toy::trimSpace(std::string* tokenized)
	{
		std::string space = " ";
		size_t pos = 0;
		while (tokenized->at(pos) == ' ')
		{
			pos = tokenized->find(space, pos);
			tokenized->erase(pos, 1);
		}
		pos = tokenized->length() - 1;
		while (tokenized->at(pos) == ' ')
		{
			pos = tokenized->find(space, pos);
			tokenized->erase(pos, 1);
			pos = tokenized->length() - 1;
		}
	}

	Toy::Toy() 
	{
		fieldLength[0] = '\0';
		orderID = 0;
		noOfItems = 0;
		name = "";
		price = 0;
		tax = 0;
	}


	Toy::Toy(const std::string& toy)
	{

		std::stringstream ss(toy);
		std::string tokenized[4];
		int index = 0;
		while (index < 4)
		{
			std::getline(ss, tokenized[index], ':');
			trimSpace(&tokenized[index++]);
		}

		this->orderID = std::stoi(tokenized[0]);
		this->name = tokenized[1];
		this->noOfItems = std::stoi(tokenized[2]);
		this->price = std::stof(tokenized[3]);
		this->tax = (float)(this->price * this->noOfItems) * tax_rate;

		fieldLength[FIELD::ID] = 8;
		fieldLength[FIELD::NAME] = 18;
		fieldLength[FIELD::NUM] = 3;
		fieldLength[FIELD::PRICE] = 8;
		fieldLength[FIELD::SUBTOTAL] = 7;
		fieldLength[FIELD::TAX] = 6;
		fieldLength[FIELD::TOTAL] = 7;
	}

	Toy::~Toy() 
	{}

	void Toy::update(int numItems)
	{
		this->noOfItems = numItems;
		this->tax = (float)(this->price * this->noOfItems) * tax_rate;
	}

	std::string getRemainSpace(int printedLength, int totalLength)
	{
		std::string res = "";
		for (int i = 0; i < totalLength - printedLength; i++)
			res += " ";

		return res;
	}

	ostream& operator<<(ostream& os, const Toy& rhs)
	{
		 float subTotal, total;
		 subTotal = (float)(rhs.noOfItems) * rhs.price;
		 total = subTotal + rhs.tax;
		 os << "Toy";
		 os << getRemainSpace(
			 std::to_string(rhs.orderID).length(), 
			 rhs.fieldLength[Toy::FIELD::ID]) 
			 << rhs.orderID << ":";

		 os << getRemainSpace(
			 rhs.name.length(), 
			 rhs.fieldLength[Toy::FIELD::NAME]) << rhs.name;

		 os << getRemainSpace(
			 std::to_string(rhs.noOfItems).length(), 
			 rhs.fieldLength[Toy::FIELD::NUM])
			 << rhs.noOfItems;

		 os << "items";
		 os << getRemainSpace(
			 std::to_string(((int)round(rhs.price * 100))).length() + 1,
			 rhs.fieldLength[Toy::FIELD::PRICE]);
		 os.setf(std::ios::fixed);
		 os.precision(2);
		 os << round(rhs.price * 100) / 100;
		 os.unsetf(std::ios::fixed);

		 os << "/item subtotal:";
		 os << getRemainSpace(
			 std::to_string(((int)round(subTotal * 100))).length(),
			 rhs.fieldLength[Toy::FIELD::SUBTOTAL]);
		 os.setf(std::ios::fixed);
		 os.precision(2);
		 os << round(subTotal * 100) / 100;
		 os.unsetf(std::ios::fixed);

		 os << "tax:";
		 os << getRemainSpace(
			 std::to_string(((int)round(rhs.tax * 100))).length() + 1,
			 rhs.fieldLength[Toy::FIELD::TAX]);
		 os.setf(std::ios::fixed);
		 os.precision(2);
		 os << round(rhs.tax * 100) / 100;
		 os.unsetf(std::ios::fixed);

		 os << "total:";
		 os << getRemainSpace(
			 std::to_string((int)round(total * 100) / 100).length(),
			 rhs.fieldLength[Toy::FIELD::TOTAL]);
		 os.setf(std::ios::fixed);
		 os.precision(2);
		 os << round(total * 100) / 100;
		 os.unsetf(std::ios::fixed);

		 os << endl;

		 return os;
	}
}