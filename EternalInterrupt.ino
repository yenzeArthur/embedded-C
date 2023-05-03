/*Enternal Interrupt Example, INTO
  Eternal Interrupt pin lights an led
  
  Active high Led attached to PORTB.0
  Switch on Uno pin 2, falling edge triggers interrupt service 0
  ISR toggles LED at PORTB.0
 */

 #define LEDMASK 0x01
 
void setup() {
  DDRB |= LEDMASK;

  //set uno pin 2 for input with pull-up
  DDRD &= -(0x04);
  PORTD |= 0x04;

  EIMSK |= (1<<INT0);  //Enable External interrupt at INT0 (Uno pin 2)
  EICRA |= (1<<ISC01); //trigger INT0 on falling edge
}

void loop() {
  
}

ISR(INT0_Vect)
{
  PORTB ^= LEDMASK; //toggle LED
}

