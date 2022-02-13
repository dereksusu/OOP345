#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include "Toy.h"

namespace sdds
{
	class Child
	{
	private:
		const sdds::Toy** toys;
		std::string name;
		int age;
		size_t count;

	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& rhs);
		Child(Child&& rhs) noexcept;
		~Child();
		Child& operator= (const Child& rhs);
		Child& operator= (Child&& rhs) noexcept;
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& rhs);
	};
}

#endif // !SDDS_CHILD_H
