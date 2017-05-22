// Created by Roy Redman IV

#include "Rv.h"
#include <iostream>
#include <string>
using namespace std;

Rv::Rv():Cars() {
  bathroomCount = seatCount = bedCount = hasStove = 0;
}

Rv::Rv(double mpppg, string clr, bool tm, int trSz, int bc, int sc, int bedc, bool hStove) : Cars(mpppg, clr, tm, trSz) {
  bathroomCount = bc;
  seatCount = sc;
  bedCount = bedc;
  hasStove = hStove;
}

void Rv::SetbathroomCount(int bc) {
  bathroomCount = bc;
}

void Rv::SetseatCount(int sc) {
  seatCount = sc;
}

void Rv::SetbedCount(int bedc) {
  bedCount = bedc;
}

void Rv::SethasStove(bool hStove) {
  hasStove = hStove;
}

int Rv::GetbathroomCount() {
  return bathroomCount;
}

int Rv::GetseatCount() {
  return seatCount;
}

int Rv::GetbedCount() {
  return bedCount;
}

bool Rv::GethasStove() {  
  return hasStove;
}

void Rv::print() {
  Cars::print();
  cout << "Bathroom Count is: " << GetbathroomCount() << " bathrooms" <<  endl;
  cout << "Seat Count is: " << GetseatCount() << " seats" << endl;
  cout << "Bed Count is: " << GetbedCount() << " beds" << endl;
  string value;
  if (GethasStove())
    value = "true";
  else
    value = "false";
  cout << "Has stove is: " << value << endl;
}
