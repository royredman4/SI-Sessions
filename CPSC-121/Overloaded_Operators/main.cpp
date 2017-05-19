// Created by Roy Redman IV

#include "dogs.h"
#include <iostream>
#include <string>

// Randomizes and creates the dogs information
void Randomizer(Dogs[]);

// Sorts the dogs into order by age, youngest to oldest
void SortAge(Dogs[]);

// Reduces the price of a dog by a passed percentage amount
// based on the dogs age
void ReduceAgeValues(Dogs[], int, double);

using namespace std;

const int SIZE = 35;


int main() {
  // Creates an array with temporary values (for demonstration)
  Dogs DogShop[SIZE] {{"Balto", "Husky", 10, 200.00, 5}, {"Airbud", "Golden Retriever", 4, 500.00, 2}};

  // Uses the overloaded operator to output its information
  cout << DogShop[0] << DogShop[1];

  // Compares between two dogs with overloaded operators
  if (DogShop[0] < DogShop[1]) {
    cout << "I am choosing the first dog" << endl;
  }
  
  // Compares between two dogs with overloaded operators
  else if (DogShop[0] > DogShop[1]) {
    cout << "I am choosing the second dog" << endl;
  }
  
  // If they are neither of the previous two,
  // then they are the same age
  else {
    cout << "The dogs are the same age" << endl;
  }

  Randomizer(DogShop);
  SortAge(DogShop);

  // Outputs the dogs before they are organized
  cout << "Before Dog" << endl;
  for (int i = 0; i < SIZE; ++i)
    cout << DogShop[i] << endl;
  
  ReduceAgeValues(DogShop, 9, .40);

  // Outputs dogs after they are organized
  cout << "After dogs" << endl;
  for (int i = 0; i < SIZE; ++i)
    cout << DogShop[i] << endl;
  
}


struct DogInfo {
  string breed;
  double cost;
  DogInfo(string bd, double cst):breed(bd), cost(cst) {}
};


// Assignment #4
void Randomizer(Dogs DgShop[]) {
  #include <time.h>
  #include <stdlib.h>
  const int temp_size = 11;
  DogInfo TempDogs[temp_size] = {{"Great Dane", 2399.00}, {"German Sheperd", 1860.00},
                                 {"American Foxhound", 255.00},{"Beagle", 875.00},
                                 {"Tiberian Mastiff", 3517.00}, {"Border Collie", 525.00},
                                 {"Dachshund", 500.00}, {"Basset Hound", 400.00}, {"Pug", 350.00},
                                 {"Corgi", 600.00}, {"Labrador Retriever", 800.00}};


  string DogNames[temp_size] = {"Balto", "Duke", "Sadie", "Wilfred", "Pluto", "Bandit", "Baxter",
                                "Molly", "Bailey", "Lola", "Coco"};

  srand(time(0));
  int dogIndex;

  // Setting dogs information based on random array/struct info
  for (int i = 0; i < SIZE; ++i) {
    DgShop[i].Setage(rand() % 11 + 1);
    dogIndex = rand() % temp_size; 
    DgShop[i].Setbreed(TempDogs[dogIndex].breed);
    DgShop[i].Setname(DogNames[rand() % temp_size]);
    DgShop[i].Setcost(TempDogs[dogIndex].cost);
  }
}

// Assignment #4
void SortAge(Dogs DgShop[]) {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = i+1; j < SIZE; ++j) {
      if (DgShop[i] < DgShop[j]) {}
      
      else if (DgShop[i] > DgShop[j]) {
          Dogs temp = DgShop[i];
          DgShop[i] = DgShop[j];
          DgShop[j] = temp;
      }
        else {}
    }
  }

}

// Assignment #4
void ReduceAgeValues(Dogs DgShop[], int age, double reductionPrice) {

  // converts whole number to percentage value
  if (reductionPrice >= 1) {
    reductionPrice /= 100;
  }
  for (int i = 0; i < SIZE; ++i) {
    if (DgShop[i].Getage() >= age) {
      DgShop[i].Setcost(DgShop[i].Getcost() - (DgShop[i].Getcost() * reductionPrice));
    }
  }
}
