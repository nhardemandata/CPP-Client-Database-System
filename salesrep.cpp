// sales rep class.cpp

#include "salesrep.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

SalesRep::SalesRep() { // sales rep default info
    srName = "";
    srAddress = "";
    srSales = 0;
}

// THIS WORKS!!!
void SalesRep::SetModifySalesRep(){ // method to modify a sales rep
    // open, add what is needed, then close
    string search; // search for this string to update sales rep info        
    ifstream readFile;    // file to open
    ofstream outFile;   // file to be saved
    string newAddress;                       // new address for sales rep
    string newMoney;                         // new sales for sales rep
    string readLine;         // variable that is checked for sales rep name

    readFile.open("SalesRepFile.txt"); // open file
    outFile.open("NewSalesRepFile.txt"); // file with updated sales rep info
    
    if (readFile.is_open()) { // if open success
        cout << "Enter sales rep to modify: (Last, First)\n"; // prompt for name of sales rep to be updated
        getline(cin, search); // get user input
        while (getline(readFile, readLine)) { // while data in file from line to read in is still there
            if(readLine == search){ // if file contents match the search criteria

                outFile << readLine;
                outFile << endl;

                cout << "Enter new sales rep address: (Numbers Street City/Tx)\n"; // prompt for new address
                getline(cin, newAddress); // address to be updated
                cout << "Enter new sales rep dollar amount: ($xxx,xxx)\n"; // prompt for new sales rep dollar amount
                getline(cin, newMoney); // dollar amount to be updated

                outFile << newAddress << endl; // adding new address to file
                outFile << newMoney << endl; // adding new dollar amount to file

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
    cout << "Sales rep updated!" << endl; // confirmation of update 
    readFile.close(); // close the read in file
    outFile.close(); // close the outfile 
}



// THIS WORKS!!!
void SalesRep::SetNewSalesRep() { // method to add a new sales rep
    ofstream appendFile; // file to add new sales rep to
    string name, address, money; // sales rep fields to add

    appendFile.open("SalesRepFile.txt", ios::app); // open and read from file

    if(appendFile.is_open()) { // if open a success 

    cout << "Enter name of sales rep to add to file: (Last, First)" << endl; // prompt for appended sales rep name
    getline(cin, name); 

    cout << "Enter address of sales rep to add to file: (Numbers Street City/Tx)" << endl; // prompt for appended sales rep address
    getline(cin, address);

    cout << "Enter dollar amount of sales rep: ($xxx,xxx)" << endl; // prompt for appended sales rep dollar amount
    getline(cin, money);

    appendFile << endl << endl << name << endl; // add name to file
    appendFile << address << endl; // add address to file
    appendFile << money; // add money amount to file

    cout << "Done!" << endl; // finish prompt

    appendFile.close(); // close the file
    }
    else {
        cout << "File not opened." << endl; // file open failure
    }
}


// THIS WORKS!!!
void SalesRep::GetSpecificSalesRepInfo() { // method to get specific sales rep information
    // open, read in, return line of specific sales rep info
    ifstream inFile; // file to open
    string searchName; // name of client to search for
    string fileContents; // file contents to compare with seach variable
    string infoHolder; // variable to display address and money

    inFile.open("SalesRepFile.txt", ios::out); // open file

    if (inFile.is_open()) { // if file opens successfully
        cout << "Enter name of sale rep whose info should be displayed: (Last, First)\n"; // prompt
        getline(cin, searchName); //input client name to search info on

        while (getline(inFile, fileContents)) { // as long as there is still data in file to read in

            if (fileContents == searchName) { // if file contents match the search criteria
                cout << fileContents << endl;

                getline(inFile, infoHolder); // get and output the address and money information

                cout << infoHolder << endl;

                getline(inFile, infoHolder);

                cout << infoHolder << endl;

                infoHolder.erase(remove(infoHolder.begin(), infoHolder.end(), '$'), infoHolder.end()); // remove $ from string
                infoHolder.erase(remove(infoHolder.begin(), infoHolder.end(), ','), infoHolder.end()); // remove comma from string

                int monthlySales = stoi(infoHolder); // convert string to int
                double avgMonthlySales = (static_cast<double> (monthlySales) / 12.00); // find average monthly sales

                cout << fixed << setprecision(2); // two decimal places
                cout << "Average monthly sales: $" << avgMonthlySales  << endl; // output average monthly sales

                
                }
        }
        inFile.close(); // close file
    }

}


// THIS WORKS!!!
void SalesRep::GetAllSalesReps() { //method to get all sales reps
    fstream readFile; // file to open
    string display; // variable to feed in file contents
    readFile.open("SalesRepFile.txt", ios::in); // open file to read to console

    if (readFile.is_open()) { // if file is open
        while (getline(readFile, display)) { // loop to display contents of the file
            cout << display << endl; // output the line read in
        }

        readFile.close(); // close the file
    }
    else {
        cout << "File not opened." << endl; // file open failure
    }
}

// THIS WORKS!!!
void SalesRep::SalesRepBonus(){ // method to see specific sales rep bonus
    ifstream inFile; // file to open
    string searchName; // name of sales rep to search for
    string fileContents; // file contents to compare with seach variable

    inFile.open("SalesRepFile.txt", ios::out); // open file

    if (inFile.is_open()) { // if file opens successfully
        cout << "Enter name of sale rep whose bonus should be displayed: (Last, First)\n"; // prompt
        getline(cin, searchName); //input sales rep name to get their bonus

        while (getline(inFile, fileContents)) { // while reading in data from file

            if (fileContents == searchName) { // if read in line matches search criteria
                cout << fileContents << endl; // output sales rep name 

                SkipLines(inFile, 1); // skip the line with address info

                getline(inFile, fileContents); // grab the sales rep sales

                cout << "Total sales: " << fileContents << endl; // output total sales

                fileContents.erase(remove(fileContents.begin(), fileContents.end(), '$'), fileContents.end()); // remove $ from string
                fileContents.erase(remove(fileContents.begin(), fileContents.end(), ','), fileContents.end()); // remove comma from string

                int bonus = stoi(fileContents); // convert string to int
                double salesBonus = (static_cast<double> (bonus) * 0.08); // find average monthly sales

                srBonus = salesBonus; // assign sales bonus
                cout << fixed << setprecision(2); // two decimal places
                cout << "8 percent sales commision bonus: $" << salesBonus  << endl; // output average monthly sales

                
                }
        }
        inFile.close(); // close file
    }

}

// THIS WORKS!!!
void SalesRep::SkipLines(ifstream& fFile, int nLines) { // method to skip lines in file search maneuvering 
    string dummyLine;
    for (int i = 0; i < nLines; ++i) {
        getline(fFile, dummyLine);
    }
} 