// Created by Roy Redman IV

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main() {

  string filename = "coins.txt";
  string quarter, dime, nickel, penny;
  int qcount, dcount, ncount, pcount;
  ifstream in(filename);

  if(in.is_open()) {
    in >> quarter >> qcount;
    in >> dime >> dcount;
    in >> nickel >> ncount;
    in >> penny >> pcount;
  }
  
  else {
    quarter = "Quarter";
    dime = "Dime";
    nickel = "Nickel";
    penny = "Penny";
    qcount = dcount = ncount = pcount = 0;
  }
  in.close();
  
  cout << "Here is your coin count" << endl;
  cout << quarter << ":" << qcount << endl;
  cout << dime << ":" << dcount << endl;
  cout << nickel << ":" << ncount << endl;
  cout << penny << ":" << pcount << endl;
  cout << "Total value is: " << (qcount *25) + (dcount *10) + (ncount * 5) + pcount << " cents" << endl << endl;

  int input, value;
  do {
    cout << "What would you like to input?" << endl;
    cout << "1. Quarters" << endl;
    cout << "2. Dimes" << endl;
    cout << "3. Nickels" << endl;
    cout << "4. Pennies" << endl;
    cout << "5. Exit" << endl;
    cin >> input;

    switch (input) {
      case 1: {
        cout << "How many Quarters are you adding? " << endl;
        cin >> value;
        qcount += value;
        break;
      }
      case 2: {
        cout << "How many Dimes are you adding? " << endl;
        cin >> value;
        dcount += value;
        break;
      }
      case 3: {
        cout << "How many Nickels are you adding? " << endl;
        cin >> value;
        ncount += value;
        break;
      }
      case 4: {
        cout << "How many Pennies are you adding? " << endl;
        cin >> value;
        pcount += value;
        break;
      }
default:
        break;
    }
                                    
  } while (input < 5 &&  input > 0);

  ofstream output(filename);
  output << quarter << " " << qcount << endl;
  output << dime << " " << dcount << endl;
  output << nickel << " " << ncount << endl;
  output << penny << " " << pcount << endl;

  output.close();
  return 0;
}
