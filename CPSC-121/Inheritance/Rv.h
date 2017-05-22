// Created by Roy Redman IV

#ifndef _RV_H_
#define _RV_H_

#include "Cars.h"
#include <iostream>
using namespace std;

// Assignment #2
class Rv: public Cars {
 private:
  int bathroomCount;
  int seatCount;
  int bedCount;
  bool hasStove;

 public:
  Rv();
  Rv(double, string, bool, int, int, int, int, bool);

  // Default setters allows the private variables
  // to be altered safely
  void SetbathroomCount(int);
  void SetseatCount(int);
  void SetbedCount(int);
  void SethasStove(bool);
  
  // Allows the user to get the private variables
  // values without risking altering the private variables
  int GetbathroomCount();
  int GetseatCount();
  int GetbedCount();
  bool GethasStove();

  virtual void print();
};

#endif
