#include "app.h"
using namespace std;

int main()
{
  while (true)
  {
    App app = App();
    app.PromptCommand();
    app.ProcessCommand();
  }
  return 0;
}