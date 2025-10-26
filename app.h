#pragma once
#include "deck.h"
#include "parser.h"
#include <unordered_map>
#include <vector>

class App
{
public:
  App();
  void DisplayHelp();
  bool ProcessCommand();
  void PromptCommand();

private:
  unordered_map<string, Deck> decks;
  string activeDeckLabel;
  Parser parser;
  bool ValidateCommand();
};