// Created by Roy Redman IV

#ifndef _DOGS_H_
#define _DOGS_H_

#include <iostream>
#include <string>
using namespace std;

class Dogs {

  // Overloads the cout operator
  friend ostream& operator<<(ostream&, const Dogs);

  // Overloads the cin operator
  friend istream& operator>>(istream&, Dogs&);

 private:
  string name;
  string breed;
  double weight;
  double cost;
  int age;
  
 public:
  Dogs();

  // Default constructor with passed values
  Dogs(string, string, double, double, int);

  // Default mutators
  void Setname(string);
  void Setbreed(string);
  void Setweight(double);
  void Setcost(double);
  void Setage(int);

  // Default Accessors
  string Getname();
  string Getbreed();
  double Getweight();
  double Getcost();
  int Getage();

  // Overloads the < operator
  bool operator<(const Dogs);

  // Overloads the > operator
  bool operator>(const Dogs);

};

#endif
