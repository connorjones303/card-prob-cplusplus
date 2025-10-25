#include "app.h"
#include <iostream>

App::App()
{
}

void App::EditDeck()
{
  auto tokens = parser.UpdateTokens();
  cout << "Edit Mode :: " << activeDeckLabel << endl;
}
void App::EditHand()
{
}
void App::ViewDeck()
{
}
void App::ChangeActiveDeck()
{
}
void App::DisplayHelp()
{

  cout << "Change Mode Commands\n"
       << "d <deck name>     -change active deck\n\n"
       << "v     -view deck mode\n"
       << "e     -edit deck mode\n"
       << "h      -display help"

       << "Edit Mode Commands:\n"
       << "new <hand name> [<card name> <card count>] ...   -create new hand\n"
       << "del <hand name>    -delete hand\n"
       << "add <card name> <card count>    -add card to deck\n"
       << "rm <card name> <card count>    -remove card from deck\n\n";
}