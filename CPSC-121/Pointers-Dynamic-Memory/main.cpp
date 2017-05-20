// Created by Roy Redman IV
#include <iostream>

using namespace std;

// Collects all the reciepts from the user
void Get_Reciepts(double*, int);

// Collects all the reciepts from the user, assuming they
// don't know how many reciepts they have. This will
// return the size of the array when its finished

// If the reference is confusing, please reference to the following website
// http://stackoverflow.com/questions/1931218/c-allocating-dynamic-memory-in-a-function-newbie-question
int Get_Reciepts(double*&);

// Gets the total of all reciepts
double Total_value(double*, int);

// Gets the Average of all reciepts
double Average_value(double*, int);


int main() {

  // Assignment #1
  int x = 17;
  int* ptr = &x;

  cout << "the value of the variable is " << *ptr << endl;
  cout << "The address of that variable is at address: " << ptr << endl;
  cout << "As proof, here is the address of variable x: " << &x << endl;
  cout << "Finally, the address of the pointer itself is: " << &ptr << endl;

  int rec_size;

  // Assignment #2
  cout << endl << "How many reciepts do you have? (if you don't know, type \"-1\") ";
  cin >> rec_size;
  double* recieptArray = NULL;
	
  //Assignment #3
  if (rec_size != -1) {
    recieptArray = new double[rec_size];
    Get_Reciepts(recieptArray, rec_size);
  }

  else {
    rec_size = Get_Reciepts(recieptArray);
         
  }
  cout << "The total amount spent is " << Total_value(recieptArray, rec_size) << endl;
  cout << "The average cost spent is " << Average_value(recieptArray, rec_size) << endl;
  

  delete[] recieptArray;
  return 0;
}

int Get_Reciepts(double*& Ary) {
  double value;
  if (Ary != NULL) {
    cout << "Error!! Cannot extend a dynamic array without its current size, deleting original array now";
    delete[] Ary;
  }
  int max_capacity = 2;
  int total_reciepts = 0;
  char user_input;
  Ary = new double[max_capacity];
  double* temp_Ary = NULL;
  
  do {
    if (total_reciepts == max_capacity) {
      // Gives the old allocated array to temp_Ary to temporarly hold
      temp_Ary = Ary;

      // Creates a new dynamic array that is 2x the size of the old one
      max_capacity *= 2;
      Ary = new double[max_capacity];

      // Transfers all the old arrays contents into the newly created array
      for (int i = 0; i < total_reciepts; ++i) {
        Ary[i] = temp_Ary[i];
      }
      
      // Removes the old array since its not needed anymore
      delete[] temp_Ary;
      
    }
    cout << "How much was on reciept #" << total_reciepts + 1 << ": ";
    cin >> value;
    Ary[total_reciepts] = value;
    
    total_reciepts++;
    cout << "Would you like to add another reciept? (y/n)";
    cin.ignore();
    cin.get(user_input);
    
  }while(user_input == 'y' || user_input == 'Y');
  
  return total_reciepts;
}

void Get_Reciepts(double* Ary, int size) {
  cout << "please input your recipt costs:" << endl;
  for (int i = 0; i < size; ++i) {
    cout << "Receipt #" << i+1 << " cost: "; 
    cin >> Ary[i];
    cout << endl;
  }
}


double Total_value(double* Ary, int size) {
  double total = 0;
  for (int i = 0; i < size; ++i) {
    total += Ary[i];
  }
  return total;
  
}

double Average_value(double* Ary, int size) {
  return Total_value(Ary, size)/size;

}
