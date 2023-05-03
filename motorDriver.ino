
#define MOTOR_FORWARD 0b00000010
#define MOTOR_BACKWARD 0b00000100
//#define BUTTON_FORWARD 0b00010000
//#define BUTTON_BACKWARD 0b00100000

void setup() {
  // put your setup code here, to run once:
  DDRB |= MOTOR_BACKWARD; //set bit 2 to output 
  DDRB |= MOTOR_BACKWARD; //set bit 3 to output
  //PORTD &= -(BUTTON_FORWARD); //set bit 4 portd to input
  //PORTD &= -(BUTTON_BACKWARD); //set bit 4 portd to input
  
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  //unsigned char currentstate = 0;
  //unsigned char previousstate = 0;
  PORTB |= MOTOR_BACKWARD;
  PORTB |= MOTOR_BACKWARD;
  ADMUX |= B00000100;
  ADMUX |= B11000000;
  ADCSRA |= B11000000;        
  //MyDelay(10000000);
  while(bit_is_set(ADCSRA, ADSC));
  int value = ADCL | (ADCH << 8);    
}
/*void MyDelay(unsigned long mSecondsApx){
  volatile unsigned long i;
  unsigned long endTime = 1000*mSecondsApx;
  for(i=0;i<=endTime; i++);
}*/

