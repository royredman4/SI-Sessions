// Created by Roy Redman IV

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>


using namespace std;

// Assignment #1
// Finds the factorial based on the users value
int factorial(int);

// Assignment #2
// Checks if an item is prime or not
bool isPrime(int, int =2);

// Assignment #3
// Recursively checks for spaces and replaces them with an underscore
string SpaceReplacer(string, int);


int main() {
	srand(time(0));
	string randomPhrase = "NAQDV 3gyuragytg3hbr ry8qw09rfnb f bAUG73 gt rhgqU3FTR C:{ 40a-";
	cout << "Before change   \"" << randomPhrase << "\""<< endl;
	cout << "After change is \"" << SpaceReplacer(randomPhrase, randomPhrase.length()-1) << "\"" << endl;

	char input;
	int value;
	do {
		cout << "Put in a number that you want to find the factorial of: ";
		cin >> value;
		cin.clear();
		cout << endl << "The factorial of " << value << " is " << factorial(value) << endl;
		cout << "Would you like to do another factorial?(y/n) ";
		cin >> input;
		cin.clear();
	} while (input == 'y' || input == 'Y');

	string p_check = "";
	do {
		cout << "Put in a number that you want to check if it is prime or not: ";
		cin >> value;
		cin.clear();

		if (!(isPrime(value)))
			p_check = "NOT ";

		p_check += "Prime";

		cout << endl << value << " is " << p_check << endl;
		cout << "Would you like to do another factorial?(y/n) ";
		cin >> input;
		cin.clear();
		p_check = "";

	} while (input == 'y' || input == 'Y');
	cout << "Hello";
	return 0;
}

int factorial(int number) {
	if (number <= 1) {
		return 1;
	}

	return number * factorial(number - 1);

}

bool isPrime(int number, int starting) {
	
	if (starting == number) {
		return true;
	}
	else if (number % starting == 0)
		return false;
	

	return isPrime(number, starting + 1);
}

string SpaceReplacer(string value , int length) {
	string val;
	if (length < 0) {
		return "";
	}
	else if (value[length] == ' ')
		val = "_";
	else
		val = value[length];

	return SpaceReplacer(value, length - 1) + val;
}

