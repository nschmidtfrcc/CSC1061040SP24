#include "Vehicle.h"

void Vehicle::SetMake(string make){
  this->make = make;
}
string Vehicle::GetMake(){
  return make; 
}
void Vehicle::SetModel(string model){
  this->model = model;
}
string Vehicle::GetModel(){
  return model;
}
void Vehicle::SetColor(string color){
  this->color = color;
}
string Vehicle::GetColor(){
  return color;
}
void Vehicle::SetVin(int vin){
  this->vin = vin;
 }
string Vehicle::GetVin(){
  return vin;
}
void Vehicle::SetYear(int year){
  this->year = year;
}
int Vehicle::GetYear(){
  return year;
}
void Vehicle::SetTimeOnLot(int timeOnLot){
  this->timeOnLot = timeOnLot;
}
int Vehicle::GetTimeOnLot(){
  return timeOnLot;
}
void Vehicle::SetPrice(int price){
  this->price = price;
}
int Vehicle::GetPrice(){
  return price;
}
void Vehicle::DisplayVehicle(){}