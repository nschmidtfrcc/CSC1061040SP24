#include <iostream>
#include <string>
#include <vector>
using namespace std;


int calculateSales(const vector<Vehicle>& vehicles, double dailySales, double weeklySales, double monthlySales) {
  // We want to calculate total sales, as well as sales for the day, week, and month.
  int totalSales = 0;
  // Iterates through Vehicle vector
  for (const auto& vehicle : vehicles) {
    // If the car isSold == true
    if(vehicle.isSold()){
      // Add car price to total sales
      totalSales += vehicle.getSalePrice(); // May just be .getPrice()
      
      // If the vehicle sold today, add it to dailySales
      if (vehicle.timeOnLot() <= 1) { dailySales += vehicle.getSalePrice(); }
      // If the vehicle sold this week, add it to weeklySales
      if (((vehicle.timeOnLot() % 7) <= 7)) { weeklySales += vehicle.getSalePrice(); }
      // If the vehicle sold this month, add it to monthlySales
      if (vehicle.timeOnLot() <= 30) { monthlySales += vehicle.getSalePrice(); }
      //                           /\ 30 is the average amount of days in a month.

        // We need to either create a getSaleDate() function or a way to get the current date and time using something from the c++ library.
    }

  }
  
    return totalSales; // Return the totalSales;
} // Maybe this might work?



int main() {
  double dailySales = 0.0;
  double weeklySales = 0.0;
  double monthlySales = 0.0;
  
  calculateSales(vehicles, dailySales, weeklySales, monthlySales);
  printSales(dailySales, weeklySales, monthlySales)
  
  return 0;
} // end main

// Calculate sales is going to be in main, calcualte sales of the vehichles that sold and then add them up. Time on lot to use.