#pragma once
#include "Toy.h"
namespace sdds
{
    class ConfirmOrder
    {
    public:
        ConfirmOrder();
        ConfirmOrder(ConfirmOrder& rhs);
        ConfirmOrder(ConfirmOrder&& rhs);
        ~ConfirmOrder();
        ConfirmOrder& operator=(const ConfirmOrder& rhs);
        ConfirmOrder& operator=(ConfirmOrder&& rhs);
        ConfirmOrder& operator+=(const Toy& toy);
        ConfirmOrder& operator-=(const Toy& toy);
        friend std::ostream& operator<<(std::ostream& os, const sdds::ConfirmOrder& rhs);
    private:
        const sdds::Toy** toys;
        size_t count = 0;
    };
}