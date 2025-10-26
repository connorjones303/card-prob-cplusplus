#include "hand.h"
#include <vector>
#include <iostream>
using namespace std;

Hand::Hand(string label) : label(label)
{
  // empty hand with no cards in the unordered map
}

Hand::Hand(string label, unordered_map<string, int> handCards) : label(label), cards(handCards)
{
}

void Hand::PrintHand()
{
  for (auto &elem : cards)
  {
    cout << endl
         << "label: " << elem.first << " | count: " << elem.second << endl;
  }
}

unordered_map<string, int> Hand::GetHand()
{
  return cards;
};

void Hand::ModHand(unordered_map<string, int> newCards) // changes card counts, and deletes cards if needed
{
  for (auto &elem : newCards)
  {
    string cardLabel = elem.first;
    int cardCount = elem.second;
    cards[cardLabel] += newCards[cardLabel];
    if (cards[cardLabel] <= 0)
    {
      cards.erase(cardLabel);
    }
  }
}

int Hand::GetSize()
{
  int size = 0;
  for (const auto &elem : cards)
  {
    size += elem.second;
  }
  return size;
}