//5. Desenvolver semáforo automático usando arrays e repetição.

int leds[] = {2, 3, 4}; // vermelho, amarelo, verde
long tempos[] = {3000, 1000, 3000};

int estado = 0;
unsigned long previousMillis = 0;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= tempos[estado]) {
    previousMillis = currentMillis;

    for (int i = 0; i < 3; i++) {
      digitalWrite(leds[i], LOW);
    }

    digitalWrite(leds[estado], HIGH);

    estado++;
    if (estado >= 3) estado = 0;
  }
}