
#define BIT3_MASK 

void setup() {
  // put your setup code here, to run once:
  unsigned char *portDDRB;
  unsigned char *portDataB;
  unsigned char *portPinB;
  
  portDDRB = (unsigned char *) 0x24;
  portDDRB = (unsigned char *) 0x25;
  portDDRB = (unsigned char *) 0x23;
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char *portPinB;
  portPinB = (unsigned char *) 0x23;

  unsigned char currentState;
  unsigned char previousState;
  
  currentState = (*portPinB) & BIT3_MASK;
  if (currentState != previousState){
    unsigned char *portB;
    portB = (unsigned char *) 0x25;
    *portB |= 0b00001000;
  }
  previousState = currentState;
}
