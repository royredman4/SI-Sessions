// Created by Roy Redman IV

#include <iostream>

using namespace std;

// Assignment #2
// Grabs the transactions from the user and saves it
// into the array
int GetTransactions(double[]);

// Assignment #3
// Calculates all transactions and returns the total to the main
double totalSpent(double[], int);

// Assignment #4/#5
// Allows you to seach an array and also change the transaction in the array
int EditArray(double[], int);

// Assignment #4
// Shows a menu of what the user wants to do
int Menu();

// Assignment #4
// Shows all the transactions the user made
void DisplayTransactions(double[], int);


const int SIZE = 200;


int main() {

	double transactions[SIZE];
	int size = GetTransactions(transactions);
	cout << "Your total spent is " << totalSpent(transactions, size) << endl;
	
	do {
		switch (Menu())
		{
		case 1:
			DisplayTransactions(transactions, size);
			break;
		case 2:
			size = EditArray(transactions, size);
			break;
		case 3:
			return 0;
		}
	} while (true);

}

int GetTransactions(double Ary[]) {
	int size = 0;
	double val;
	cout << "Please input your transaction (type \"-1\" when you are finished)" << endl;
	for (int i = 0; i < SIZE; ++i) {
		
		cout << "Transaction #" << i +1 << ": ";
		cin >> val;
		cout << endl;

		if (val != -1)
			Ary[i] = val;
		else
			return i;
	}
	cout << "No more transactions can be inputted, sorry!!";

}

double totalSpent(double Ary[], int size) {
	double total = 0;
	for (int i = 0; i < size; ++i)
		total += Ary[i];
	return total;
}

int Menu() {
	cout << "What would you like to do?" << endl << endl;
	int input;
	cout << "1. Show all transactions" << endl
		<< "2. change/delete a transaction amount based on transaction number" << endl
		<< "3. Quit" << endl;

	cin >> input;
	return input;
}

void DisplayTransactions(double Ary[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << "Transaction #" << i + 1 << " is "
			<<  Ary[i] << endl;
 	}
}

int EditArray(double Ary[], int size) {
	int val, option;
	double value;
	do{
		DisplayTransactions(Ary, size);
		cout << "What did you want to do?" << endl
			<< "1. Change a transaction to a different value" << endl
			<< "2. Delete a transaction" << endl
			<< "3. Exit changing/editing " << endl;
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Which transaction index did you want to change? " << endl
				<< "Transaction #: ";
			cin >> val;
			--val;
			if (val >= size || val < 0) { cout << "ERROR!! INPUTTED BAD NUMBER!!" << endl; break; }
			cout << "what value did you want to change it to?" << endl;
			cin >> value;
			Ary[val] = value;
			cout << "Change has been made sucessfully" << endl;
			break;
		case 2:
			cout << "Which transaction index did you want to Delete? " << endl
				<< "Transaction #: ";
			cin >> val;
			--val;
			if (val >= size || val < 0) { cout << "ERROR!! INPUTTED BAD NUMBER!!" << endl; break; }
			for (int i = val; i < size; ++i) {
				Ary[i] = Ary[i + 1];
			}
			--size;
			cout << "The transaction has been deleted" << endl;
			break;
		case 3:
			return size;
		}

	} while (true);

}