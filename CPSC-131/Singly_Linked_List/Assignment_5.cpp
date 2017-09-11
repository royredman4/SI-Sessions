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


// Allows to insert a node into any section in a linked list
Node* Insert_Helper(Node*, int, int);

// Outputs all of the nodes values inside the linked list
void Print_LL(Node*);

// Deletes the Linked List, preventing memory leaks
void Delete_LL(Node*);

int main() {
  int size = 0;
  int value = 0;
  Node* head = NULL;
  int index;

  do {
    cout << "\n\nWhat value would you like to input? (type \"-1\" to exit)\n";
    cout << "input: ";
    cin >> value;
    cout << "\n";
    if (value != -1) {
      if (size == 0) {
        head = new Node(value, NULL);
      }
  
      else {
	    Print_LL(head);
	do {
            cout << "You can insert this node between Node #1 and Node #" << size+1 << endl;
	    cout << "What index would you like to put it in?: ";
	    cin >> index;

	}while (index < 0 || index > size+1);
	
	head = Insert_Helper(head, value, index-1);
        
      }
    }
    size++;
  }while (value != -1);
  cout << "The final values are\n";
  Print_LL(head);
  Delete_LL(head);
}

Node* Insert_Helper(Node* head, int value, int index) {
  Node* newNode = NULL;
  if (index == 0) {
    newNode = new Node(value, head);
    head = newNode;
  }
  else {
    Node* tracer = head;
    for(int i = 0; i < index-1; ++i) {
      tracer = tracer->next;
    }

    tracer->next = new Node(value, tracer->next);
    
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