// Created by Roy Redman

#include <iostream>
#include <string>

using namespace std;

// Takes a load of string variables and combines them into one easy string
// Uses the default parameter in order to test if they have a middle name or not.
string CombineFullName(string, string, string = "NULL");

int main() {
  string First, Middle, Last, name;
  cout << "What is your First name? ";
  cin >> First;

  cout << "\nWhat is your middle name? (Hit \"-1\" if you don't have one) ";
  cin >> Middle;

  cout << "\nWhat is your last name? ";
  cin >> Last;

  if (Middle == "-1")
    name = CombineFullName(First, Last);

  else
    name = CombineFullName(First, Last, Middle);

  cout << "Your full name is " << name << endl;
      
}

string CombineFullName(string First, string Last, string Middle) {
  if (Middle == "NULL")
    return (First + " " + Last);

  return (First + " " + Middle + " " + Last);
}
