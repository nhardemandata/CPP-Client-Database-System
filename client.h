// client class
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Client { // define client class

    private:
        string clientName; // name of client
        string clientAddress; // address of client
        int clientSales; // client sales to date

    public:
        Client(); // defaulut constructor
        void SetModifyClient(); // method to modify client info --- WORKS!!!
        void SetNewClient(); // method to set new client --- WORKS!!!
        void GetSpecificClientInfo(); // method to get info on client ---WORKS!!!
        void GetAllClients(); // method to get all client's info --- WORKS!!!

        
        ifstream ClientFile; // open client file
        ofstream ClientWrtie; // write to client file 



        
        void SkipLines(ifstream&, int); // method to skip lines in file search --- WORKS!!!
};

#endif

