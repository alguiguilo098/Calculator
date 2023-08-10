#include "CalculatorG.hpp"
CalculatorErrorG::CalculatorErrorG(const char *message) {
  this->message = message;
}

char const *CalculatorErrorG::getMessage() { return this->message; }

void CalculatorG::setDisplay(Display* display) {
  this->display = display;
}

Display* CalculatorG::getDisplay() {
  return display;
}

void CalculatorG::setCpu(Cpu* cpu) {
  this->cpu = cpu;
}

Cpu* CalculatorG::getCpu() {
  return cpu;
}

void CalculatorG::setKeyboard(Keyboard* keyboard) {
  this->keyboard= keyboard;
}

Keyboard* CalculatorG::getKeyboard() {
  return keyboard;
}
