#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Parser
{
public:
  Parser();
  vector<string> UpdateTokens();
  vector<string> GetTokens();

private:
  vector<string> tokens;
  string inputStream;
};