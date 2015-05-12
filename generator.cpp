#include "generator.h"

generator::generator():min(0),max(std::numeric_limits<int>::max())
{
  seedVal = std::chrono::system_clock::now().time_since_epoch().count();
  numGenerator.seed(seedVal);
}

generator::generator(int minValue,int maxValue):min(minValue),max(maxValue)
{
   seedVal = std::chrono::system_clock::now().time_since_epoch().count();
   numGenerator.seed(seedVal);
}

int generator::operator()()
{
  return numGenerator()%(max-min)+min;
}

