// Created by Roy Redman IV

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

// Assignment #2
// Fills  an array with 100,000 items
void FillArray(int[], int);

// Assignment #3
// Sorts the Array in order, using bubble sort
void BubbleSort(int[], int);

// Displays the full array to the screen
void DisplayArray(int[], int);

// Assignment #4
// Sorts the array using Selection Sort
void SelectionSort(int[], int);

// Assignment #5
// Searches for a value, assumed the array is in order
int BinarySearch(int[], int, int , int);


int main() {
  srand(time(NULL));
  const int SIZE = 100000;
  int Values[SIZE];
  FillArray(Values, SIZE);
  cout << "Before organizing" << endl;
  DisplayArray(Values, SIZE);
  cout << endl << "Press enter to continue: ";
  cin.get();
  cout << endl << "After organizing (please wait, it will take a while)" << endl;
  BubbleSort(Values, SIZE);
  // SelectionSort(Values, SIZE);
  DisplayArray(Values, SIZE);
  cout << endl << "Press enter to use the binary search";
  cin.get();
  int rand_val = rand() % 20000;
  cout << endl << "Now looking for the value " << rand_val << endl;
  int rand_index = BinarySearch(Values, 0, SIZE, rand_val);
  cout << endl << "The value was found at index " << rand_index << ": value = " << Values[rand_index]; 
  cout << endl << "Press the enter key to exit:";
  cin.get();
  
  return 0;
}

void FillArray(int Ary[], int size) {
  for (int i = 0; i < size; ++i) {
    Ary[i] = rand() % 20000 + 1;
  }
}


void DisplayArray(int Ary[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "Item #" << i+1 << " is: " << Ary[i] << endl;
  }
}

void BubbleSort(int Ary[], int size) {
  int temp;
  // checks if there was a swap.
  // If we loop through everything and there was
  // no swapping, then everything is in order
  bool swapOcurred = true;

  // We go through this constant checking at most
  // n times in order to guarantee that our array is sorted
  // or if we go through every index and there has been no swapping ocurred
  for (int i = 1; i < size && swapOcurred; ++i) {
    swapOcurred = false;

    // checks the current index and compares it to the one
    // next to its self if it is ordered or not.
    // does this for every index
    for (int j = 0; j < size-1; ++j) {

      if (Ary[j] > Ary[j+1]) {
        temp = Ary[j];
        Ary[j] = Ary[j + 1];
        Ary[j+1] = temp;
        swapOcurred = true;
      }
    }
  }
  

}

void SelectionSort(int Ary[], int size) {
  int temp;
  // This does the same thing over again until
  // we have done the same procedure n times
  for (int i = 0; i < size; ++i) {

    // Compares the previous index "i" to every
    // other index in the array, if the value of
    // Ary[i] is greater than Ary[j], then swap the
    // values around. Repeat with the other indexes
    for (int j = i+1; j < size; ++j) {
      if (Ary[i] > Ary[j]) {
        temp = Ary[i];
        Ary[i] = Ary[j];
        Ary[j] = temp;
      }
      
    }
  }
}

int BinarySearch(int Ary[], int first, int last, int searchValue) {
  int mid, low, high;
  mid = (first+last) / 2;
  low = mid -1;
  high = mid +1;

  // prevents from going out of bounds of the array
  if (last >= first) {

    // We have found the value
    if (Ary[mid] == searchValue)
      return mid;

    // if the value is greater than the value
    // in the middle of the array
    else if (searchValue > Ary[mid]) {
      // high is now the first value since we are wanting to
      // search the second half of the array (upper portion).
      // last is placed as last since the end of the second
      // half we are searching for is the last index of the array
      return BinarySearch(Ary, high, last,  searchValue);
    }

    // The value is less than the value of the middle index in
    // the array. If the value is in the array, then it must be
    // before the middle index of the array
    else {
      // first is there because the beginning of the left half
      // of the array is at the first index. Low is placed as the
      // last index, because for the left half of the array, we will
      // only be searching up until the middle -1
      return BinarySearch(Ary, first, low, searchValue);
    }
    
  }
  // If we go outside the bounds of our array and we still haven't
  // found the value in the array, then it isn't there
  else
    return -1;
  
}
