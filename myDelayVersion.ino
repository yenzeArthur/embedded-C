#define LEDMASK 0x01
#define COUNTOFFSET 15

void setup() {
  DDRB |= LEDMASK;

  TCCR2A = 0;    // normal mode
  TCCR2B = 0x07; // 1024x prescale
}

void loop() {
  PORTB |= LEDMASK;
  mydelay(120);
  PORTB &= -LEDMASK;
  mydelay(30);
}

void mydelay(int x)
{
  while(x){
    TCNT2 = COUNTOFFSET; //count up from the offset value to 255 then overflow
    TIFR2 = 1<<TOV2;      //clear flag, bit is set on overflow
    while( !(TIFR2 & (1<<TOV2)) );  //wait for overflow bit
    x--;
  }
}

