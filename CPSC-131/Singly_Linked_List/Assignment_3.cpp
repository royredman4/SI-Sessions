#include <iostream>

using namespace std;

// This would be the node container that would encompass the data and the pointer to the next node
struct Node{
    Node(int d, Node* n): data(d), next(n) {}

    // This would hold any input for each node
    int data;
    // This would allow a node to be connected to the next node
    Node* next;
};

// Creates the linked list and returns the head node
Node* Create_LL();

// Outputs all of the nodes values inside the linked list
void Print_LL(Node*);

// Deletes the Linked List, preventing memory leaks
void Delete_LL(Node*);

int main() {
  Node* head = Create_LL();
  Print_LL(head);
  Delete_LL(head);
}

Node* Create_LL() {
    Node* head = NULL;
    Node* tracer = head;
    int value = 0;

     while(value != -1)  {
      cout << "What value would you like to input? (type \"-1\" to exit)\n";
      cout << "input: ";
      cin >> value;
      cout << "\n";
      if (value != -1) {
	if (head == NULL) {
	  head = new Node(value, NULL);
	  tracer = head;
        }
	else {
          tracer->next = new Node(value, NULL);
          tracer = tracer->next;
        }
      }
     }

   return head;
}

void Print_LL(Node* head) {
  int i = 1;
  Node* tracer = head;
  while (tracer != NULL) {
    cout << "Node #" << i << " is " << tracer->data << endl;
    tracer = tracer->next;
    i++;
  }
  
}

void Delete_LL(Node* head) {
  Node* tracer = head;
  Node* current = head;
  while (current != NULL) {
    tracer = current;
    current = current->next;
    delete tracer;
  }
}