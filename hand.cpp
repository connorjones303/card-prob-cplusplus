#include "hand.h"
#include <vector>
#include <iostream>
using namespace std;

Hand::Hand(string label) : label(label), size(0)
{
  // empty hand with no cards in the unordered map
}

Hand::Hand(string label, unordered_map<string, int> handCards) : label(label), cards(handCards)
{
  size = 0;
  for (auto &elem : handCards)
  {
    elem.second += size; // add to size of hand for each count of each count of each card in hand
  }
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
void Hand::AddCard(int count, string label) // TODO: how will we handle adding a card to a hand that doesn't exist yet in deck?
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