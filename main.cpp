#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Customer.h"
using namespace std;

int displayMenu();


void DisplaySales(int salesDay, int salesWeek, int salesMonth);


//Input: Vehicle and custmer data read from file. User input to navigate menus to search. MD
//Process: Files are read and vectors of vehicles and customers are made. The user navitages menus to search for vehicles and customers based on specific data values. Sales data can also be searched. MD
//Output: The program outputs the result of the user's search. MD
int main() {
   //Declarations.(MH)
   vector<Vehicle> Vehicles;
   vector<Customer> Customers;
   int salesDay = 17625;
   int salesWeek = 70500;
   int salesMonth = 282000;
   int optionNum = 0;
   int count;
   
   //Gets the data need for the other functions called.(Mh)
   readfiles();//Please add the names of the two files please.(Marco Hosendove)
   
   CalculateSales(Vehicles);//Unsure wether or not theres going be three different Calculate sales function 1 for days, 1 for week, and 1 for months.Marco Hosendove
   
   //Calls DisplayMenu() to run through the different options through the system.(MH)
   optionNum = DisplayMenu();
   switch(optionNum){
      case 1:
         DisplaySales(salesDay,salesWeek,salesMonth);//Displays the Sales
         break;
      case 2:
         SearchVechiles(Vechiles);//Searches the vechiles vector by a spefic criteria and displays the appropriate vechile(s).(MH)
         break;
      case 3:
         //Displays all the customers.(MH)
         for(count = 0; count <= Customers.size();++i){
            DisplayCustomer();
         }//End of for().(MH)
         break;
      default:
         cout << "That is not a option in the system." << endl;
   }//End of swtich().(MH)
    int salesDay, salesWeek, salesMonth = 0;
    DisplaySales(salesDay, salesWeek, salesMonth);

  
}//end main

void DisplaySales(int salesDay, int salesWeek, int salesMonth) {
    cout << "Sales today: $" << salesDay << endl;
    cout << "Sales this week: $" << salesWeek << endl;
    cout << "Sales this month: $" << salesMonth << endl;

} 

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
    
   if (userChoice < 1 || userChoice  > 3) {
      cout << endl << "Please input a valid number" << endl;
   }else{
      return userChoice;
   }//end if-else
   
   return 0;
   
}//end displayMenu

//I: string containing the type and a vector containing the data.
//P: display the data.
//O: same as process.
void displayVehicle(string searchType, vector<vehicleTypesOnOffLot> vehicleTypes) {
   // Display the top of the table. MH
  cout << " " << searchType << " | On Lot | Sold\n";
  cout << "--------------------------------" << endl;

   // Display the data. MH
  for (i = 0; i < vehicleTypes.size(); i++) {
      cout << " " << vehicleTypes.at(i).type << " | " << vehicleTypes.at(i).onLot << " | " << vehicleTypes.at(i).onLot << endl;
      cout << "----------------------------" << endl;
  } // end for() 
} // end displayVehicle()
