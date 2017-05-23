// Created by Roy Redman IV

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Assignment #2
// Takes in two items of the same data
// type and returns the combination of
// the two
template <class T>
T CombinedValue(T, T);

// Assignment #3
// Takes a random set of information/data
// types and outputs it to the screen
template<class T, class U, class V, class W>
void OutputValues(T[], U[], V[], W);



int main() {

  // Assignment #3
  // Outputing information about the stock market crash
  double yearValues[] = { 2012, 2013, 2014, 2015};
  double percentChange[] = {-30.3, 17.9, 2.33, 5.97};
  string headers[] = {"Years", "Percent Change"};
  string topic = "Housing Market Changes";
  cout << "Outputting a chart based on " << topic << endl;
  OutputValues(headers, yearValues, percentChange, topic);


  // Outputting information about Car bills
  // Notice the difference in data types between the two
  // times where making the function calls
  string carBill[] = {"Oil Change", "New Transmission", "New Tire", "Radiatior Change"};
  double cost[] = {50.00, 1560.00, 300.99, 205.64};
  string newHeaders[] = {"Bill Info", "Cost"};
  string newTopic = "Monthly Car bills";
  cout << "Outputing a chart based on " << newTopic << endl;
  OutputValues(newHeaders, carBill, cost, newTopic);

  
  // Assignment #3
  string val1 = "Cat", val2 = "Dog";
  cout << "Combining two values of the same data type for the fun of it\n";
  cout << CombinedValue(val1, val2) << endl;
  cout << CombinedValue(5, 4) << endl;
  cout << CombinedValue(4.5, 9.4) << endl;

  // Doesn't work since they aren't the same
  // Data type
  //cout << CombinedValue(4, 9.3) << endl;

  
  return 0;
}

template <class T, class U, class V, class W>
void OutputValues(T Heading[], U Years[], V Pchange[], W Title) {
  cout << setw(40) << Title << "\n\n";
  cout << setw(20) <<  Heading[0] << setw(19) << Heading[1] <<  "\n\n";

  for (int i = 0; i < 4; ++i) {
    cout << setw(19) << Years[i] << setw(20) << Pchange[i] << "\n";
  }

  cout << endl;

}

template <class T>
T CombinedValue(T val1, T val2) {
  return val1 + val2;
}
