// Created by Roy Redman IV

#include "Cars.h"

Cars::Cars() {
  mpg = tireSize = is_manualTransmission = 0;
  color = "NULL";
}
Cars::Cars(double mpppg, string clr, bool trans, int trSize) {
  mpg = mpppg;
  color = clr;
  is_manualTransmission = trans;
  tireSize = trSize;
  
}

void Cars::Setmpg(double mpppg) {
  mpg = mpppg;
}

void Cars::Setcolor(string clr) {
  color = clr;
}

void Cars::SetManualTransmission(bool transmission) {
  is_manualTransmission = transmission;
}

void Cars::SettireSize(int trSize) {
  tireSize = trSize;
}
 
double Cars::Getmpg() {
  return mpg;
}

string Cars::Getcolor() {
  return color;
}

bool Cars::GetManualTransmission() {
  return is_manualTransmission;
}

int Cars::GettireSize() {
  return tireSize;
}

void Cars::print() {
  cout << "Mpg is: " << Getmpg() << endl;
  cout << "Color is: " << Getcolor() << endl;
  string value;
  if (GetManualTransmission())
    value = "true";
  else
    value = "false";
  cout << "Manual Transmission type is: " << value << endl;
  cout << "Tire size is: " << GettireSize() << " inches" << endl;
}
