#include <iostream>

using namespace std;

int main() {
  char first_word[8];
  char letter;
  int i = 0;
 
  // Assignment #2
  cout << "Please enter a 7 character word " << endl << "Answer: ";
  
  // Grabs each letter and puts it in the C-String
  while ( (i < 7) && (cin >> letter) ) {
   first_word[i] = letter;
   ++i;
  }
  first_word[i] = '\0';
  
  // Outputs the word
  i = 0;
  cout << "Your word is: ";
  while (first_word[i] != '\0') {
    cout << first_word[i];
    ++i;
  }
  cout << endl;
  
  char second_word[13];
  char third_word[13];
  char combined_word[25];
  i = 0;

  // Assignment #3
  cout << "Please enter a 12 character word " << endl << "Answer: ";

  // Grabs each letter and puts it in the C-String
  while ( (i < 12) && (cin >> letter) ) {
   second_word[i] = letter;
   ++i;
  }
  second_word[i] = '\0';
  
  cout << endl << "Please enter a second 12 character word " << endl << "Answer: ";
  i = 0;
  // Grabs each letter and puts it in the C-String
  while ( (i < 12) && (cin >> letter) ) {
   third_word[i] = letter;
   ++i;
  }
  third_word[i] = '\0';

  i = 0;
  //combines the two 12 character words together
  while (i < 24) {
    if (i < 12)
      letter = second_word[i];
    else
      letter = third_word[i%12];
    combined_word[i] = letter;
    ++i;
  } 
  combined_word[i] = '\0';

  // Outputs the word
  i = 0;
  cout << "Your combined word is: ";
  while (combined_word[i] != '\0') {
    cout << combined_word[i];
    ++i;
  }
  cout << endl;

  return 0;

}
