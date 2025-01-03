
#ifndef CART_H
#define CART_H

#include <map>
#include <list>
#include <string>
#include "item.h"

class Cart {
private:
    std::map<std::string, Item> storeProducts;
    std::map<std::string, Item> cart;
    std::list<int> memberIdList;
    
public:
    Cart();
    void initiateProducts();
    void addToCart();
    void removeItemCart();
    void viewCart();
    float checkout(bool);
    int signUp();
    bool checkValidId();
};

#endif /* cart_h */
