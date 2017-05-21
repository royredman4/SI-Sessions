// Created by Roy Redman IV

#include "Cars.h"

Cars::Cars() {
	color = model = make = "NULL";
	year = 0;
}

Cars::Cars(string c, string mo, string ma, int yr) {
	SetColor(c);
	SetModel(mo);
	SetMake(ma);
	SetYear(yr);
}

void Cars::SetColor(string c){
	color = c;
}

void Cars::SetModel(string mo){
	model = mo;
}

void Cars::SetMake(string ma){
	make = ma;
}

void Cars::SetYear(int yr){
	if (yr < 0)
		year = 0;
	else
		year = yr;
}

string Cars::GetColor() {
	return color;
}

string Cars::GetModel() {
	return model;
}

string Cars::GetMake() {
	return make;
}

int Cars::GetYear() {
	return year;
}
