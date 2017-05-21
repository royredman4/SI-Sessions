// Created by Roy Redman IV

#include <iostream>
#include <string>
#include "Cars.h"

using namespace std;

void DisplayCarLot(Cars[], int);

int main() {
	string value;
	int val, size;
	char input;
	// Assignment #3
	Cars CarLot[200];

	for (int i = 0; i < 200; ++i) {
		cout << "What is the cars color? ";
		cin >> value;
		CarLot[i].SetColor(value);
		cout << endl << "What is the cars make? ";
		cin >> value;
		CarLot[i].SetMake(value);
		cout << endl << "What is the cars model? ";
		cin >> value;
		CarLot[i].SetModel(value);
		cout << endl << "What is the cars year? ";
		cin >> val;
		CarLot[i].SetYear(val);

		cout << endl << "Would you like to add another Car? (y/n) ";
		cin >> input;

		if (input != 'y' && input != 'Y') {
			
			size = i;
			break;
		}
		cout << endl;
		if (i == 199)
			size = 199;
		
	}
	DisplayCarLot(CarLot, size);
	return 0;
}

void DisplayCarLot(Cars CrLot[], int size) {
	for (int i = 0; i <= size; ++i) {
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "Color: " << CrLot[i].GetColor() << endl;
		cout << "Make: " << CrLot[i].GetMake() << endl;
		cout << "Model: " << CrLot[i].GetModel() << endl;
		cout << "Year: " << CrLot[i].GetYear() << endl << endl;
	}
}