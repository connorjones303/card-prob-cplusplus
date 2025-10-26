#include "deck.h"
#include "hand.h"
#include "prob.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <iomanip>
using namespace std;

Deck::Deck() : label("unnamed deck")
{
}
Deck::Deck(string deckName) : label(deckName)
{
}
double Deck::GetOddsFromHand(Hand hand)
{
  double odds;
  int combinationHand = 1;
  int combinationDeck = Prob::Combination(GetSize(), hand.GetSize());

  for (auto &elem : hand.GetHand())
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
  odds = odds = static_cast<double>(combinationHand) / combinationDeck; // cast int to double to avoid int division

  return odds;
}

void Deck::RemoveCard(int count, string cardLabel)
{
  auto card = cards.find(cardLabel);
  if (card == cards.end())
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
  if (hand == hands.end())
  {
    // do nothing if hand label to remove doesn't exist in a deck
    return;
  }
  else
  {
    hands.erase(handLabel);
  }
}
void Deck::AddHand(string label, unordered_map<string, int> handCards) // adds a hand if doesn't exist, or changes existing hand
{
  auto it = hands.find(label);
  if (it == hands.end())
  {
    // hand doesn't exist yet
    hands[label] = Hand(label, handCards);
  }
  else
  {
    it->second.ModHand(handCards);
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
  if (cards.empty())
  {
    cout << endl
         << "No cards exist in the deck" << endl;
  }
  else
  {
    cout << endl
         << "Deck Cards:\n";
    for (auto &elem : cards)
    {
      cout << "label: " << elem.first << " | count: " << elem.second << endl;
    }
  }
}
void Deck::PrintDeckHands()
{
  if (hands.empty())
  {
    cout << endl
         << "No Hands exist for the deck" << endl;
  }
  for (auto &elem : hands)
  {
    cout << endl
         << "hand label: " << elem.first << endl;
    elem.second.PrintHand();
    double odds = GetOddsFromHand(elem.second);
    cout << "probability: " << fixed << setprecision(2) << odds * 100 << "%" << endl;
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

int Deck::GetSize()
{
  int size = 0;
  for (const auto &elem : cards)
  {
    size += elem.second;
  }
  return size;
}