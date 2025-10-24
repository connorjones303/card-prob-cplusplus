#include "hand.h"
#include <vector>
#include <iostream>
using namespace std;

void Hand::PrintHand()
{
  cout << "PRINTING HAND: " << label << endl;
  for (int i = 0; i < sizeof(cards);)
  {
    cout << "label: " << cards[i].label << " | count: " << cards[i].count << endl;
  }
}
vector<Card> Hand::AddCard(int count, string label) // TODO: how will we handle adding a card that doesn't exist yet in deck?
{
  bool exists = false;
  for (int i = 0; i < sizeof(cards); i++)
  {
    if (cards[i].label == label)
    {
      cards[i].count += count;
      exists = true;
    }
  }
  if (!exists) // add new card if doesn't yet exist in hand
  {
    cards.push_back(Card{count, label});
  }
  return cards;
}

vector<Card> Hand::RemoveCard(int count, string label)
{
  for (int i = 0; i < sizeof(cards); i++)
  {
    if (cards[i].label == label)
    {
      if (count >= cards[i].count)
      { // remove from array if count exceeds current count in hand
        cards.erase(cards.begin() + i);
      }
      else
      {
        cards[i].count -= count;
      }
    }
  }
  return cards;
}

vector<Card> Hand::GetHand()
{
  return cards;
};