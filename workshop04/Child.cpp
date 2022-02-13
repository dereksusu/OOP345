#include <iostream>
#include "Child.h"

using namespace std;

namespace sdds
{
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		this->name = name;
		this->age = age;
		this->toys = new const Toy * [count];
		for (int i = 0; i < count; i++)
		{
			this->toys[i] = toys[i];
		}
		this->count = count;
	}

	Child::Child(const Child& rhs)
	{
		this->name = "";
		this->age = 0;
		delete[] this->toys;

		this->name = rhs.name;
		this->age = rhs.age;
		this->toys = new const Toy * [rhs.count];
		for (int i = 0; i < rhs.count; i++)
		{
			this->toys[i] = rhs.toys[i];
		}
		this->count = rhs.count;

	}

	Child& Child::operator= (const Child& rhs)
	{
		if (this != &rhs)
		{
			this->name = "";
			this->age = 0;
			this->toys = nullptr;
			delete[] this->toys;

			this->name = rhs.name;
			this->age = rhs.age;
			this->toys = new const Toy * [rhs.count];
			for (int i = 0; i < rhs.count; i++)
			{
				this->toys[i] = rhs.toys[i];
			}
			this->count = rhs.count;
		}
		return *this;
	}

	Child::Child(Child&& rhs) noexcept
	{
		this->name = rhs.name;
		this->age = rhs.age;
		this->toys = new const Toy * [rhs.count];
		for (int i = 0; i < rhs.count; i++)
		{
			this->toys[i] = rhs.toys[i];
		}
		this->count = rhs.count;
		rhs.name = "";
		rhs.age = 0;
		rhs.count = 0;
		rhs.toys[0] = nullptr;
		delete[] rhs.toys;
	}

	Child& Child::operator= (Child&& rhs) noexcept
	{
		if (this != &rhs) 
		{
			delete[] rhs.toys;
			this->name = rhs.name;
			this->age = rhs.age;
			this->toys = new const Toy * [rhs.count];
			for (int i = 0; i < rhs.count; i++)
			{
				this->toys[i] = rhs.toys[i];
			}
			this->count = rhs.count;

			rhs.name = "";
			rhs.age = 0;
			rhs.count = 0;
			rhs.toys[0] = nullptr;
			delete[] rhs.toys;
		}
		return *this;
	}

	Child::~Child()
	{
		if(count != 0)
			delete[] toys;
	}

	size_t Child::size() const
	{
		return count;
	}

	std::ostream& operator<<(std::ostream& os, const Child& rhs)
	{
		//Child 1: Kyle Patel 8 years old:	
		static int CALL_CNT = 0;
		CALL_CNT++;
		os << "--------------------------" << std::endl;
		os << "Child " << CALL_CNT << ": ";
		os << rhs.name << " ";
		os << rhs.age << " " << "years old:" << std::endl;
		os << "--------------------------" << std::endl;
		if (rhs.count == 0)
		{
			os << "This child has no toys!" << std::endl;
		}
		else
		{
			for (int i = 0; i < rhs.count; i++)
			{
				os << *(rhs.toys[i]);
			}
		}
		return os;
 	}
}