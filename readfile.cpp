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