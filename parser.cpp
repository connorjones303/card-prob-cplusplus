#include <sstream>
#include <iostream>
#include "parser.h"
using namespace std;

Parser::Parser()
{
}

vector<string> Parser::UpdateTokens()
{
  cout << "Enter Command: ";
  string inputLine;
  getline(cin, inputLine);

  vector<string> inputTokens;
  string token;
  bool inQuotes = false;

  for (int i = 0; i < inputLine.length(); i++)
  {
    char c = inputLine[i];

    if (c == '"')
    {
      inQuotes = !inQuotes; // toggle inside quote state
      // don't add the quote character itself
    }
    else if (c == ' ' && !inQuotes)
    {
      // space outside quotes, end of token
      if (!token.empty())
      {
        inputTokens.push_back(token);
        token.clear();
      }
    }
    else
    {
      // regular char or space inside quotes
      token += c;
    }
  }

  // don't forget the last token
  if (!token.empty())
  {
    inputTokens.push_back(token);
  }

  tokens = inputTokens;
  return inputTokens;
}
vector<string> Parser::GetTokens()
{
  return tokens;
}