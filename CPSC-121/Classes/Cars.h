// Created by Roy Redman IV

#include <iostream>
#include <string>

using namespace std;

#ifndef _CARS_H_
#define _CARS_H_

// Assignment #2
class Cars{
  private:
	  string color;
	  string model;
	  string make;
	  int year;

  public:
	  // Default constructors allows all the variables
	  // to be initialized even if the user doesn't set
	  // it to begin with.
	  Cars();

	  // Default constructors allows all the passed varibles
	  // to be easily set to the private variables in the car
	  // class
	  Cars(string, string, string, int);
	  
	  // Assignment #4
	  // Accessors make it easy to access your variables
	  // information safely.
	  string GetColor();
	  string GetModel();
	  string GetMake();
	  int GetYear();

	  // Mutators makes it easy to change your protected
	  // variables while also checking for errors prior
	  void SetColor(string);
	  void SetModel(string);
	  void SetMake(string);
	  void SetYear(int);
};

#endif