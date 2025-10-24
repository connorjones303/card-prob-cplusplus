#include "hand.h"
#include "card.h"
#include <unordered_map>
#include <vector>
using namespace std;

class Deck
{
public:
  double GetOddsFromHand(vector<Card> hand);
  Card GetCard(string name);
  Card RemoveCard(string name);
  vector<Hand> GetHands();
  vector<Hand> AddHand(int count, string label);
  vector<Hand> RemoveHand(int count, string label); // handles removing completely if count goes zeros
  void PrintDeck();

private:
  unordered_map<string, int> cards;
  int size;
  vector<Hand> hands;
  string label;
};
