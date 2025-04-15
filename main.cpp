/***********************************************************************
// OOP244 Project, Milestone 5
//
// Final Project Milestone 5 - Part 2
// Module: main
// Filename: main.cpp
// Version 1.1
// Author: Karl Shiu, 131531246, bkshiu1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/04/15  Implemented drink ordering loop and submenu flow (MS52)
// 2025/04/15  Fixed indentation problem for ms52
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
***********************************************************************/
#include <iostream>
#include "Menu.h"
#include "Ordering.h"
#include "Utils.h"

using namespace std;
using namespace seneca;

int main() {
    Ordering ordering("drinks.csv", "foods.csv");

    if (!ordering) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }

    bool exit = false;
    while (!exit) {
        Menu mainMenu("Seneca Restaurant", "End Program", 0, 0);
        mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
        size_t mainSel = mainMenu.select();

        switch (mainSel) {
        case 1: {
            bool keepOrdering = true;
            while (keepOrdering) {
                Menu orderMenu("Order Menu", "Back to main menu", 3, 1);
                orderMenu << "Food" << "Drink";
                size_t orderSel = orderMenu.select();

                switch (orderSel) {
                case 1:
                    ordering.orderFood();
                    break;
                case 2:
                    ordering.orderDrink();
                    break;
                case 0:
                    keepOrdering = false;
                    break;
                }
            }
            break;
        }
        case 2:
            ordering.printBill(cout);
            break;
        case 3:
            ordering.resetBill();
            break;
        case 4:
            ordering.listFoods();
            break;
        case 5:
            ordering.listDrinks();
            break;
        case 0:
            if (ordering.hasUnsavedBill()) {
                Menu confirm("You have bills that are not saved. Are you sure you want to exit?", "No", 1, 1);
                confirm << "Yes";
                if (confirm.select() == 1) {
                    exit = true;
                }
            }
            else {
                exit = true;
            }
            break;
        }
    }

    return 0;
}
