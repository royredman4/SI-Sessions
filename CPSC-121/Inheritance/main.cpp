// Created by Roy Redman IV

#include "Cars.h"
#include "Rv.h"
#include <iostream>
#include <string>

using namespace std;



int main() {
  // Assignment #3
  // Virtual function does not affect anything here
  Rv LargeRv(12, "Red", false, 5, 1, 6, 2, true);
  Cars Mustang(32, "Yellow", true, 7);
  cout << "Outputting Rv type" << endl;
  LargeRv.print();

  cout << endl << "Outputting Car type" << endl;
  Mustang.print();

  cout << endl <<  "With the help of virtual functions we can " << endl;
  cout << "use both a Car type and an Rv type respectfully inside" << endl;
  cout << "a car array without any issues." << endl;

  // Assignment #4
  // This wouldn't work the way we expected it
  // without pure virtual functions
  // if you want to test it without a virtual function,
  // remove the keyword "virutal" from the "print()" function
  // in Cars.h and Rv.h 
  Cars* Garage[2];
  Garage[0] = new Rv(12, "Red", false, 5, 1, 6, 2, true);
  Garage[1] = new Cars(32, "Yellow", true, 7);

  // Without virtual functions, both of these would only
  // output print(), from type Cars, but with the help
  // of virtual functions, it identifies its object type
  // and calls the "print()" function by its object type
  for (int i = 0; i < 2; ++i) {
    cout << "Car #" << i+1 << endl;
    Garage[i]->print();
    cout << endl;
  }
  
  return 0;
}
