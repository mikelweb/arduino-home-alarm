const int LEDPin = LED_BUILTIN;
const int PIRPin = 2;
bool isArmed = false;

void setup()
{
  pinMode(LEDPin, OUTPUT);
  pinMode(PIRPin, INPUT);
  isArmed = true;
}

void loop()
{
  if( digitalRead(PIRPin) && isArmed )
  {
    digitalWrite(LEDPin, HIGH);
    delay(50);
    digitalWrite(LEDPin, LOW);
    delay(950);
  }
}