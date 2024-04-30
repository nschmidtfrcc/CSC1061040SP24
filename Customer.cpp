#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

//Input: Hard coded in the program.(MH)
//Process: Sets the default values for all the data in the default constructor.(MH)
//Output: None (MH)
void Customer::Customer(){
   bought = false;
   vinNumber = "ABCD1234EFGH56780";
   firstName = "No first name";
   lastName = "No last name";
   contactInfo = "000-000-0000";
}//End of Customer() default constructor.MH

//Input: Data inputed from the user.(MH)
//Process: Sets the data members values from the input of the user when Customer constructor is called.(MH)
//Output: None (MH)
void Customer:Customer(bool boughtStatus, string initVin, string initFirst, string initLast, string initContact){
   bought = boughtStatus;
   vinNumber = initVin;
   firstName = initFirst;
   lastName = initLast;
   contactInfo = initContact;
}// End of Customer() constructor.MH

//Input: Data inputed from the user.(MH)
//Process: Sets the bought value from the input of the user when SetBought is called.(MH)
//Output: None (MH)
void Customer::SetBought(bool inputBought){
   bought = inputBought;
}//End of SetBought().(MH)

//Input: Data inputed from the user.(MH)
//Process: Sets the bought value from the input of the user when SetVin is called.(MH)
//Output: None (MH)
void Customer::SetVin(string inputVin){
   vinNumber = inputVin;
}//End of SetVin()MH

//Input: Data inputed from the user.(MH)
//Process: Sets the bought value from the input of the user when SetFirstName is called.(MH)
//Output: None (MH)
void Customer::SetFirstName(string inputFirst){
   firstName = inputFirst;
}//End of SetFirstName().(MH)

//Input: Data inputed from the user.(MH)
//Process: Sets the bought value from the input of the user when SetLastName is called.(MH)
//Output: None (MH)
void Customer::SetLastName(string inputLast){
   lastName = inputLast;
}//End of SetLastname().(MH)

//Input: Data inputed from the user.(MH)
//Process: Sets the bought value from the input of the user when SetContactInfo is called.(MH)
//Output: None (MH)
void Customer::SetContactInfo(string inputContact){
   contactInfo = inputContact;
}//End of SetContactInfo().(MH)

//Input: No input (MH)
//Process: When GetBought is called it will returns the value of bought.(MH)
//Ouput: Returns the value of bought.(MH)
bool Customer::GetBought(){
   return bought;
}//End of GetBought().(MH)

//Input: No input (MH)
//Process: When GetVin is called it will returns the value of vinNumber.(MH)
//Ouput: Returns the value of vinNumber.(MH)
string Customer::GetVin(){
   return vinNumber;
}//End of GetVin().(MH)

//Input: No input (MH)
//Process: When GetFirstName is called it will returns the value of firstName.(MH)
//Ouput: Returns the value of firstName.(MH)
string Customer::GetFirstName(){
   return firstName;
}//End of GetFirstName().(MH)

//Input: No input (MH)
//Process: When GetLastName is called it will returns the value of lastName.(MH)
//Ouput: Returns the value of lastName.(MH)
string Customer::GetLastName(){
   return lastName;
}//End of GetLastName().(MH)

//Input: No input (MH)
//Process: When GetContactInfo is called it will returns the value of contactInfo.(MH)
//Ouput: Returns the value of contactInfo.(MH)
string Customer::GetContactInfo(){
   return contactInfo;
}//End of GetContactInfo().(MH)

void DisplayCustomer(){
   cout << "Customer: " << firstName << " " << lastName << endl;
   cout << "Vin number to the car is : " << vinNumber << endl;
   if(){
   
   }//End of if().(MH)
   else{
   
   }//End of else().(MH)
   
}//End of DisplayCustomer().(MH)