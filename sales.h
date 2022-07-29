// sales class h file
#ifndef SALES_H
#define SALES_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Sales
{ // define sales class

private:
    string clientName;        // name of product
    string purchaseDescription; // short descript of what the product is
    int purchaseTotal;          // price for one of the product
    
public:
    Sales(); // defaulut constructor
    void PurchaseProduct();         // updates product
    void ViewAllSales();            // creates a new product
    void ViewClientSales(); // lists a specific product's information           // gets product sales
    void UpdateClientSales();          // lists all the products available
    


    ifstream salesFile; // open product file

    ofstream salesWrite; // write to product file

    void SkipLines(ifstream &, int); // method to skip lines in file search 
};

#endif