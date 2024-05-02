#include "Customer.h"
#include "Vehicle.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int DisplayMenu();

void DisplaySales(int salesDay, int salesWeek, int salesMonth);

//Input: Vehicle and custmer data read from file. User input to navigate menus to search. MD
//Process: Files are read and vectors of vehicles and customers are made. The user navitages menus to search for vehicles and customers based on specific data values. Sales data can also be searched. MD
//Output: The program outputs the result of the user's search. MD
struct vehicleTypesOnOffLot {
  string type;
  int onLot = 0;
  int offLot = 0;
};


void searchVehicle(vector<Vehicle> vehicles);
void displayVehicle(string searchType,
                    vector<vehicleTypesOnOffLot> vehicleTypes);

bool readfile();

int calculateSales(const vector<Vehicle>& vehicles, int salesDay, int salesWeek, int salesMonth);

void DisplaySales(int salesDay, int salesWeek, int salesMonth);

// Input: Vehicle and custmer data read from file. User input to navigate menus
// to search. MD Process: Files are read and vectors of vehicles and customers
// are made. The user navitages menus to search for vehicles and customers based
// on specific data values. Sales data can also be searched. MD Output: The
// program outputs the result of the user's search. MD
int main() {
  // Declarations.(MH)
  vector<Vehicle> Vehicles;
  vector<Customer> Customers;
  int salesDay = 0;
  int salesWeek = 0;
  int salesMonth = 0;
  int optionNum = 0;
  int count;

  // Gets the data need for the other functions called.(Mh)
  readfiles();

  CalculateSales(Vehicles, salesDay, salesWeek, salesMonth);

  // Calls DisplayMenu() to run through the different options through the
  // system.(MH)
  optionNum = DisplayMenu();
  switch (optionNum) {
  case 1:
    DisplaySales(salesDay, salesWeek, salesMonth); // Displays the Sales
    break;
  case 2:
    SearchVechiles(
        Vechiles); // Searches the vechiles vector by a spefic criteria and
                   // displays the appropriate vechile(s).(MH)
    break;
  case 3:
    // Displays all the customers.(MH)
    for (count = 0; count <= Customers.size(); ++i) {
      DisplayCustomer();
    } // End of for().(MH)
    break;
  default:
    cout << "That is not a option in the system." << endl;
  } // End of swtich().(MH)
  int salesDay, salesWeek, salesMonth = 0;
  DisplaySales(salesDay, salesWeek, salesMonth);

} // end main

// Input: N/A
// Process: Reads the text files and populates variables which then fills the
// vectors of objects with the created objects Output: Returns boolean value
// based off of success of read operation
bool readFile() {
  bool boughtStatus, sold;
  string tmp, vinNum, firstName, lastName, phoneNum, make, model, color, vin;
  int year, timeOnLot, price;
  vector<Customer> customerVec;
  vector<Vehicle> vehicleVec;
  ifstream inputFileC("customer.txt");
  ifstream inputFileV("vehicle.txt");
  if (!inputFileC.is_open() || !inputFileV.is_open()) {
    throw runtime_error("Failed to open file. Exiting...");
    return false;
  }

  while (getline(inputFileC, tmp)) {
    if (tmp.find("CUSTOMER") != string::npos) {
      getline(inputFileC, vinNum);
      getline(inputFileC, firstName);
      getline(inputFileC, lastName);
      getline(inputFileC, phoneNum);
      inputFileC >> boolalpha >>
          boughtStatus; // boolalpha to make bool yes or no not 1 or 0
    }
    Customer cust(boughtStatus, vin, firstName, lastName, phoneNum);
    customerVec.push_back(cust);
  }
  // Getting vehicle data
  while (getline(inputFileV, tmp)) {
    if (tmp.find("VEHICLE") != string::npos) {
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

// Input: vector of vehicles, asks for number between 1-5 from user
// Process: Validates user input and then puts the correct type of search value
// in the vector of vehicleTypesOnOffLot Output: No output but calls the
// displayVehicle function
void searchVehicle(vector<Vehicle> vehicles) {
  string numValString;
  char numValChar;
  bool done;
  string type;
  string searchType;
  vehicleTypesOnOffLot dud;
  vector<vehicleTypesOnOffLot> vehicleTypes;

  // Prompting and getting input from the user
  // Validating
  cout << "Search for a vehicle by:" << endl;
  cout << "1.) Make" << endl;
  cout << "2.) Model" << endl;
  cout << "3.) Year" << endl;
  cout << "4.) Color" << endl;
  cout << "5.) Time on Lot" << endl;

  while (numValChar <= 48 || numValChar >= 54) {
    cout << "Please enter a number between 1-5: ";
    getline(cin, numValString);
    if (numValString.size() != 1) {
      continue;
    }
    numValChar = numValString.at(0);
    cout << endl;
  } // end while

  // Populating a vector vehicleTypes with this for loop
  for (unsigned int i = 0; i < vehicles.size(); i++) {
    // Switch statement for whatever the user chose
    switch (numValChar) {
    case 49:
      // Make
      type = vehicles.at(i).GetMake();
      searchType = "Make";
      break;
    case 50:
      // Model
      type = vehicles.at(i).GetModel();
      searchType = "Model";
      break;
    case 51:
      // Year
      type = to_string(vehicles.at(i).GetYear());
      searchType = "Year";
      break;
    case 52:
      // Color
      type = vehicles.at(i).GetColor();
      searchType = "Color";
      break;
    case 53:
      // Time on Lot
      type = to_string(vehicles.at(i).GetTimeOnLot());
      searchType = "Time on Lot";
      break;
    default:
      break;
    } // end switch

    // Checking to see if the type is already in the vehicleTypes Vector
    // Also adds one to on or off lot depending on the vehicle
    done = false;
    for (unsigned int j = 0; j < vehicleTypes.size(); j++) {
      if (vehicleTypes.at(j).type == type) {
        if (vehicles.at(i).GetSold() == false) {
          vehicleTypes.at(j).onLot += 1;
        } else {
          vehicleTypes.at(j).offLot += 1;
        }
        done = true;
        break;
      } // end if
    }   // end for
    // If the type is not there then it adds it to the vehicle type vector
    // Also adds one to on or off lot depending on the vehicle
    if (done == false) {
      dud.type = type;
      vehicleTypes.push_back(dud);
      if (vehicles.at(i).GetSold() == false) {
        vehicleTypes.at(vehicleTypes.size() - 1).onLot += 1;
      } else {
        vehicleTypes.at(vehicleTypes.size() - 1).offLot += 1;
      } // end if else
    }   // end if
  }     // end for

  // Passing in the vehicleTypes vector to the display vehicle so they can do it
  displayVehicle(searchType, vehicleTypes);
} // end searchVehicle()

//Input: A vector with all of the vehicles, dailySales, weeklySales and monthlySales.
//Process: Creates totalSales; updates dailySales, weeklySales, and monthlySales
//Output: Total sales value.
int calculateSales(const vector<Vehicle>& vehicles, int salesDay, int salesWeek, int salesMonth) {
    int salesTotal = 0;
    // Iterates through Vehicle vector
    for (const auto& vehicle : vehicles) {
      if(vehicle.isSold()){
          salesTotal += vehicle.GetPrice(); // May be .getPrice()
          
          // If the vehicle sold today, add it to dailySales
          if (vehicle.GetTimeOnLot() <= 1) {
              salesDay += vehicle.GetPrice();
          }
          // If the vehicle sold this week, add it to weeklySales
          if (((vehicle.GetTimeOnLot() % 7) <= 7)) {
              salesWeek += vehicle.GetPrice();
          }
          // If the vehicle sold this month, add it to monthlySales
          if (vehicle.GetTimeOnLot() <= 30) { // 30 is the average amount of days in a month.
              salesMonth += vehicle.GetPrice();
          }
      }
  }
    return salesTotal;
}

void DisplaySales(int salesDay, int salesWeek, int salesMonth) {
  cout << "Sales today: $" << salesDay << endl;
  cout << "Sales this week: $" << salesWeek << endl;
  cout << "Sales this month: $" << salesMonth << endl;
}


int DisplayMenu() {

//I: User inputs number corresponding to the 3 different choices; searchInventory, displaySales, or customerList OR
//P: Validate input OR
//O: Output user choice OR

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
   }//end for CC
   
   cout << endl;
   return userChoice;
   
}//end DisplayMenu OR


// I: string containing the type and a vector containing the data.
// P: display the data.
// O: same as process.
void displayVehicle(string searchType,
                    vector<vehicleTypesOnOffLot> vehicleTypes) {
  // Display the top of the table. MH
  cout << " " << searchType << " | On Lot | Sold\n";
  cout << "--------------------------------" << endl;

  // Display the data. MH
  for (i = 0; i < vehicleTypes.size(); i++) {
    cout << " " << vehicleTypes.at(i).type << " | " << vehicleTypes.at(i).onLot
         << " | " << vehicleTypes.at(i).onLot << endl;
    cout << "----------------------------" << endl;
  } // end for()
} // end displayVehicle()
