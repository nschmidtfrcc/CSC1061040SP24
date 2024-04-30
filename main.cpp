//input: data from calculate sales
//process:
//output: display to user gross sales for day, week, month
#include <iostream>
using namespace std;

void DisplaySales(int salesDay, int salesWeek, int salesMonth) {
    cout << "Sales today: $" << salesDay << endl;
    cout << "Sales this week: $" << salesWeek << endl;
    cout << "Sales this month: $" << salesMonth << endl;

}

int main() {
    int salesDay, salesWeek, salesMonth = 0;
    // Does calculateSales update above vars?
    DisplaySales(salesDay, salesWeek, salesMonth);

    return 1;

}