#include "card.h"
#include <vector>
#include <string>
using namespace std;

class Hand
{
public:
  vector<Card> GetHand();
  vector<Card> AddCard(int count, string label);
  vector<Card> RemoveCard(int count, string label); // handles removing completely if count goes zeros
  void PrintHand();

private:
  vector<Card> cards;
  string label;
};