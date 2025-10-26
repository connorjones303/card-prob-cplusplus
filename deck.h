#pragma once
#include "hand.h"
#include <unordered_map>
using namespace std;

class Deck
{
public:
  Deck();
  Deck(string deckName);
  double GetOddsFromHand(Hand hand);
  unordered_map<string, Hand> GetHands();
  unordered_map<string, int> GetCards();
  void AddHand(string label, unordered_map<string, int> handCards = {});
  void RemoveHand(string label);
  void AddCard(int count, string label);
  void RemoveCard(int count, string label);
  void ModCard(int count, string label);
  void PrintDeckCards();
  void PrintDeckHands();
  int GetSize();

private:
  unordered_map<string, int> cards;
  unordered_map<string, Hand> hands;
  int size;
  string label;
};
