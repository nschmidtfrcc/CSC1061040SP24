#include <iostream>
#include <string>
using namespace std;

class Vehicle{
public:

Vehicle(){
string make = "";
string model = "";
string color = "";
string vin = "";
int year = 0;
int timeOnLot = 0;
int price = 0;
bool sold = false;
};

void SetMake(string make);
string GetMake();
void SetModel(string model);
string GetModel();
void SetColor(string color);
string GetColor();
void SetVin(int vin);
string GetVin();
void SetYear(int year);
int GetYear();
void SetTimeOnLot(int timeOnLot);
int GetTimeOnLot();
void SetPrice(int price);
int GetPrice();
void DisplayVehicle(); 

private:
string make;
string model;
string color;
string vin;
int year;
int timeOnLot;
int price;
bool sold;
};
