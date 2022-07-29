// product class h file
#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Product
{ // define client class

private:
    string productName;        // name of product
    string productDescription; // short descript of what the product is
    int productPrice;          // price for 1 of the product
    int productQuantity;       // amount of product available
public:
    Product(); // defaulut constructor
    void SetUpdateProduct();         // updates product
    void SetNewProduct();            // creates a new product
    void GetSpecificProductInfo(); // lists a specific product's information
    void GetAllProduct();          // lists all the products available
    void MonthlySalesReport(); // monthly sales report

    ifstream productsFile; // open product file
    ofstream productsWrite; // write to product file


    void SkipLines(ifstream &, int); // method to skip lines in file search --- WORKS!!!
};

#endif

