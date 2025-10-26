#include "deck.h"
#include "hand.h"
#include "prob.h"
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

Deck::Deck(string deckName) : label(deckName)
{
}
double Deck::GetOddsFromHand(unordered_map<string, int> hand)
{
  double odds;
  int combinationHand = 1;
  int combinationDeck = Prob::Combination(size, hand.size());
  for (auto &elem : hand)
  {
    if (cards.find(elem.first) == cards.end())
    { // handle case when card in hand not in deck
      return 0;
    }
    else
    {
      // c(A in deck, A in hand) * c(B in deck, B in hand) * ... until hand is filled
      string cardName = elem.first;
      int cardCountInHand = elem.second;
      int cardCountInDeck = cards[cardName];
      combinationHand *= Prob::Combination(cardCountInDeck, cardCountInHand);
    }
  }
  odds = combinationHand / combinationDeck;

  return odds;
}

void Deck::RemoveCard(int count, string cardLabel)
{
  auto card = cards.find(cardLabel);
  if (card != cards.end())
  {
    // do nothing if card label to remove doesn't exist
    return;
  }
  else
  {
    if (cards.find(cardLabel)->second <= count)
    {
      cards.erase(cardLabel); // remove if removing count would become zero or less
    }
    else
    {
      cards.find(cardLabel)->second -= count;
    }
  }
}

void Deck::AddCard(int count, string cardLabel)
{
  unordered_map<string, int>::iterator card = cards.find(cardLabel);
  if (card != cards.end())
  {
    // add to already existing card
    cards[card->first] += count;
  }
  else
  {
    // make new card if not exists
    cards[cardLabel] = count;
  }
}

void Deck::RemoveHand(string handLabel)
{
  auto hand = hands.find(handLabel);
  if (hand != hands.end())
  {
    // do nothing if hand label to remove doesn't exist in a deck
    return;
  }
  else
  {
    hands.erase(handLabel);
  }
}

void Deck::AddHand(string handLabel, unordered_map<string, int> handCards = {})
{
  unordered_map<string, int>::iterator hand = cards.find(handLabel);
  if (hand == cards.end())
  {
    // make new card if not exists
    hands[handLabel] = Hand(handLabel, handCards);
  }
  else
  {
  }
}

unordered_map<string, int> Deck::GetCards()
{
  return cards;
}

unordered_map<string, Hand> Deck::GetHands()
{
  return hands;
}

void Deck::PrintDeckCards()
{
  for (auto &elem : cards)
  {
    cout << "label: " << elem.first << " | count: " << elem.second << endl;
  }
}
void Deck::PrintDeckHands()
{
  for (auto &elem : hands)
  {
    cout << "hand label: " << elem.first << endl;
    elem.second.PrintHand();
    cout << "probability: " << this->GetOddsFromHand(elem.second.GetHand());
  }
}

void Deck::ModCard(int count, string label)
{
  cards[label] += count;
  if (cards[label] <= 0)
  {
    cards.erase(label);
  }
}