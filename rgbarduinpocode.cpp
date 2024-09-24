bool STATE_BUTTON = false;
bool PREVIOUS_STATE_BUTTON = false;
int STATE = 0;  // Using an integer for 3 states (0, 1, 2)

#define BUTTON 2   // PIN 02
#define RED 9      // PIN 09
#define GREEN 10   // PIN 10
#define BLUE 11    // PIN 11 (added for blue)

void setup(){
   Serial.begin(9600);
   pinMode(BUTTON, INPUT);
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);  // Added pin mode for blue
}

void loop(){
   STATE_BUTTON = digitalRead(BUTTON);

   if ((STATE_BUTTON == true) && (PREVIOUS_STATE_BUTTON == false)){
     delay(50);  // Debouncing the button
     STATE_BUTTON = digitalRead(BUTTON);
    
     if (STATE_BUTTON == true) {
        STATE = (STATE + 1) % 3;  // Cycles through 0, 1, and 2 (Red, Green, Blue)
     }
   }

   PREVIOUS_STATE_BUTTON = STATE_BUTTON;

   // Controlling the LEDs based on the STATE
   if (STATE == 0) {
     digitalWrite(RED, HIGH);
     digitalWrite(GREEN, LOW);
     digitalWrite(BLUE, LOW);
     Serial.println(F("RED\n"));
   } 
   else if (STATE == 1) {
     digitalWrite(RED, LOW);
     digitalWrite(GREEN, HIGH);
     digitalWrite(BLUE, LOW);
     Serial.println(F("GREEN\n"));
   } 
   else if (STATE == 2) {
     digitalWrite(RED, LOW);
     digitalWrite(GREEN, LOW);
     digitalWrite(BLUE, HIGH);
     Serial.println(F("BLUE\n"));
   }

   delay(150);  // A slight delay for stability
}

