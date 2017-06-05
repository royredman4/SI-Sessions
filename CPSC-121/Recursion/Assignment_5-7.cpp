// Created by Roy Redman IV

#include <iostream>


// Assignment #5
// Adds up the total of the array
int array_total(int, int*, int);

// Assignment #6/7
// Fills the array with 0's and
// outputs the values backwards
void clean_array(int, int*, int);


using namespace std;


int main() {

  int ary[] = {12, 29, 33, 41, 1, 34, 87, 124, 11, 17};
  
  int array_size = (sizeof(ary)/sizeof(ary[0]));

  cout << "The total value of the array is "
       << array_total(0, ary, array_size) << endl;

  clean_array(0, ary, array_size);

  return 0;
}

int array_total(int index, int* ary, int arysize) {
  // If we are in the last index of the array,
  // send back the last index value to add and
  // recurse back to the original function call
  if (index == arysize-1)
    return ary[index];
  
  return ary[index] + array_total(index+1, ary, arysize);

}

void clean_array(int index, int* ary, int arysize) {
  // If we go outside of the array, go back
  if (index == arysize)
    return;

  ary[index] = 0;

  // Goes and makes a recursive call for the next values
  clean_array(index+1, ary, arysize);
  
  // Assignemnt #6 portion of the program
  cout << "Index " << index << " has the value "
       << ary[index] << endl;
  
}
