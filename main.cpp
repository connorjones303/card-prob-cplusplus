#include <iostream>
#include <string>
#include "deck.h"
#include "hand.h"
#include "card.h"
using namespace std;

int main()
{
  string input;

  while (input != "qw")
  {
    cout << "type input:" << endl;
    cin >> input;
    cout << input << endl;
  }

  return 0;
}