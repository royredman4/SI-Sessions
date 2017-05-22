// Created by Roy Redman IV

#ifndef _CARS_H_
#define _CARS_H_

#include <iostream>
#include <string>
using namespace std;

// Assignment #1
class Cars {
 private:
  double mpg;
  string color;
  bool is_manualTransmission;
  int tireSize;

  
 public:
  Cars();
  Cars(double, string, bool, int);

  // Default setters allows the private variables
  // to be altered safely
  void Setmpg(double);
  void Setcolor(string);
  void SetManualTransmission(bool);
  void SettireSize(int);

  // Allows the user to get the private variables
  // values without risking altering the private variables
  double Getmpg();
  string Getcolor();
  bool GetManualTransmission();
  int GettireSize();

  virtual void print();
  
};

#endif
