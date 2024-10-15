//
//  main.cpp
//  Week 6 project
//
//  Created by Marisabel Trejo on 6/15/24.
//

#include <iostream>
#include <string>
#include <list>
#include "cart.h"
using namespace std;

int main() {
    bool validOrNot = false;
    
    Cart cart1;
    cart1.initiateProducts();
    
    int loop = -1;
    while (loop != 0) {
        cout << "Welcome to the Shopping cart" << endl;
        cout << "1. View Cart" << endl;
        cout << "2. Add Item to cart" << endl;
        cout << "3. Remove item from cart" << endl;
        cout << "4. Enter member Id" << endl;
        cout << "5. Sign up for membership" << endl;
        cout << "6. Checkout" << endl;
        cout << "7. Quit" << endl;
        

        int userInput;
        cout << "Enter Number: ";
        cin.clear();
        cin >> userInput;

        if (userInput == 1) {
            cart1.viewCart();
        } else if (userInput == 2) {
            cart1.addToCart();
        } else if (userInput == 3) {
            cart1.removeItemCart();
        } else if (userInput == 4) {
            validOrNot = cart1.checkValidId();
        } else if (userInput == 5) {
            cart1.signUp();
        } else if (userInput == 6) {
            float total = cart1.checkout(validOrNot);
            cout << "Total $" << total <<endl;
        } else if (userInput == 7) {
            loop = 0;
        } else {
            cout << "Invalid Entry Try Again" << endl;
        }
    }
    return 0;
}
