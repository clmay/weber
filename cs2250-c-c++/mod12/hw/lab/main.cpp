/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2019 03:50:58 PM
 *       Revision:  none
 *       Compiler (C):    gcc main.cpp -o main.out -lm
 *       Compiler (C++):  g++ main.cpp ItemToPurchase.cpp ShoppingCart.cpp -o main.out 
 *          Usage:  ./main.out 
 *
 *         Author:  Hugo Valle (), hugovalle1@weber.edu
 *   Organization:  WSU
 *
 * =====================================================================================
 */

#include <iostream>
#include <iomanip>
#include "ShoppingCart.h"
using namespace std;

// Function Prototypes
char PrintMenu(ShoppingCart& theCart);

// Main Function
int main() 
{
    string custName;
    string today;
    char menuChoice;

    cout << "Enter customer's name:" << endl;
    getline(cin, custName);

    cout << "Enter today's date:" << endl;
    getline(cin, today);
    cout << endl;

    cout << "Customer name: " << custName << endl;
    cout << "Today's date: " << today << endl << endl;

    ShoppingCart myCart(custName, today);

    menuChoice = ' ';

    while(menuChoice != 'q') {
        menuChoice = PrintMenu(myCart);
    }

    return 0;
}

// Function Definitions
char PrintMenu(ShoppingCart& theCart)
{
    char menuOp;
    string name;
    string descr;
    int price;
    int quantity;

    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;

    menuOp = ' ';

    while (menuOp != 'a' && menuOp != 'd' && menuOp != 'c' &&
            menuOp != 'i' && menuOp != 'o' && menuOp != 'q') 
    {
        cout << "Choose an option:" << endl;
        cin >> menuOp;
    }

    // Switch statement on menuOp
    switch(menuOp) 
    {
        case 'a':
            {
                cin.ignore();
                cout << "ADD ITEM TO CART" << endl;
                cout << "Enter the item name:" << endl;
                getline(cin, name);
                cout << "Enter the item description:" << endl;
                getline(cin, descr);
                cout << "Enter the item price:" << endl;
                cin >> price;
                cout << "Enter the item quantity:" << endl;
                cin >> quantity;
                cout << endl;
                ItemToPurchase newItem = ItemToPurchase(name, descr, price, quantity);
                theCart.AddItem(newItem);
                break;
            }
        case 'd':
            cin.ignore();
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, name);
            theCart.RemoveItem(name);
            cout << endl;
            break;
        case 'c':
            {
                cin.ignore();
                cout << "CHANGE ITEM QUANTITY" << endl;
                cout << "Enter the item name:" << endl;
                getline(cin, name);
                cout << "Enter the new quantity:" << endl;
                cin >> quantity;
                ItemToPurchase changedItem = ItemToPurchase(name, "none", 0, quantity);
                theCart.ModifyItem(changedItem);
                cout << endl;
                break;
            }
        case 'i':
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            theCart.PrintDescriptions();
            menuOp = ' ';
            cout << endl;
            break;
        case 'o':
            cout << "OUTPUT SHOPPING CART" << endl; 
            theCart.PrintTotal();
            menuOp = ' ';
            cout << endl;
            break;
    }
    return menuOp;
}