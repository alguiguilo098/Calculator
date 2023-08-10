#pragma once
#include "CalculatorG.hpp"
#include "DisplayG.hpp"
#include <vector>
#include <windows.h> 
#include <unistd.h>   
class CpuG : public Cpu
{   
  public:
    Display* calculator_display;
    Keyboard* calculator_keyboard;
    float float_register_one=0;
    float float_register_two=0;
    float s;
    int a;
    int count_operator;
    Operator operetor;
    bool swap_register=true;
    Signal* signal_register_one;
    Signal* signal_register_two;
    Signal* signal_memory;
    int* pos_decimal_separetor_register_one;
    int* pos_decimal_separetor_register_two;
    int* pos_decimal_separetor_memory;
    int float_convert_int(float, int*);
    std::vector<Digit> *memory;
    std::vector<Digit> *resgister_one;
    std::vector<Digit> *resgister_two;
    float arthimetic(float, float, Operator);
    void percent_();
    void squart_();
    float convert_vector_in_float(std::vector<Digit>*, Signal*, int);
    Signal int_convert_vector(std::vector<Digit>*,int);
    CpuG();
    ~CpuG();
    void clearerror(std::vector<Digit>*, Signal *, int*);
    void addmemory();
    void subtractionmemory();
    void separetor();
    float float_memory;
    void show(std::vector<Digit>*, Signal*, int*);
    void equal();
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    void setDisplay(Display*);
    void setKeyboard(Keyboard *keyboard);
};
