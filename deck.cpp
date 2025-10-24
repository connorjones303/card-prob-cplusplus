#include "deck.h"
#include "prob.h"

double Deck::GetOddsFromHand(vector<Card> hand)
{
  double odds;
  int combinationHand = 1;
  int combinationDeck = Prob::Combination(size, hand.size());
  // c(A in deck, A in hand) * c(B in deck, B in hand) * ... until hand is filled
  for (int i = 0; i < hand.size(); i++)
  {
    string cardName = hand[i].label;
    int cardCountInHand = hand[i].count;
    int cardCountInDeck = cards[cardName];
    combinationHand *= Prob::Combination(cardCountInDeck, cardCountInHand);
  }
  odds = combinationHand / combinationDeck;

  return odds;
}