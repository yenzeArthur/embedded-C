/*interfacing a seven segment display with arduino uno using ansi C
the seven segment was connected in an order, the first segment to 
bit 7 and the last 'h', to bit 0*/

#define MASK 0b11111111
void MyDelay(unsigned long mSeconds);

void setup() {
  // put your setup code here, to run once:
  DDRD |= MASK; 
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD |= 0b10111111; //prints 0 and the dot
  MyDelay(1000);
  PORTD &= -(0b10111111); //releases the register
  MyDelay(1000);
  PORTD |= 0b01100001; //prints 1 and the dot
  MyDelay(1000);
  PORTD &= -(0b01100001); //releases the register
  MyDelay(1000);
  PORTD |= 0b11011011; //prints 2 and the dot
  MyDelay(1000);
  PORTD &= -(0b11011011); //releases the register
  MyDelay(1000);
  PORTD |= 0b11110011; //prints 3 and the dot
  MyDelay(1000);
  PORTD &= -(0b11110011);
  MyDelay(1000);
  PORTD |= 0b01100111; //prints 4 and the dot
  MyDelay(1000);
  PORTD &= -(0b01100111); //releases the register
  MyDelay(1000);
  PORTD |= 0b10110111; //prints 5 and the dot
  MyDelay(1000);
  PORTD &= -(0b10110111); //releases the register
  MyDelay(1000);
  PORTD |= 0b10111111; //prints 6 and the dot
  MyDelay(1000);
  PORTD &= -(0b10111111); //releases the register
  MyDelay(1000);
  PORTD |= 0b11100001; //prints 7 and the dot
  MyDelay(1000);
  PORTD &= -(0b11100001); //releases the register
  MyDelay(1000);
  PORTD |= 0b11111111; //prints 8 and the dot
  MyDelay(1000);
  PORTD &= -(0b11111111); //releases the register
  MyDelay(1000);
  PORTD |= 0b11100111; //prints 9 and the dot
  MyDelay(1000);
  PORTD &= -(0b11100111); //releases the register
  MyDelay(1000);
  
}
void MyDelay(unsigned long mSecondsApx){
  volatile unsigned long i;
  unsigned long endTime = 1000*mSecondsApx;
  for(i=0;i<=endTime; i++);
}

