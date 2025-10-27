#define LED_PIN 11
#define BUTTON_PIN 2

const int brightnessMin = 13;
const int brightnessMax = 242;

int buttonState;
int lastButtonState = LOW;
int state = 0; 
int brightness;
bool fading = false;
int fadeDirection = 1;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 8;
unsigned long lastFadeTime = 0;
unsigned long fadeInterval = 10;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  analogWrite(LED_PIN, 0);
  brightness = 0;
}

void loop()
{
  handleButton();
  handleFading();
}

void handleButton()
{
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == HIGH) {
        state++;
        if (state > 3) state = 0;
        
        switch(state) {
          case 0: 
            fading = false;
            brightness = 0;
            analogWrite(LED_PIN, 0);
            break;
            
          case 1: 
            fading = true;
            fadeDirection = 1;
            brightness = brightnessMin;
            break;
            
          case 2: 
            fading = true;
            fadeDirection = -1;
            brightness = brightnessMax;
            break;
            
          case 3: 
            fading = false;
            brightness = brightnessMax;
            analogWrite(LED_PIN, brightnessMax);
            break;
        }
      }
    }
  }
  
  lastButtonState = reading;
}

void handleFading()
{
  if (!fading) return;
  
  if (millis() - lastFadeTime >= fadeInterval) {
    lastFadeTime = millis();
    brightness += fadeDirection * 2; 
    
    if (fadeDirection == 1 && brightness >= brightnessMax) {
      brightness = brightnessMax;
      fading = false;
    }
    else if (fadeDirection == -1 && brightness <= brightnessMin) {
      brightness = brightnessMin;
      fading = false;
    }
    analogWrite(LED_PIN, brightness);
  }
}