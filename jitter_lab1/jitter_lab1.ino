#define LED_PIN 11
#define BUTTON_PIN 2

int buttonState;
int ledState = HIGH;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 8;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, ledState);
}

void loop()
{
    int reading = digitalRead(BUTTON_PIN);

    if (reading != lastButtonState){
        lastButtonTime = millis();
        }

    if ((millis() - lastDebounceTime) > debounceDelay){
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == HIGH) {
                ledState = !ledState;
                }
        }
     }
     
    digitalWrite(LED_PIN, ledState);
    lastButtonState = reading;
}