#include "app.h"
#include <iostream>
#include <vector>

App::App()
{
  decks["unnamed deck"] = Deck("unnamed deck");
  ;
  activeDeckLabel = "unnamed deck";
}
bool App::ValidateCommand()
{
  auto tokens = parser.GetTokens();

  if (tokens.empty())
  {
    return false;
  }

  string firstArg = tokens[0];

  if (firstArg == "d")
  {
    if (tokens.size() < 2)
    {
      cout << "Error: Missing deck name\n";
      cout << "Usage: d [-rm] <name>\n";
      return false;
    }

    if (tokens[1] == "-rm")
    {
      if (tokens.size() < 3)
      {
        cout << "Error: Missing deck name after -rm\n";
        cout << "Usage: d -rm <name>\n";
        return false;
      }
    }
    return true;
  }

  if (firstArg == "-h")
  {
    // Help command takes no arguments
    return true;
  }

  if (firstArg == "h")
  {
    if (tokens.size() < 2)
    {
      cout << "Error: Missing hand name\n";
      cout << "Usage: h <name> [-rm] [<card> <count>]...\n";
      return false;
    }

    // Check if -rm flag is present
    if (tokens.size() >= 3 && tokens[2] == "-rm")
    {
      // h <name> -rm (no additional args needed)
      return true;
    }

    // Check card/count pairs (starting at index 2)
    // tokens[0] = "h", tokens[1] = hand name, rest are pairs
    if ((tokens.size() - 2) % 2 != 0)
    {
      cout << "Error: Card/count pairs incomplete\n";
      cout << "Usage: h <name> [<card> <count>]...\n";
      return false;
    }

    // Validate alternating string/int pattern
    for (int i = 2; i < tokens.size(); i += 2)
    {
      if (i + 1 >= tokens.size())
        break;

      string cardName = tokens[i];
      string countStr = tokens[i + 1];

      // Check if card name is actually a number (invalid)
      try
      {
        stoi(cardName);
        cout << "Error: Card name cannot be a number: '" << cardName << "'\n";
        return false;
      }
      catch (...)
      {
        // Good - it's a string, not a number
      }

      // Check if count is a valid integer
      try
      {
        stoi(countStr);
      }
      catch (...)
      {
        cout << "Error: Count must be a valid integer, got: '" << countStr << "'\n";
        return false;
      }
    }

    return true;
  }

  if (firstArg == "c")
  {
    // All arguments after "c" should be card/count pairs
    if ((tokens.size() - 1) % 2 != 0)
    {
      cout << "Error: Card/count pairs incomplete\n";
      cout << "Usage: c [<name> <count>]...\n";
      return false;
    }

    // Validate alternating string/int pattern
    for (int i = 1; i < tokens.size(); i += 2)
    {
      if (i + 1 >= tokens.size())
        break;

      string cardName = tokens[i];
      string countStr = tokens[i + 1];

      // Check if card name is actually a number (invalid)
      try
      {
        stoi(cardName);
        cout << "Error: Card name cannot be a number: '" << cardName << "'\n";
        return false;
      }
      catch (...)
      {
        // Good - it's a string, not a number
      }

      // Check if count is a valid integer
      try
      {
        stoi(countStr);
      }
      catch (...)
      {
        cout << "Error: Count must be a valid integer, got: '" << countStr << "'\n";
        return false;
      }
    }
    return true;
  }

  if (firstArg == "v")
  {
    if (tokens.size() < 2)
    {
      cout << "Error: Missing view type\n";
      cout << "Usage: v <c|h|d>\n";
      return false;
    }

    if (tokens[1] != "c" && tokens[1] != "h" && tokens[1] != "d")
    {
      cout << "Error: Invalid view type '" << tokens[1] << "'\n";
      cout << "Usage: v <c|h|d>\n";
      return false;
    }

    return true;
  }

  // Unknown command
  cout << "Error: Unknown command '" << firstArg << "'\n";
  cout << "Type -h for help\n";
  return false;
}

void App::PromptCommand()
{
  auto tokens = parser.UpdateTokens();
}

bool App::ProcessCommand()
{
  vector<string> tokens = parser.GetTokens();
  bool validCommand = ValidateCommand();
  string firstArg = tokens[0];
  if (!validCommand)
  {
    return 0;
  }
  Deck &activeDeck = decks[activeDeckLabel];

  if (firstArg == "d")
  {
    if (tokens[1] == "-rm")
    {
      string deckToDelete = tokens[2];

      if (deckToDelete == activeDeckLabel && decks.size() == 1)
      {
        cout << "Error: Cannot delete the last remaining deck\n";
        return 1;
      }

      decks.erase(deckToDelete);

      // If deleting the active deck, switch to another one
      if (deckToDelete == activeDeckLabel && !decks.empty())
      {
        activeDeckLabel = decks.begin()->first;
      }

      return 1;
    }
    else
    {
      activeDeckLabel = tokens[1];
      return 1;
    }
  }

  if (firstArg == "h")
  {
    string handLabel = tokens[1];
    if (tokens[2] == "-rm")
    {
      activeDeck.RemoveHand(tokens[1]);
      return 1;
    }
    unordered_map<string, int> handCards;
    for (int i = 2; i < tokens.size(); i += 2)
    {
      string label = tokens[i];
      int count = stoi(tokens[i + 1]);
      handCards[label] = count;
    }
    activeDeck.AddHand(handLabel, handCards);
    return 1;
  }
  if (firstArg == "-h")
  {
    DisplayHelp();
    return 1;
  }

  if (firstArg == "c")
  {
    for (int i = 1; i < tokens.size(); i += 2)
    {
      string cardLabel = tokens[i];
      int count = stoi(tokens[i + 1]);
      activeDeck.ModCard(count, cardLabel);
    }
    return 1;
  }

  if (firstArg == "v")
  {
    if (tokens[1] == "c")
    {
      activeDeck.PrintDeckCards();
      return 1;
    }
    if (tokens[1] == "h")
    {
      activeDeck.PrintDeckHands();
      return 1;
    }
    if (tokens[1] == "d")
    {
      cout << "All Decks:" << endl;
      for (auto &elem : decks)
      {
        cout << "Deck: " << elem.first << " | Deck Size: " << elem.second.GetSize()
             << " | # Of Hands: " << elem.second.GetHands().size() << endl;
      }
      cout << "Current Deck: " << activeDeckLabel << endl;

      return 1;
    }
  }
  return 0; // return false if not caught in other conditions
}
void App::DisplayHelp()
{
  cout << "Commands:\n\n"
       << "d [-rm] <name>\n"
       << "  Change active deck\n"
       << "  Arguments:\n"
       << "    name - Deck name (creates new if doesn't exist)\n\n"
       << "    -rm - deletes Deck at deck name\n\n"

       << "-h\n"
       << "  Display help\n\n"

       << "h <name> [-rm] [<card> <count>]...\n"
       << "  Create or modify a hand\n"
       << "  Arguments:\n"
       << "    name  - Hand name (creates new if doesn't exist)\n"
       << "    -rm   - Remove hand\n"
       << "    card  - Card name (optional, repeatable)\n"
       << "    count - Number to add (positive) or remove (negative)\n"
       << "  Examples:\n"
       << "    h hand1\n"
       << "    h hand1 \"Ace of Spades\" 2\n"
       << "    h hand1 \"Ace of Spades\" 2 \"King of Hearts\" -1\n\n"

       << "c [<name> <count>]...\n"
       << "  Add or remove cards from deck\n"
       << "  Arguments:\n"
       << "    name  - Card name\n"
       << "    count - Number to add (positive) or remove (negative)\n"
       << "  Examples:\n"
       << "    c \"Queen of Diamonds\" 3\n"
       << "    c \"Queen of Diamonds\" -2\n\n"

       << "v <c|h|d>\n"
       << "  View deck contents\n"
       << "  Arguments:\n"
       << "    c - View all cards in deck\n"
       << "    h - View all hands in deck\n"
       << "    d - View all decks\n"
       << "  Examples:\n"
       << "    v c\n"
       << "    v h\n"
       << "    v d\n";
}