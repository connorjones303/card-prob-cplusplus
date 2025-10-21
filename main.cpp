#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card
{
public:
  int count;
  string label;
};

class Hand
{
public:
  vector<Card> GetCards();
  vector<Card> AddCard(int count, string label);
  vector<Card> RemoveCard(int count, string label); // handles removing completely if count goes zeros
  void PrintHand();

private:
  vector<Card> cards;
  string label;
};

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

vector<Card> Hand::GetCards()
{
  return cards;
};

class Deck
{
public:
  vector<Card> GetHands();
  vector<Card> AddHand(int count, string label);
  vector<Card> RemoveHand(int count, string label); // handles removing completely if count goes zeros
  void PrintDeck();

private:
  vector<Card> cards;
  vector<Hand> hands;
  string label;
};

int main()
{
  string input;

  while (input != "qw")
  {
    cout << "type input:" << endl;
    cin >> input;
    cout << input << endl;
  }

  return 0;
}