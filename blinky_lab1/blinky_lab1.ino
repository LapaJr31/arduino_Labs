const int DOT = 200;        
const int DASH = DOT * 3;   
const int GAP = DOT;        
const int LETTER_GAP = DOT * 3;  
const int WORD_GAP = DOT * 7;    

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Y: -.--
  dash();
  gap();
  dot();
  gap();
  dash();
  gap();
  dash();
  letterGap();
  
  // A: .-
  dot();
  gap();
  dash();
  letterGap();
  
  // R: .-.
  dot();
  gap();
  dash();
  gap();
  dot();
  
  delay(WORD_GAP);
}

void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DOT);
  digitalWrite(LED_BUILTIN, LOW);
}

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DASH);
  digitalWrite(LED_BUILTIN, LOW);
}

void gap() {
  delay(GAP);
}

void letterGap() {
  delay(LETTER_GAP);
}
