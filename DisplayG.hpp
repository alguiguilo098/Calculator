#pragma once
#include "CalculatorG.hpp"
#include "Console.hpp"
  //toda vez que for digitar algo, crie um nomo terminal
class DisplayG:public Display{
    int row_cursor=5;
    int cols_cursor=0;
    Console s;
public:
    void add(Digit);
    void clear();
    void setSignal(Signal);
    void addDecimalSeparator();
};
