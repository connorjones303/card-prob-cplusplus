#pragma once
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Hand
{
public:
  Hand() = default;
  Hand(string handLabel);
  Hand(string handLabel, unordered_map<string, int> handCards);
  unordered_map<string, int> GetHand();
  void ModHand(unordered_map<string, int>);
  void PrintHand();
  int GetSize();

private:
  unordered_map<string, int> cards;
  string label;
  int size;
};