#define LED_PIN 11

const int brightnessMin = 13;
const int brightnessMax = 242;

int brightness;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    for (brightness = brightnessMin; brightness <= brightnessMax; brightness++ ) {
        analogWrite(LED_PIN, brightness);
        delay(30);
   }
    for (brightness = brightnessMax; brightness >= brightnessMin; brightness-- ) {
        analogWrite(LED_PIN, brightness);
        delay(30);
   }
}
