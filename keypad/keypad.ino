byte pinesFilas[] = {6,5,4,3}; 
byte pinesColumnas[] = {9,8,7}; 
char teclas[4][3] = {{'1','2','3'}, 
                     {'4','5','6'}, 
                     {'7','8','9'}, 
                     {'*','0','#'}};

String pwd1 = "1234";
String pwd2 = "4321";
String currentEntry;
bool alarmStatus = false;
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
bool checkPwd(String pwd) {
  if(pwd == pwd1) {
    Serial.println("Pass 1 OK");
    return true;
  } else if(pwd == pwd2) {
    Serial.println("Pass 2 OK");
    return true;
  }
  return false;
}

void toggleAlarmStatus() {
  alarmStatus = !alarmStatus;
  Serial.print("Alarm Status: ");
  Serial.println(alarmStatus);
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
          } else {
            if(checkPwd(currentEntry)) {
              toggleAlarmStatus();
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