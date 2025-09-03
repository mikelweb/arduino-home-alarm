const int LEDpin = LED_BUILTIN;
const long onDuration = 50;
const long offDuration = 950;
int LEDState;

long rememberTime=0;// this is used by the code

void setup() {
  pinMode(LEDpin, OUTPUT);// define LEDpin as output
  digitalWrite(LEDpin, LOW);// set initial state
}

void loop() {
 if(LEDState) {
    if( (millis() - rememberTime) >= onDuration){   
      LEDState = LOW;// change the state of LED
      rememberTime = millis();// remember Current millis() time
    }
 } else {
    if( (millis() - rememberTime) >= offDuration){     
      LEDState = HIGH;// change the state of LED
      rememberTime = millis();// remember Current millis() time
    }
 }

 digitalWrite(LEDpin, LEDState);

}