#include "Calculator.hpp"
#include "CalculatorG.hpp"
#include <iostream>
#include <vector>
class KeyboardLucio: public Keyboard{
    std::vector<Key*> keys;
    char keysCount = 0;
    Cpu* cpu;
  public:
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    Key* getKey(Digit);
    Key* getKey(Operator);
    Key* getKey(Control);
    Key* getKey(Symbol);
    void add(Key*); 
    void setCpu(Cpu*);
};

class KeyDigitLucio: public KeyDigit{
    Symbol symbol;
    Digit digit;
    Keyboard* keyboard;
  public:
    KeyDigitLucio(Symbol, Digit);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Digit getDigit();
};


class KeyControlLucio: public KeyControl{
    Symbol symbol;
    Control control;
    Keyboard* keyboard;
  public:
    KeyControlLucio(Symbol, Control);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Control getControl();
};


class KeyOperatorLucio: public KeyOperator{
    Symbol symbol;
    Operator operator_;
    Keyboard* keyboard;
  public:
    KeyOperatorLucio(Symbol, Operator);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Operator getOperator();
};

