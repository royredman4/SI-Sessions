#include <iostream>

using namespace std;

const int GIGABYTE = 1000000000;

//This creates the memory leak based on how large the user chooses
void Memory_Leak(int);
//Outputs the menu that asks for how much memory to leak
int Display_Choice();

struct Node{
    Node(int d, Node* n): data(d), next(n) {}

    int data;
    Node* next;
};

int main() {
  double memory_leak_total = 0;
  int leak_size;
  int choice;
  do {
      choice = Display_Choice();
      leak_size = GIGABYTE/choice;

      if (choice != -1) {  
        Memory_Leak(leak_size/sizeof(Node));
        memory_leak_total += 1/choice;
        cout << "You have leaked a total of " << memory_leak_total << "Gigabytes\n\n";
      }

  } while(choice != -1);
  return 0;

}

int Display_Choice() {
  int choice;
  do {

    cout << "-----------------Memory Leaker-----------------\n";
    cout << "How much memory would you like to leak?\n";
    cout << "1) 1 Gigabyte\n";
    cout << "2) 1/2 Gigabyte (500 Megabytes)\n";
    cout << "3) Quit program\n";
    cin >> choice;
    

  } while( choice < 1 && choice > 3);
  
  if (choice == 3)
    choice = -1;

  return choice;
}


void Memory_Leak(int size) {

  Node* head = new Node(0, NULL);
  Node* tracer = head;
  for(int i = 1; i < size; ++i) {
    tracer->next = new Node(i, NULL);
    tracer = tracer->next;
  }
}
