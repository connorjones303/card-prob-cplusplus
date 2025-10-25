#include <iostream>
#include <string>
#include "deck.h"
#include "hand.h"
using namespace std;

int main()
{
  string mode;

  while (mode != "qw")
  {
    cout << "type input:" << endl;
    cin >> mode;
    cout << mode << endl;
  }

  return 0;
}