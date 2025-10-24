#include "hand.h"
#include <vector>
#include <iostream>
using namespace std;

Hand::Hand(int startSize, string label)
{
  cards[label] = startSize;
  size = startSize;
}

int Hand::GetSize()
{
  return size;
}
void Hand::PrintHand()
{
  cout << "PRINTING HAND: " << label << endl;
  for (auto &elem : cards)
  {
    cout << "label: " << elem.first << " | count: " << elem.second << endl;
  }
}
void Hand::AddCard(int count, string label) // TODO: how will we handle adding a card that doesn't exist yet in deck?
{
  unordered_map<string, int>::iterator card = cards.find(label);
  if (card != cards.end())
  {
    cards[label] += count;
    size += count;
  }
  else
  {
    cards[label] = count;
    size += count;
  }
}

void Hand::RemoveCard(int count, string label)
{
  auto card = cards.find(label);
  if (card != cards.end())
  {
    if (card->second <= count)
    {
      size -= card->second; // remove only the remaining counts not more
      cards.erase(card);
    }
    else
    {
      card->second -= count;
      size -= count;
    }
  }
}

unordered_map<string, int> Hand::GetHand()
{
  return cards;
};