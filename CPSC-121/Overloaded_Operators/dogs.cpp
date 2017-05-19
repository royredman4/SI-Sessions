// Created by Roy Redman IV
#include "dogs.h"

#include <iostream>
#include <string>
using namespace std;


Dogs::Dogs() {
  name = breed = "Null";
  weight = cost = age = 0;
}


Dogs::Dogs(string nm, string bred, double lb, double price, int youth) {
  name = nm;
  breed = bred;
  weight = lb;
  cost = price;
  age = youth;

}

void Dogs::Setname(string nm) {
  name = nm;
}

void Dogs::Setbreed(string bred) {
  breed = bred;
}

void Dogs::Setweight(double lb) {
  if (lb > 0.0)
    weight = lb;
}

void Dogs::Setcost(double price) {
  if (price > 0.0)
    cost = price;
}

void Dogs::Setage(int youth) {
  if (youth > 0.0)
    age = youth;
}

string Dogs::Getname() {
  return name;
}

string Dogs::Getbreed() {
  return breed;
}

double Dogs::Getweight() {
  return weight;
}

double Dogs::Getcost() {
  return cost;
}

int Dogs::Getage() {
  return age;
}

// Assignemnt #2
bool Dogs::operator<(const Dogs comparison) {
  if (this->age < comparison.age)
    return true;
  
  return false;
}

// Assignment #2
bool Dogs::operator>(const Dogs comparison) {
  if (this->age > comparison.age)
    return true;
  return false;
}


// Assignment #1
ostream& operator<<(ostream& output, Dogs current) {
  output  << current.name << " is a " << current.breed << endl
	  << "and is " << current.age << " years old " << endl
          << "and its price is " << current.cost << endl;
  return output;
}

// Assignemnt #3
istream& operator>>(istream& in, Dogs& current) {
  string names;
  double values;
  cout << "Input the following:\n"
       << "Dogs name: ";
  in >> names;
  current.Setname(names);

  cout << "\nDogs Breed Type: ";
  in >> names;
  current.Setbreed(names);
  
  cout << "\nDogs Weight: ";
  in >> values;
  current.Setweight(values);

  cout << "\nDogs Cost: ";
  in >> values;
  current.Setcost(values);
  
  cout << "\nDogs Age: ";
  in >> values;
  current.Setage(int(values));

  return in;
}




