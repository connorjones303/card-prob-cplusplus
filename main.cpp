#include "app.h"
using namespace std;

int main()
{
  App app = App();
  while (true)
  {
    app.PromptCommand();
    app.ProcessCommand();
  }
  return 0;
}