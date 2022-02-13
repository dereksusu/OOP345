#include "ConfirmOrder.h"

namespace sdds
{
    ConfirmOrder::ConfirmOrder() {
        this->toys = nullptr;
        this->count = 0;
    }
    ConfirmOrder::ConfirmOrder(ConfirmOrder& rhs) {
        this->toys = rhs.toys;
        this->count = rhs.count;
    }
    ConfirmOrder::ConfirmOrder(ConfirmOrder&& rhs) {
        *this = std::move(rhs);
    }
    ConfirmOrder::~ConfirmOrder() {
        if (toys) {
            delete[] toys;
            toys = nullptr;
        }
    }
    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& rhs) {
        this->toys = new const Toy * [rhs.count];
        for (int i = 0; i < rhs.count; i++) {
            this->toys[i] = rhs.toys[i];
        }
        this->count = rhs.count;

        return *this;
    }
    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& rhs) {
        if (this != &rhs) {
            this->toys = std::move(rhs.toys);
            this->count = std::move(rhs.count);

            rhs.toys = nullptr;
            rhs.count = 0;
        }

        return *this;
    }
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        bool hasToy = false;
        const Toy** newToys;
        for (int i = 0; i < this->count; i++) {
            if (this->toys[i] == &toy)
                hasToy = true;
        }
        if (!hasToy) {
            newToys = new const Toy * [this->count + 1];
            for (int i = 0; i < this->count; i++) {
                newToys[i] = this->toys[i];
            }
            newToys[this->count] = &toy;
            this->count++;
            delete[] this->toys;
            this->toys = newToys;
        }

        return *this;
    }
    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        bool hasToy = false;
        int iFoundedToy = -1;
        int index = 0;
        const Toy** newToys;
        for (int i = 0; i < this->count; i++) {
            if (this->toys[i] == &toy) {
                hasToy = true;
                iFoundedToy = i;
            }
        }
        if (hasToy) {
            newToys = new const Toy * [this->count - 1];
            for (int i = 0; i < this->count; i++) {
                if (i == iFoundedToy) continue;
                newToys[index++] = this->toys[i];
            }
            delete[] this->toys;
            this->count--;
            this->toys = newToys;
        }

        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const sdds::ConfirmOrder& rhs) {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;

        if (rhs.count == 0) {
            os << "There are no confirmations to send!" << std::endl;
        }
        else {
            for (int i = 0; i < rhs.count; i++) {
                os << *(rhs.toys[i]);
            }
        }

        os << "--------------------------" << std::endl;

        return os;
    }
}