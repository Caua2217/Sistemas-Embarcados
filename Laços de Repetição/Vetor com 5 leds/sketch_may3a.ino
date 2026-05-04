//3. Montar vetor com cinco LEDs e acender um por vez.

int leds[] = {2, 3, 4, 5, 6};
int indexLed = 0;

unsigned long previousMillis = 0;
const long interval = 300;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], LOW);
    }

    digitalWrite(leds[indexLed], HIGH);

    indexLed++;
    if (indexLed >= 5) indexLed = 0;
  }
}