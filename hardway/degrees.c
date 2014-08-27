// Copyright (c) 2014 Parker Harris Emerson
// Converts Celsius into Fahrenheit

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
  // enter the temp in Celsius
  int celsius;
  cout << "Enter the temperature in Celsius: ";
  cin >> celsius;

  // Convert
  int factor;
  factor = 212 - 32;
  int fahrenheit;
  fahrenheit = factor * celsius / 100 + 32;

  // Print
  cout << "Fahrenheit value is: ";
  cout << fahrenheit << endl;

  // Wait for user
  cout << "Press enter to continue..." << endl;
  cin.ignore(10, '\n');
  cin.get();
  return 0;
}
