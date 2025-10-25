#include <sstream>
#include <iostream>
#include "parser.h"
using namespace std;

Parser::Parser()
{
  cout << "Enter Command: ";
  getline(cin, inputStream);
}

vector<string> Parser::UpdateTokens()
{
  cout << "Enter Command: ";
  string inputLine;
  getline(cin, inputLine);
  istringstream iss(inputLine);
  string token;
  vector<string> inputTokens;
  while (iss >> token)
  {
    inputTokens.push_back(token); // Read word by word whitespace-separated
  }
  tokens = inputTokens;
  return inputTokens;
}
vector<string> Parser::GetTokens()
{
  return tokens;
}