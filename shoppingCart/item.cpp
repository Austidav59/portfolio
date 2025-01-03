
#include "item.h"

Item::Item(std::string name, float price) : name(name), price(price) {}

std::string Item::getName() const {
    return name;
}

float Item::getPrice() const {
    return price;
}

void Item::setName(const std::string& newName) {
    name = newName;
}

void Item::setPrice(float newPrice) {
    price = newPrice;
}
