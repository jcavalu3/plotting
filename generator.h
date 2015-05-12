#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <iostream>
#include <chrono>
#include <random>
#include <limits>


class generator
{
 public:
  generator();
  generator(int minValue,int maxValue);
  int operator()();
 private:
  std::mt19937 numGenerator;
  unsigned seedVal;
  int min;
  int max;
  

};

#endif
