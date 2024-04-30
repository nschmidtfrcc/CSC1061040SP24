#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
using namespace std;

class Customer{
   public:
   
   //Default constructor.MH
   Customer();
   Customer(bool boughtStatus, string initVin, string initFirst, string initLast, string initContact);
   
   //Mutators/Setters functions.MH
   void SetBought(bool inputStatus);
   void SetVin(string inputVin);
   void SetFirstName(string inputFirst);
   void SetLastName(string inputLast);
   void SetContactInfo(string inputContact);

   //Accessor/Getters functions.MH
   bool GetBought();
   string GetVin();
   string GetFirstName();
   string GetLastName();
   string GetContactInfo();
   
   //Displays Customer method.(MH)
   void DisplayCustomer();
   
   private:
   
   //Data members(MH)
   bool bought;
   string vinNumber;
   string firstName;
   string lastName;
   string contactInfo;
   
};//End of class def.MH
#endif