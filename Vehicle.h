#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
  // parameterized constructor will read values from file and assigns them to
  // the private variables. The file name is passed as a parameter to the
  // constructor. ex. Vehicle("car.txt").
  Vehicle(const string &filename);
  Vehicle() {
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
  void SetSold(bool sold);
  bool GetSold();
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
