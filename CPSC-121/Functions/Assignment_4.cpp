// Created by Roy Redman IV

#include <iostream>

using namespace std;

// Calculates the users paywage based on hours
// spent working and their pay rate
void paywage_calc(double&);


// Reduces the users paycheck based on their
// taxes amount
void taxReducer(double&);

int main() {
  double paycheck = 0;

  paywage_calc(paycheck);
  cout << "Total paycheck amount before tex reductions is " << paycheck << endl;
  taxReducer(paycheck);
  cout << "Total paycheck amount after tax reductions is " << paycheck << endl;
  
  return 0;
}

void paywage_calc(double& total) {
  double total_hours = 0;
  double payrate = 0;
  double temp;
  for (int i = 0; i < 4; ++i) {
    cout << "How many hours did you work for week #" << i+1 << "? ";
    cin >> temp;
    total_hours += temp;
    cout << endl;
  }
  cout << "What is your payrate? ";
  cin >> payrate;

  total = total_hours * payrate;
}

void taxReducer(double& paycheck) {
  double taxPercent;
  
  cout << "How much percent of your paywage is based on taxes? ";
  cin >> taxPercent;
  if (taxPercent >= 1)
    taxPercent /=100;

  paycheck = paycheck - (paycheck * taxPercent);
}
