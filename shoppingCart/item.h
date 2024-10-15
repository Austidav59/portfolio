//
//  item.h
//  shoppingCart
//
//  Created by Austin Davis on 10/14/24.
//
// item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    float price;

public:
    Item() : name(""), price(0.0f) {}  // Add this default constructor
    Item(std::string name, float price);
    std::string getName() const;
    float getPrice() const;
    void setName(const std::string& newName);
    void setPrice(float newPrice);
};

#endif // ITEM_H
