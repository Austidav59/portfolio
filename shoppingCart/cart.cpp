//
//  cart.cpp
//  Week 6 project
//
//  Created by Marisabel Trejo on 6/15/24.
//
// cart.cpp
#include <map>
#include "item.h"
#include "cart.h"
#include <iostream>
#include <string>
#include <algorithm>  // for std::find

Cart::Cart() {};

// cart.cpp
void Cart::initiateProducts()
{
    storeProducts = {
        {"Yogur", Item{"Yogurt", 6.50}},
        {"Apples", Item{"Apples", 3.56}},
        {"Avacados", Item{"Avacados", 8.50}},
        {"Tortillas", Item{"Tortillas", 4.56}},
        {"Pizza", Item{"Pizza", 12.50}},
        {"Bacon", Item{"Bacon", 1.20}}
    };
}

void Cart::addToCart()
{
    std::cout << "Store contents:" << std::endl;
    for (const auto& pair : storeProducts) {
        std::cout << pair.first << ": $" << pair.second.getPrice() << std::endl;
    }

    std::string itemToAdd;
    std::cout << "Enter the item to add to the cart: ";
    std::cin >> itemToAdd;
    if (storeProducts.count(itemToAdd) > 0) {
        cart[itemToAdd] = storeProducts[itemToAdd];
        std::cout << "Item added to the cart." << std::endl;
    } else {
        std::cout << "Item not found in the store." << std::endl;
    }
}

void Cart::removeItemCart()
{
    std::cout << "Cart contents:" << std::endl;
    for (const auto& pair : cart) {
        std::cout << pair.first << ": $" << pair.second.getPrice() << std::endl;
    }

    std::string itemToRemove;
    std::cout << "Enter the item to remove from the cart: ";
    std::cin >> itemToRemove;
    if (cart.count(itemToRemove) > 0) {
        cart.erase(itemToRemove);
        std::cout << "Item removed from the cart." << std::endl;
    } else {
        std::cout << "Item not found in the cart." << std::endl;
    }
}

void Cart::viewCart()
{
    float sum = 0;
    std::cout << "Cart contents:" << std::endl;
    for (const auto& pair : cart) {
        std::cout << pair.first << ": $" << pair.second.getPrice() << std::endl;
        sum += pair.second.getPrice();
    }
    std::cout << "Total: $" << sum << std::endl;
}

float Cart::checkout(bool validOrNot)
{
    float sum = 0;
    for (const auto& pair : cart) {
        sum += pair.second.getPrice();
    }

    if (validOrNot) {
        float total = sum - (sum * 0.1);
        return total;
    } else {
        return sum;
    }
}

int Cart::signUp() {
    int newId = memberIdList.empty() ? 1000 : memberIdList.back() + 1;
    memberIdList.push_back(newId);
    std::cout << "Your new member ID is: " << newId << std::endl;
    return newId;
}

bool Cart::checkValidId() {
    int id;
    std::cout << "Enter your member ID: ";
    std::cin >> id;
    return std::find(memberIdList.begin(), memberIdList.end(), id) != memberIdList.end();
}

// The signUp and checkValidId functions remain unchanged
