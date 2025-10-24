#include "hand.h"
#include "card.h"
#include <vector>
using namespace std;

class Deck
{
public:
  Card GetCard(string name);
  Card RemoveCard(string name);
  vector<Hand> GetHands();
  vector<Hand> AddHand(int count, string label);
  vector<Hand> RemoveHand(int count, string label); // handles removing completely if count goes zeros
  void PrintDeck();

private:
  vector<Card> cards;
  vector<Hand> hands;
  string label;
};
