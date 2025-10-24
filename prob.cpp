#include "prob.h"

double GetHandOdds(int allHandCombinations, int oneHandCombination)
{
  return oneHandCombination / allHandCombinations;
}

int Factorial(int integer, int stopInt = 1) // stop int is exclusive number to stop the factorial multiplying at
{
  int factorialVal = 1;
  if (stopInt >= integer)
  {
    return 1;
  }
  for (integer; integer > stopInt; integer--)
  {
    factorialVal *= integer;
  }
  return factorialVal;
}

int Combination(int n, int k)
{
  int combinations = Factorial(n, (n - k)) / Factorial(k);
  // uses optimized combination function that cancels unneeded terms
  // ie. Combination(5, 2) becomes just (5 × 4) / (2 × 1)

  return combinations;
}