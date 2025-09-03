byte pinesFilas[] = {6,5,4,3}; 
byte pinesColumnas[] = {9,8,7}; 
char teclas[4][3] = {{'1','2','3'}, 
                     {'4','5','6'}, 
                     {'7','8','9'}, 
                     {'*','0','#'}};

String currentEntry;
void setup()
{
  for (int nL = 0; nL <= 3; nL++) {
     pinMode(pinesFilas[nL], OUTPUT);
     digitalWrite(pinesFilas[nL], HIGH);
  }
  for (int nC = 0; nC <= 2; nC++) {
     pinMode(pinesColumnas[nC], INPUT_PULLUP);
  } 
   
  Serial.begin(9600);
  Serial.println("Teclado 4x3");
  Serial.println();
}

void resetKeypad() {
  currentEntry = "";
  Serial.println("Reset keypad");
}

void loop()
{
    //Barrido por las filas
    for (int nL = 0; nL <= 3; nL++)
    {
      digitalWrite(pinesFilas[nL], LOW);
      
      //Barrido en columnas buscando un LOW
      for (int nC = 0; nC <= 2; nC++) {
        if (digitalRead(pinesColumnas[nC]) == LOW)
        {
          if(isDigit(teclas[nL][nC])) {
            currentEntry += teclas[nL][nC];
            Serial.println(currentEntry);
            }
            resetKeypad();
          }
          
          while(digitalRead(pinesColumnas[nC]) == LOW){}
        }
      }
      digitalWrite(pinesFilas[nL], HIGH);
    }
   delay(10);
}