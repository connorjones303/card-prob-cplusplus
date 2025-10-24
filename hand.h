#include "card.h"
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Hand
{
public:
  Hand(int size, string label);
  int GetSize();
  unordered_map<string, int> GetHand();
  void AddCard(int count, string label);
  void RemoveCard(int count, string label); // handles removing completely if count goes zeros
  void PrintHand();

private:
  unordered_map<string, int> cards;
  string label;
  int size;
};