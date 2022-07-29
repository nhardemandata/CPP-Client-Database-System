// MAIN PROPGRAM

#include "client.h" // include appropriate .h files
#include "salesrep.h"
#include "product.h"
#include "sales.h"

#include <iostream> // include appropriate libraries
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std; // standard namespace

int main() {

    Client alpha; // client class object
    SalesRep beta; // sales rep class object
    Product gamma; // product class object
    Sales delta; // sales class object
    int index; // index to traverse main menu
    int subIndex; // index to traverse sub menu

    cout << "Welcome to Wedling Central; we are happy you are here!" << endl; // greeting
    cout << "Please select which department you would like to enter:" << endl; // orientation
    cout << "Clients (Enter: 1)" << endl; // directories
    cout << "Sales reps (Enter: 2)" << endl;
    cout << "Products (Enter: 3)" << endl;
    cout << "Sales (Enter: 4)" << endl;
    cout << "Quit (Enter: 10)" << endl; // option to exit
    cin >> index; // user input index for main menu
    cin.ignore(); // ignore cin after index input

    while (index != 10) { // while user does not wish to exit program

    switch(index) {
        case 1: // client department

        while (subIndex != 10){ // while user does not wish to return to main menu

            cout << "What would you like to do?" << endl; // prompt
            cout << "Modify client (Enter: 1)" << endl; // options
            cout << "Add new client (Enter: 2)" << endl;
            cout << "Get a client's info (Enter: 3)" << endl;
            cout << "View clients (Enter: 4)" << endl;
            cout << "Go back to main menu (Enter: 10)" << endl; // return to main menu

            cin >> subIndex; // user input for sub menu
            cin.ignore(); // ignore cin after sub index input
            

            switch(subIndex) { // options within department
                case 1:

                    alpha.SetModifyClient(); // update a client
                    
                    break; // return to sub menu

                case 2:

                    alpha.SetNewClient(); // add new client

                    break; // return to sub menu

                case 3:

                    alpha.GetSpecificClientInfo(); // view specific client's information

                    break; // return to sub menu

                case 4:

                    alpha.GetAllClients(); // view all clients

                    break; // return to sub menu

            }
        }

            break; // return to main menu

        case 2:

        while (subIndex != 10){ // while user does not wish to return to main menu

            cout << "What would you like to do?" << endl; // prompt
            cout << "Modify sales rep (Enter: 1)" << endl; // options
            cout << "Add new sales rep (Enter: 2)" << endl;
            cout << "Get a sales rep's info (Enter: 3)" << endl;
            cout << "View sales reps (Enter: 4)" << endl;
            cout << "View a sales rep's bonus (Enter: 5)" << endl;
            cout << "Go back to main menu (Enter: 10)" << endl;

            cin >> subIndex; // user input for sub menu
            cin.ignore(); // ignore cin after sub index input

            switch(subIndex) { // options within department
                case 1:

                    beta.SetModifySalesRep(); // update a sales rep

                    break; // return to sub menu 

                case 2:

                    beta.SetNewSalesRep(); // add new sales rep

                    break; // return to sub menu

                case 3:

                    beta.GetSpecificSalesRepInfo(); // view specific sales rep's information

                    break; // return to sub menu

                case 4:

                    beta.GetAllSalesReps(); // view all sales reps

                    break; // return to sub menu

                case 5:

                    beta.SalesRepBonus(); // view a sales rep's bonus

                    break; // return to sub menu

            }
        }

            break; // return to main menu

        case 3:

        while (subIndex != 10) // while user does not wish to return to main menu
        {
            cout << "What would you like to do?" << endl; // prompt
            cout << "Modify product (Enter: 1)" << endl; // options
            cout << "Add new product (Enter: 2)" << endl;
            cout << "Get a product's info (Enter: 3)" << endl;
            cout << "View products (Enter: 4)" << endl;
            cout << "View product sales (Enter: 5)" << endl;
            cout << "Go back to main menu (Enter: 10)" << endl;

            cin >> subIndex; // user input for sub menu
            cin.ignore(); // ignore cin after sub index input

            switch (subIndex)
            {
            case 1:

                gamma.SetUpdateProduct(); // update product's information

                break; // return to sub menu

            case 2:

                gamma.SetNewProduct(); // add new product

                break; // return to sub menu 

            case 3:

                gamma.GetSpecificProductInfo(); // view specific product's informatioin

                break; // return to sub menu

            case 4:

                gamma.GetAllProduct(); // view all products

                break; // return to sub menu
            
            case 5:

                gamma.MonthlySalesReport(); // view monthly sales report

                break; // return to sub menu

            }
        }    

            break; // return to main menu

        case 4:

        while (subIndex != 10) // while user does not return to main menu
        {
            cout << "What would you like to do?" << endl; // prompt
            cout << "Purchase a product (Enter: 1)" << endl; // options
            cout << "View sales for the year (Enter: 2)" << endl;
            cout << "View sales for a specific client (Enter: 3)" << endl;
            cout << "Update client's sale (Enter: 4)" << endl;
            cout << "Go back to main menu (Enter: 10)" << endl;
            
            cin >> subIndex; // user input for sub menu
            cin.ignore(); // ignore cin after sub index input

            switch (subIndex)
            {
            case 1:

                delta.PurchaseProduct(); // purchase a product

                break; // return to sub menu
                
            case 2:

                delta.ViewAllSales(); // view sales

                break; // return to sub menu
            
            case 3:

                delta.ViewClientSales(); // view specific client sales

                break; // return to sub menu
            
            case 4:

                delta.UpdateClientSales(); // update client sales

                break; // return to sub menu

            }
        }

        break; // return to main menu
        
    }

    subIndex = int(); // reset sub index variable

    cout << "What is next?" << endl; // main menu return greeting
    cout << "Please select which department you would like to enter:" << endl; // department orientation
    cout << "Clients (Enter: 1)" << endl; // options
    cout << "Sales reps (Enter: 2)" << endl;
    cout << "Products (Enter: 3)" << endl;
    cout << "Sales (Enter: 4)" << endl;
    cout << "Quit (Enter: 10)" << endl; // exit index

    cin >> index; // user input
    cin.ignore(); // ignore cin after index input

    }

    cout << "Have a good day - thanks for stopping by Welding Central!" << endl; // farewell prompt

    return 0; // end main
}

