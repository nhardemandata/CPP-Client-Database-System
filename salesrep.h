// SalesRep class
#ifndef SALESREP_H
#define SALESREP_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class SalesRep { // define salesrep class
    private:
        string srName; // name of sales rep
        string srAddress; // address of sales rep
        int srSales; // sales rep sales to date
        double srBonus;// sales rep bonus based upon calculation

    public:
        SalesRep(); // default constructor
        void SetModifySalesRep(); // method to modify sales rep info --- WORKS!!!
        void SetNewSalesRep(); // method to set new sales rep --- WORKS!!!
        void GetSpecificSalesRepInfo(); // method to get info on sales rep --- WORKS!!!
        void GetAllSalesReps(); // method to return all sales reps info --- WORKS!!!
        void SalesRepBonus(); // method to calculate sales rep bonus --- WORKS!!!

        void SkipLines(ifstream&, int); // method to skip lines in file search --- WORKS!!!

};

#endif