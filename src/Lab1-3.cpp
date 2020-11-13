//============================================================================
// Name        : Lab1-3.cpp
// Author      : Devon Darling
// Version     :
// Course      : CS-260-J3682
// Date        : 01-12-2020
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Define a data structure to hold bid information together as a single unit of storage.
struct Bid{
	string title;
	string fund;
	string vehicleId;
	double bidAmount;
};
// Declare strToDouble
double strToDouble(string str, char ch);

// Display the bid values passed in data structure
/**
 * Display the bid information
 *
 * @param Bid data structure containing the bid info
 */
void displayBid(Bid bid) {
    cout << "Title: " << bid.title << endl;
    cout << "Fund: " << bid.fund << endl;
    cout << "Vehicle: " << bid.vehicleId << endl;
    cout << "Bid Amount: " << bid.bidAmount << endl;

    return;
}

// Store input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
Bid getBid() {
//Declare instance of data structure to hold bid information
    Bid bid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, bid.vehicleId);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.bidAmount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

    // Declare instance of data structure to hold bid information
	Bid bid;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // Complete the method calls then test the program
        switch (choice) {
            case 1:
            	bid = getBid();
                break;
            case 2:
                displayBid(bid);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}

