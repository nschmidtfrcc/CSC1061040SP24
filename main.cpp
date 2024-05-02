#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Customer.h"
using namespace std;

#include "customer.h"
#include "vehicle.h"
#include <fstream>
//Input: N/A
//Process: Reads the text files and populates variables which then fills the vectors of objects with the created objects
//Output: Returns boolean value based off of success of read operation
bool readFile() {
	bool boughtStatus, sold;
	string tmp, vinNum, firstName, lastName, phoneNum, make, model, color, vin;
	int year, timeOnLot, price;
	vector<Customer> customerVec;
	vector<Vehicle> vehicleVec;
	ifstream inputFileC("customer.txt");
	ifstream inputFileV("vehicle.txt");
	if(!inputFileC.is_open() || !inputFileV.is_open()) {
		throw runtime_error("Failed to open file. Exiting...");
		return false;
	}

	while(getline(inputFileC, tmp)) {
		if(tmp.find("CUSTOMER") != string::npos) { 
			getline(inputFileC, vinNum);
			getline(inputFileC, firstName);
			getline(inputFileC, lastName);
			getline(inputFileC, phoneNum);
			inputFileC >> boolalpha >> boughtStatus; // boolalpha to make bool yes or no not 1 or 0
		}
		Customer cust(boughtStatus, vin, firstName, lastName, phoneNum);
		customerVec.push_back(cust);
	}
	// Getting vehicle data
	while(getline(inputFileV, tmp)) {
		if(tmp.find("VEHICLE") != string::npos) { 
			getline(inputFileV, make);
			getline(inputFileV, model);
			getline(inputFileV, color);
			inputFileV >> vin;
			inputFileV >> year;
			inputFileV >> timeOnLot;
			inputFileV >> price;
			inputFileV >> boolalpha >> sold;
		}
		Vehicle veh(make, model, color, vin, year, timeOnLot, price, sold);
		vehicleVec.push_back(veh);
	}

	inputFileC.close(); 
   inputFileV.close(); 
	return true;
}
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
