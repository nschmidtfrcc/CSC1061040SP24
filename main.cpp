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

   cout << "Would you like to search inventory(1), display sales data(2), or access a list of customers(3): ";
   cin >> userChoice;
    
   if (userChoice < 1 || userChoice  > 3) {
      cout << endl << "Please input a valid number" << endl;
   }else{
       
   }//end if-else
   return userChoice;
}//end displayMenu