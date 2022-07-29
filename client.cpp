//// client class.cpp

#include "client.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

Client::Client() { // client default info
    clientName = "";
    clientAddress = "";
    clientSales = 0;
}

// THIS WORKS!!!
void Client::SetModifyClient() { // method to modify a client
    // open, add what is needed, then close
    string search; // search for this string to update client info          
    ifstream readFile;    // file to open
    ofstream outFile;   // file to be saved 
    string newAddress;                       // new address for client
    string newMoney;                         // new sales for client
    string readLine;         // variable that is checked for client name

    readFile.open("ClientsFile.txt");
    outFile.open("NewClientsFile.txt");
    
    if (readFile.is_open()) {
        cout << "Enter client to modify: (Last, First)\n"; // prompt for name of client to be updated
        getline(cin, search);
        while (getline(readFile, readLine)) {
            if(readLine == search){ // if line matches the client name

                outFile << readLine;
                outFile << endl;

                cout << "Enter new client address: (Numbers Street City/Tx)\n"; // prompt for new address
                getline(cin, newAddress); // address to be updated
                cout << "Enter new client dollar amount: ($xxx,xxx)\n"; // prompt for new client dollar amount
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
    cout << "Client updated!" << endl;
    readFile.close(); // close the read in file
    outFile.close(); // close the outfile   
}



// THIS WORKS!!!
void Client::SetNewClient() { // method to set new client
    ofstream appendFile; // file to add new client to
    string name, address, money; // client fields to add

    appendFile.open("ClientsFile.txt", ios::app); // open file

    if(appendFile.is_open()) { // if file is open

    cout << "Enter name of client to add to file: (Last, First)" << endl; // prompt for appended client name
    getline(cin, name); 

    cout << "Enter address of client to add to file: (Numbers Street City/Tx)" << endl; // prompt for appended client address
    getline(cin, address);

    cout << "Enter dollar amount of client: ($xxx,xxx)" << endl; // prompt for appended client dollar amount
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
    
    
    

// THIS WORKS!!
void Client::GetSpecificClientInfo() { // method to retrieve client info
    // open, read in, return line of specific client info
    ifstream inFile; // file to open
    string searchName; // name of client to search for
    string fileContents; // file contents to compare with seach variable
    string infoHolder; // variable to display address and money

    inFile.open("ClientsFile.txt", ios::out); // open file

    if (inFile.is_open()) { // if file opens successfully
        cout << "Enter name of client whose info should be displayed: (Last, First)\n"; // prompt
        getline(cin, searchName); //input client name to search info on

        while (getline(inFile, fileContents)) { // loops while still data in file

            if (fileContents == searchName) { // if client name matches search name
                cout << fileContents << endl; // output that client's info

                getline(inFile, infoHolder); // grab clients address and sales info and push to console

                cout << infoHolder << endl;

                getline(inFile, infoHolder);

                cout << infoHolder << endl;
                
                }
        }
        inFile.close(); // close file
    }

}



// THIS WORKS!!!
void Client::GetAllClients() { // method to see all clients
    fstream readFile; // file to open
    string display; // variable to feed in file contents
    readFile.open("ClientsFile.txt", ios::in); // open file to read to console

    if (readFile.is_open()) {
        while (getline(readFile, display)) { // loop to display contents of the file
            cout << display << endl;
        }

        readFile.close(); // close the file
    }
    else {
        cout << "File not opened." << endl;
    }
}


// THIS WORKS!!!
void Client::SkipLines(ifstream& fFile, int nLines) { // method to skip lines in file search maneuvering 
    string dummyLine;
    for (int i = 0; i < nLines; ++i) {
        getline(fFile, dummyLine);
    }
} 