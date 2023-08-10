#pragma once
#include "Calculator.hpp"
#include "DisplayG.hpp"
#include "CPUG.hpp"


class CalculatorErrorG: public CalculatorError{
  const char* message;
  public:
   char const* getMessage();
   CalculatorErrorG(char const*);
};

class CalculatorG: public Calculator {
  Display* display;
  Cpu* cpu;
  Keyboard* keyboard;
  
public:
  virtual void setDisplay(Display*);
  virtual Display* getDisplay();
  virtual void setCpu(Cpu*);
  virtual Cpu* getCpu();
  virtual void setKeyboard(Keyboard*);
  virtual Keyboard* getKeyboard();
};