#include<stdint.h>

void setup() {
  // put your setup code here, to run once:
  DDRB |= 0x08;
  //DDRD |= 0x08;
  ADC_Init();
  // the following is done in two steps for clarity
  TCCR2A = (1<<WGM21) | (1<<WGM20);    // specify fast PWM
  TCCR2A = (1<<COM2A1) | (1<<COM2B1);  // add in non-inverting output

  TCCR2A = (1<<CS22); //prescale by 64x

  
}

void loop() {
  //nothing to do here!
  OCR2A = ADC_R(); // set duty cycles (0 through 255)
  //OCR2B = reads();  
}

void ADC_Init(){
  ADCSRA |= B11000000;  //set ADEN and ADSC equals to 1.
  ADMUX |= B11000000;   //set REFS1 and REFS0 to 1. set voltage references.     
}

void ADC_R(){
  ADMUX |= B00000100;   //we read A4.
  
  while(bit_is_set(ADCSRA, ADSC));
  delay(500);
  int8_t value = ADCL | (ADCH << 8); 
  return value;
}
