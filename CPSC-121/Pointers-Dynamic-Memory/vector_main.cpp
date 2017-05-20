// Created by Roy Redman IV

#include <iostream>
#include <vector>
using namespace std;

// Gets the input of the users reciepts
void Get_Reciepts(vector<double>&);

// Gets the total of all reciepts
double Total_value(vector<double>&);

// Gets the Average of all reciepts
double Average_value(vector<double>&);


int main() {


  int x = 17;
  int* ptr = &x;

  cout << "the value of the variable is " << *ptr << endl;
  cout << "The address of that variable is at address: " << ptr << endl;
  cout << "As proof, here is the address of variable x: " << &x << endl;
  cout << "Finally, the address of the pointer itself is: " << &ptr << endl;

  // Assignment #4
  // Uses a vector instead of a dynamically manmade array with pointers
  vector<double> recieptArray;
  
  Get_Reciepts(recieptArray);

  cout << "The total amount spent is " << Total_value(recieptArray) << endl;
  cout << "The average cost spent is " << Average_value(recieptArray) << endl;
  
  return 0;
}

void Get_Reciepts(vector<double>& Ary) {
  int sz = int(Ary.size());
  double value;
  char user_input;
  do {
    cout << "How much was on reciept #" << sz+1 << ": ";
    cin >> value;
    Ary.push_back(value);
    
    ++sz;
    cout << "Would you like to add another reciept? (y/n)";
    cin.ignore();
    cin.get(user_input);
    
  }while(user_input == 'y' || user_input == 'Y');
  
}

double Total_value(vector<double>& Ary) {
  double total = 0;
  for (int i = 0; i < int(Ary.size()); ++i) {
    total += Ary[i];
  }
  return total;
  
}

double Average_value(vector<double>& Ary) {
  return Total_value(Ary)/int(Ary.size());
}
