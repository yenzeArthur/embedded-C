

void setup() {
  // put your setup code here, to run once:
  DDRB |= 0x08;
  PORTB |= 0x08;  
  TCCR2A |= (1<<COM2A1);
}

void loop() {
  // put your main code here, to run repeatedly:
  ADMUX |= B00000100;  //We read A4
  ADMUX |= B11000000;  //REFS1 AND REFS0 equal to 1
  ADCSRA |= B11000000; //ADEN and ADSC equal to 1

  while(bit_is_set(ADCSRA, ADSC));
  int value = ADCL | (ADCH << 8);
  OCR2A = value;
}
