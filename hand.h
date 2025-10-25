#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Hand
{
public:
  Hand(string handLabel);
  Hand(string handLabel, unordered_map<string, int> handCards);
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