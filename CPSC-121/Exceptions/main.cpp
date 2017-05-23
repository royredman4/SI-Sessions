// Created by Roy Redman IV

#include <iostream>
#include <string>

using namespace std;

// Assignment #2
// Checks if you you are dividing by
// zero, if so, it will throw an error,
// otherwise it will return the result
double division(double, double);

// Assignment #3
// It would check the age of your son
// compared to you. If you are younger
// than your son, you are not the father,
// otherwise, you are
string PaternityTest(int, int);

int main() {
  double val1, val2;
  char input;
  do {
    cout << "What two numbers do you want to divide?" << endl;
    cout << "Value 1: ";
    cin >> val1;
    cout << endl << "Value 2: ";
    cin >> val2;

    // Prepares that section incase if a throw gets passed
    try {
      cout << division(val1, val2) << endl;
    }

    // grabs the nearest throw based on the paramater value thrown
    catch (double value) {
      cout << "You cannot divide by " << value << endl;
    }
    cout << "would you like to try this again?(y/n)\n";
    cin >> input;
  } while (input == 'y' || input == 'Y');

  try {
    int age1, age2;
    cout << "Whats your age? " << endl;
    cout << "your age: ";
    cin >> age1;
    cout << endl << "Whats your sons age?" << endl;
    cout << "Sons age: ";
    cin >> age2;
    cout << PaternityTest(age1, age2);
  }
  catch (int e) {
    cout << "You are NOT the father!!";
  }

  return 0;
}
double division(double v1, double v2) {
    if (v2 == 0)
      throw v2;

  return v1/v2;
}

string PaternityTest(int yourAge, int sonAge) {
  if (yourAge < sonAge)
    throw yourAge;

  return "You ARE the father!!";
}


