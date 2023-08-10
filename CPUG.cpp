#include "CPUG.hpp"
#include <cmath>
#include <iostream>
float CpuG::arthimetic(float number_one, float number_two, Operator operation) {
  switch (operation) {
  case SUM:
    return number_one + number_two;
    break;
  case SUBTRACTION:
    return number_one - number_two;
    break;
  case MULTIPLICATION:
    return number_one * number_two;
    break;
  case DIVISION:
    return number_one / number_two;
    break;
  default:
    throw CalculatorErrorG("Operation arthimetic not find");
    break;
  }
}
void CpuG::percent_(){
    if (swap_register){
      this->float_register_one=this->convert_vector_in_float(this->resgister_one,this->signal_register_one,*(this->pos_decimal_separetor_register_one));
      this->float_register_one /=100;
      int ax=this->float_convert_int(this->float_register_one,this->pos_decimal_separetor_register_one);
      *(this->signal_register_one)=this->int_convert_vector(this->resgister_one,ax);
    }else{
      this->float_register_two=this->convert_vector_in_float(this->resgister_two,this->signal_register_two,*(this->pos_decimal_separetor_register_two));
      this->float_register_two /=100;
      int ax=this->float_convert_int(this->float_register_two,this->pos_decimal_separetor_register_two);
      *(this->signal_register_one)=this->int_convert_vector(this->resgister_one,ax);
    }
}
void CpuG::squart_(){
    if (swap_register){
      if (*(this->signal_register_one)==NEGATIVE)throw CalculatorErrorG("Squart_root negative");
      this->float_register_one=this->convert_vector_in_float(this->resgister_one,this->signal_register_one,*(this->pos_decimal_separetor_register_one));
      this->float_register_one=std::sqrt(this->float_register_one);
      int ax=this->float_convert_int(this->float_register_one,this->pos_decimal_separetor_register_one);
      *(this->signal_register_one)=this->int_convert_vector(this->resgister_one,ax);
    }else{
      if (*(this->signal_register_one)==NEGATIVE)throw CalculatorErrorG("Squart_root negative");
      this->float_register_two=this->convert_vector_in_float(this->resgister_two,this->signal_register_two,*(this->pos_decimal_separetor_register_two));
      this->float_register_two=std::sqrt(this->float_register_two);
      int ax=this->float_convert_int(this->float_register_one,this->pos_decimal_separetor_register_one);
      *(this->signal_register_one)=this->int_convert_vector(this->resgister_one,ax);
      this->swap_register=false;
    }
}
int CpuG::float_convert_int(float number_float, int *pos_separetor_decimal){
  try {
    if (number_float != (int)number_float) {
      throw number_float;
    }
  } catch (float) {
    number_float = float_convert_int(10 * number_float, pos_separetor_decimal);
    (*pos_separetor_decimal)++;
  }
  return number_float;
}
float CpuG::convert_vector_in_float(std::vector<Digit> *array, Signal *signal,int p_seprator_decimal) {
  float vector_convert = 0.0;
  int tam = 0;
  int tam_orgin = array->size() - 1;
  while (tam <= tam_orgin) {
    vector_convert += array->back() * (pow(10, tam));
    array->pop_back();
    tam++;
  }

  for (int i = 0; i <p_seprator_decimal; i++) {
    vector_convert /= 10;
  }
  if (*signal == NEGATIVE) {
    vector_convert = (-1) * vector_convert;
  }
  return vector_convert;
}
void CpuG::receive(Operator opt) {
  if(this->count_operator>0) this->equal();
  this->operetor=opt;
  if (this->operetor==SQUARE_ROOT){
    this->calculator_display->clear();
    this->squart_();
    this->show(this->resgister_one, this->signal_register_one, this->pos_decimal_separetor_register_one);
  }else if(this->operetor == PERCENTAGE){
    this->calculator_display->clear();
    this->percent_();
    this->show(this->resgister_one, this->signal_register_one, this->pos_decimal_separetor_register_one);
  }
  else if(this->swap_register){
    int s=*(this->pos_decimal_separetor_register_one);
    this->float_register_one=convert_vector_in_float(this->resgister_one,this->signal_register_one,s);
    this->swap_register=false;
  this->count_operator++;
  }
}
Signal CpuG::int_convert_vector(std::vector<Digit> *array,int number) {
  Signal signal;
  std::vector<Digit> aux;
  if (number >= 0)
    signal = POSITIVE;
  if (number < 0)
    signal = NEGATIVE;
  number = std::abs(number);
  while (number > 0) {
    int unit = number % 10;
    number /= 10;
    switch (unit) {
    case 1:
      aux.push_back(ONE);
      break;
    case 2:
      aux.push_back(TWO);
      break;
    case 3:
      aux.push_back(THREE);
      break;
    case 4:
      aux.push_back(FOUR);
      break;
    case 5:
      aux.push_back(FIVE);
      break;
    case 6:
      aux.push_back(SIX);
      break;
    case 7:
      aux.push_back(SEVEN);
      break;
    case 8:
      aux.push_back(EIGHT);
      break;
    case 9:
      aux.push_back(NINE);
      break;
    case 0:
      aux.push_back(ZERO);
      break;
    }
  }
  while (!aux.empty()) {
    array->push_back(aux.back());
    aux.pop_back();
  }
  return signal;
}
void CpuG::receive(Digit Digits){
  switch (Digits){
  case ZERO:
    this->calculator_display->clear();
    if (swap_register){
      this->resgister_one->push_back(ZERO);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
      
    }else{
      this->resgister_two->push_back(ZERO);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case ONE:
    this->calculator_display->clear();
    if (swap_register){      
      this->resgister_one->push_back(ONE);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(ONE);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case TWO:
    this->calculator_display->clear();
    if (swap_register)
    {      
      this->resgister_one->push_back(TWO);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(TWO);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case THREE:
    this->calculator_display->clear();
    if (swap_register)
    { 
      this->resgister_one->push_back(THREE);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(THREE);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case FOUR:     
    this->calculator_display->clear();
    if (swap_register)
    { 
      this->resgister_one->push_back(FOUR);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(FOUR);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case FIVE:      
    this->calculator_display->clear();
    if (swap_register)
    { 
      this->resgister_one->push_back(FIVE);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(FIVE);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case SIX:      
    this->calculator_display->clear();
    if (swap_register)
    { 
      this->resgister_one->push_back(SIX);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(SIX);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case SEVEN:      
    this->calculator_display->clear();
    if (swap_register)
    { 
      this->resgister_one->push_back(SEVEN);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(SEVEN);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case EIGHT:      
    this->calculator_display->clear();
    if (swap_register)
    { 
      this->resgister_one->push_back(EIGHT);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(EIGHT);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  case NINE:      
    this->calculator_display->clear();
    if (swap_register)
    {
      this->resgister_one->push_back(NINE);
      this->show(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    }else{
      this->resgister_two->push_back(NINE);
      this->show(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    }
    break;
  }
}
void CpuG::receive(Control control){
  
  switch (control)
  {
  case EQUAL:
    if(!this->resgister_two->empty()){
      this->calculator_display->clear();
      this->equal();
      *(this->pos_decimal_separetor_register_two)=0;
      this->count_operator=0;
      *(this->pos_decimal_separetor_register_one);
      this->show(this->resgister_one, this->signal_register_one, this->pos_decimal_separetor_register_one);
    }
    break;
  case DECIMAL_SEPARATOR:

  if(this->resgister_one->empty() && this->swap_register){
    this->receive(ZERO);
  }
  if(this->resgister_two->empty() && !this->swap_register){
    this->receive(ZERO);
  }
    this->separetor();
    break;
  case OFF:
    delete this->calculator_display;
    this->~CpuG();
    break;
  case CLEAR_ERROR:
    this->clearerror(this->resgister_one,this->signal_register_one,this->pos_decimal_separetor_register_one);
    this->clearerror(this->resgister_two,this->signal_register_two,this->pos_decimal_separetor_register_two);
    this->clearerror(this->memory,this->signal_memory,this->pos_decimal_separetor_memory);
    break;
  case MEMORY_SUBTRCTION:
    this->subtractionmemory();
    this->swap_register = true;
    break;
  case MEMORY_READ_CLEAR:
    if(!this->memory->empty())this->clearerror(this->memory,this->signal_memory,this->pos_decimal_separetor_memory);
    else *(this->memory)=*(this->resgister_one);
    this->swap_register = false;
    break;
  case MEMORY_SUM:
    this->addmemory();
    this->swap_register = true; 
    break;
  default:
    throw CalculatorErrorG("Control not implement !!!");
    break;
  }
}
CpuG::CpuG(){
  this->resgister_one = new std::vector<Digit>;
  this->resgister_two = new std::vector<Digit>;
  this->memory = new std::vector<Digit>;
  this->count_operator=0;
  this->pos_decimal_separetor_memory = new int;
  *(this->pos_decimal_separetor_memory) = 0;
  this->pos_decimal_separetor_register_one = new int;
  *(this->pos_decimal_separetor_register_one) = 0;
  this->pos_decimal_separetor_register_two = new int;
  *(this->pos_decimal_separetor_register_two) = 0;
  this->signal_memory = new Signal;
  *signal_memory = POSITIVE;
  this->signal_register_one = new Signal;
  *signal_register_one = POSITIVE;
  this->signal_register_two = new Signal;
  *signal_register_two = POSITIVE;
  this->signal_register_two = new Signal;
}
CpuG::~CpuG() {
  this->resgister_one->~vector();
  this->resgister_two->~vector();
  delete this->pos_decimal_separetor_memory;
  delete this->pos_decimal_separetor_register_one;
  delete this->pos_decimal_separetor_register_two;
  delete this->signal_memory;
  delete this->signal_register_one;
  delete this->signal_register_two;
  delete this->calculator_display;
  this->memory->~vector();
}
void CpuG::show(std::vector<Digit>* array,Signal* signal, int*pos){
  int aux = *pos;
    
  if (*signal==NEGATIVE) this->calculator_display->setSignal(NEGATIVE);
  for (std::vector<Digit>::iterator it=array->begin();it!=array->end(); it++){
    this->calculator_display->add(*it);
    (*pos)--;
    if (*pos==1) this->calculator_display->addDecimalSeparator();
  }

  *pos = aux;
}
void CpuG::equal(){
  this->float_register_two=this->convert_vector_in_float(this->resgister_two,this->signal_register_two,*(this->pos_decimal_separetor_register_two));
  s=this->arthimetic(this->float_register_one,this->float_register_two,this->operetor);
  a=this->float_convert_int(s,this->pos_decimal_separetor_register_one);
  this->int_convert_vector(this->resgister_one,a);
  this->swap_register=true;
}
void CpuG::setDisplay(Display *display) {
  if (display != NULL) {
    this->calculator_display = display;
  }
}
void CpuG::setKeyboard(Keyboard *keyboard) {
  if (keyboard != NULL) {
    this->calculator_keyboard = keyboard;
  }
}
void CpuG::clearerror(std::vector<Digit> *array, Signal *signal,int *decimal_separator) {
  while (!array->empty()) {
    array->pop_back();
  }
  *signal = POSITIVE;
  *decimal_separator = 0;
}
void CpuG::addmemory(){

  float reg = this->convert_vector_in_float(this->resgister_two,this->signal_register_two,*(this->pos_decimal_separetor_register_two));

  this->float_memory=this->convert_vector_in_float(this->memory,this->signal_memory,*(this->pos_decimal_separetor_memory));
  this->float_memory+= reg;
  int aux=this->float_convert_int(this->float_memory,this->pos_decimal_separetor_memory);
  *(this->signal_memory)=this->int_convert_vector(this->memory,aux);
}
void CpuG::subtractionmemory(){

  this->float_memory=this->convert_vector_in_float(this->memory,this->signal_memory,*(this->pos_decimal_separetor_memory));
  this->float_memory-=this->convert_vector_in_float(this->resgister_two,this->signal_register_two,*(this->pos_decimal_separetor_register_two));
  int aux=this->float_convert_int(this->float_memory,this->pos_decimal_separetor_memory);
  *(this->signal_memory)=this->int_convert_vector(this->memory,aux);

}
void CpuG::separetor(){
  if (swap_register){
    *(this->pos_decimal_separetor_register_one)=this->resgister_one->size();
  }else if (!swap_register){
    *(this->pos_decimal_separetor_register_two)=this->resgister_two->size();
  }
}
