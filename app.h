#include "deck.h"
#include "hand.h"
#include "parser.h"
#include <unordered_map>

class App
{
public:
  App();
  void EditDeck();
  void EditHand();
  void ViewDeck();
  void ChangeActiveDeck();
  void DisplayHelp();

private:
  unordered_map<string, Deck> decks;
  string activeDeckLabel;
  Parser parser;
};