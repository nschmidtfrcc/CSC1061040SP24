#include <iostream>
#include <vector>
#include "Vehicle.h"
using namespace std;


struct vehicleTypesOnOffLot{
    string type;
    int onLot = 0;
    int offLot = 0;
};

void searchVehicle(vector<Vehicle> vehicles);
void displayVehicle(vector<vehicleTypesOnOffLot> vehicleTypes);


int main(){

    return 0;
}




// Input: vector of vehicles, asks for number between 1-5 from user
// Process: Validates user input and then puts the correct type of search value in the vector of vehicleTypesOnOffLot
// Output: No output but calls the displayVehicle function
void searchVehicle(vector<Vehicle> vehicles){
    string numValString;
    char numValChar;
    bool done;
    string type;
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

    while(numValChar <= 48 || numValChar >= 54){
        cout << "Please enter a number between 1-5: ";
        getline(cin, numValString);
        if(numValString.size() != 1){
            continue;
        }
        numValChar = numValString.at(0);
        cout << endl;
    } // end while

    // Populating a vector vehicleTypes with this for loop
    for(unsigned int i = 0; i<vehicles.size(); i++){
        // Switch statement for whatever the user chose
        switch(numValChar){
            case 49:
                // Make
                type = vehicles.at(i).GetMake();
                break;
            case 50:
                // Model
                type = vehicles.at(i).GetModel();
                break;
            case 51:
                // Year
                type = to_string(vehicles.at(i).GetYear());
                break;
            case 52:
                // Color
                type = vehicles.at(i).GetColor();
                break;
            case 53:
                // Time on Lot
                type = to_string(vehicles.at(i).GetTimeOnLot());
                break;
            default:
                break;
        } // end switch

        // Checking to see if the type is already in the vehicleTypes Vector
        // Also adds one to on or off lot depending on the vehicle
        done = false;
        for(unsigned int j = 0; j < vehicleTypes.size(); j++){
            if(vehicleTypes.at(j).type == type){
                if(vehicles.at(i).GetSold() == false){
                    vehicleTypes.at(j).onLot += 1;
                }
                else{
                    vehicleTypes.at(j).offLot += 1;
                }
                done = true;
                break;
            } // end if
        } // end for
        // If the type is not there then it adds it to the vehicle type vector
        // Also adds one to on or off lot depending on the vehicle
        if(done == false){
            dud.type = type;
            vehicleTypes.push_back(dud);
            if(vehicles.at(i).GetSold() == false){
                vehicleTypes.at(vehicleTypes.size() - 1).onLot += 1;
            }
            else{
                vehicleTypes.at(vehicleTypes.size() - 1).offLot += 1;
            } // end if else
        } // end if
    } // end for

    // Passing in the vehicleTypes vector to the display vehicle so they can do it
    displayVehicle(vehicleTypes);
} // end searchVehicle()




void displayVehicle(vector<vehicleTypesOnOffLot> vehicleTypes){

}