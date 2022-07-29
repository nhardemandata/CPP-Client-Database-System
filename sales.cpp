//// sales class.cpp

#include "sales.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

Sales::Sales() { // default sales info 
    clientName = "";
    purchaseDescription = "";
    purchaseTotal = 0;
    
}

// THIS WORKS!!!
void Sales::UpdateClientSales() { // method to update sales
    // open, add what is needed, then close
    string search; // search for this string to update client info        
    ifstream readFile;    // file to open
    ofstream outFile;   // file to be saved 
    
    string newDescription;       // new price for product
    string newTotal;             // new quantity for product
    string readLine;         // variable that is checked for client name

    readFile.open("salesFile.txt"); // open sales file
    outFile.open("NewSalesFile.txt"); // open updated sales file
    
    if (readFile.is_open()) { // if file open successful 
        cout << "Enter client name to modify that client's purchases: (last, first)\n"; // prompt for name of product to be updated
        getline(cin, search);
        while (getline(readFile, readLine)) { // while unread data remains in file
            if(readLine == search){ // if data matches search

                outFile << readLine;
                outFile << endl;

                cout << "Enter new products client purchased: (quantity of product(s) and product name(s))\n"; // prompt for new description
                getline(cin, newDescription); // description to be updated
                cout << "Enter new purchase total: ($x)\n"; // prompt for new price amount
                getline(cin, newTotal); // price amount to be updated
                
                

                outFile << newDescription << endl; // adding new description to file
                outFile << newTotal << endl; // adding new price amount to file
               
                outFile << endl;

                SkipLines(readFile, 2); // skip the lines with the outdated data

            }
            else {
                outFile << readLine << endl; // read next line if no match made
            }

        }
    }
    else {
        cout << "File not opened." << endl; // file failed to open
    }
    cout << "Sales updated!" << endl;
    readFile.close(); // close the read in file
    outFile.close(); // close the outfile      --- do I need this??
}



void Sales::PurchaseProduct() { //method to purchase a product
    ofstream appendFile; // file to add new product to
    string name, description, total; // client fields to add

    appendFile.open("salesFile.txt", ios::app);

    if(appendFile.is_open()) {

    cout << "Enter name of client to create purchase: (last, first)" << endl; // prompt for appended product name
    getline(cin, name); 

    cout << "Enter items client purchased to add to file: (quantity of product(s) and product(s) name(s))" << endl; // prompt for appended client address
    getline(cin, description);

    cout << "Enter total of purchase: ($x)" << endl; // prompt for appended product dollar amount
    getline(cin, total);


    appendFile << endl << endl << name << endl; // add name to file
    appendFile << description << endl; // add description to file
    appendFile << total << endl; // add price amount to file


    cout << "Done!" << endl; // finish prompt

    appendFile.close(); // close the file
    }
    else {
        cout << "File not opened." << endl; // file open failure
    }
}
    
    
    

// THIS WORKS!!
void Sales::ViewClientSales() { //method to view a client's sales
    // open, read in, return line of specific client info
    ifstream inFile; // file to open
    string searchName; // name of product to search for
    string fileContents; // file contents to compare with seach variable
    string infoHolder; // variable to display address and money

    inFile.open("salesFile.txt", ios::out); // open file

    if (inFile.is_open()) { // if file opens successfully
        cout << "Enter name of client whose purchase info should be displayed: (last, first)\n"; // prompt
        getline(cin, searchName); //input product name to search info on

        while (getline(inFile, fileContents)) { // grabe data from file

            if (fileContents == searchName) { // compare data with search
                cout << fileContents << endl;

                getline(inFile, infoHolder);

                cout << infoHolder << endl;

                getline(inFile, infoHolder);

                cout << infoHolder << endl;
                
                }
        }
        inFile.close(); // close file
    }

}



// THIS WORKS!!!
void Sales::ViewAllSales() { //method to view all sales
    fstream readFile; // file to open
    string display; // variable to feed in file contents
    readFile.open("salesFile.txt", ios::in); // open file to read to console

    if (readFile.is_open()) {
        while (getline(readFile, display)) { // loop to display contents of the file
            cout << display << endl;
        }

        readFile.close(); // close the file
    }
    else {
        cout << "File not opened." << endl; // file open failure 
    }
}



void Sales::SkipLines(ifstream& fFile, int nLines) { // method to skip lines in file search maneuvering 
    string dummyLine;
    for (int i = 0; i < nLines; ++i) {
        getline(fFile, dummyLine);
    }
} 