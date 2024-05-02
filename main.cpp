#include <iostream>

using namespace std;

int displayMenu();

int main() { 
 
}//end main() 
int displayMenu() {

//I: User inputs number corresponding to the 3 different choices; searchInventory, displaySales, or customerList
//P: Validate input
//O: Output user choice

int userChoice = 0;
   
   cout << "Welcome to the Front Range Community Car Lot Database!" << endl; 
   cout << "| Would you like to search:                          |" << endl;
   cout << "| 1. Inventory                                       |" << endl;
   cout << "| 2. Sales Data                                      |" << endl;
   cout << "| 3. List of Customers                               |" << endl << endl;
   cout << "Enter Choice: ";
   
   cin >> userChoice;
    
   while (userChoice < 1 || userChoice > 3) {
      cout << endl << "Please input a valid number: ";
      cin >> userChoice;
   }//end for
   
   cout << endl;
   return userChoice;
   
}//end displayMenu