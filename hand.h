#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Hand
{
public:
  Hand(string handLabel);
  Hand(string handLabel, unordered_map<string, int> handCards);
  unordered_map<string, int> GetHand();
  void ModHand(unordered_map<string, int>);
  void PrintHand();

private:
  unordered_map<string, int> cards;
  string label;
};