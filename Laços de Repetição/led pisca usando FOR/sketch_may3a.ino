//Criar um programa que faça um LED piscar vinte vezes usando for.

const int ledPin = 13;
int count = 0;
bool ledState = false;
unsigned long previousMillis = 0;
const long interval = 200;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (count < 40) { // 20 piscadas = 40 trocas (liga/desliga)
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      ledState = !ledState;
      digitalWrite(ledPin, ledState);

      for (int i = 0; i < 1; i++) { // uso simbólico do for
        count++;
      }
    }
  }
}