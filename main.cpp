#include <iostream>
#include <vector>
#include "Vehicle.h"
using namespace std;

void searchVehicle(vector<Vehicle> vehicles);
void displayVehicle(vector<vehicleTypesOnOffLot> vehicleTypes);

struct vehicleTypesOnOffLot{
    string type;
    int onLot = 0;
    int offLot = 0;
};

int main(){




    return 0;
}





void searchVehicle(vector<Vehicle> vehicles){
    char numValidate;
    bool done;
    string type;
    vehicleTypesOnOffLot dud;
    vector<vehicleTypesOnOffLot> vehicleTypes;


    // Prompting and getting input from the user
    cout << "Search for a vehicle by:" << endl;
    cout << "1.) Make" << endl;
    cout << "2.) Model" << endl;
    cout << "3.) Year" << endl;
    cout << "4.) Color" << endl;
    cout << "5.) Time on Lot" << endl;

    while(numValidate <= 48 || numValidate >= 54){
        cout << "Please enter a number between 1-5: ";
        cin >> numValidate;
        cout << endl;
    }

    // Populating a vector vehicleTypes with this for loop
    for(int i = 0; i<vehicles.size(); i++){
        // Switch statement for whatever the user chose
        switch(numValidate){
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
        }

        // Checking to see if the type is already in the vehicleTypes Vector
        // Also adds one to on or off lot depending on the vehicle
        done = false;
        for(int j = 0; j < vehicleTypes.size(); j++){
            if(vehicleTypes.at(j).type == type){
                if(vehicles.at(i).GetSold() == false){
                    vehicleTypes.at(j).onLot += 1;
                }
                else{
                    vehicleTypes.at(j).offLot += 1;
                }
                done = true;
                break;
            }
        }
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
            }
        }
    }

    // Passing in the vehicleTypes vector to the display vehicle so they can do it
    displayVehicle(vehicleTypes);
}




void displayVehicle(vector<vehicleTypesOnOffLot> vehicleTypes){

}