bool STATE_BUTTON = false;
bool PREVIOUS_STATE_BUTTON = false;
bool STATE = false;

#define BUTTON 2 // PIN 02
#define RED 9 // PIN 09
#define GREEN 10 // PIN 10

void setup(){
   Serial.begin(9600);
   pinMode(BUTTON, INPUT);
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT); 
}

void loop(){
  
   STATE_BUTTON = digitalRead(BUTTON);
 
  if ((STATE_BUTTON == true) && (PREVIOUS_STATE_BUTTON == false)){
     delay(50);
     STATE_BUTTON = digitalRead(BUTTON);
    
  if (STATE_BUTTON == true) {
     STATE = !STATE;
   }
  }
 
   PREVIOUS_STATE_BUTTON = STATE_BUTTON;
 
  if (STATE == true){
     digitalWrite(RED, LOW);
     digitalWrite(GREEN, HIGH);
     Serial.println(F("GO\n"));
  } 
  
  else{
     digitalWrite(RED, HIGH);
     digitalWrite(GREEN, LOW);
     Serial.println(F("STOP\n"));
  }
   delay(150);
}
