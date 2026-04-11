********************************************************

3. Escalonamento (Barra de LEDs):
Descrição: Leia o Potenciômetro e acenda os LEDs de forma progressiva (tipo bargraph).
0-25% (nenhum LED), 25-50% (LED 1), 50-75% (LEDs 1 e 2), 75-90% (LEDs 1, 2 e 3) e
acima de 90% (todos os 4 LEDs acesos).

********************************************************


const int pot = A0;
const int leds[] = {8, 9, 10, 11};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int valor = analogRead(pot);

  // Apaga todos primeiro
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], LOW);
  }

  if (valor >= 256) digitalWrite(leds[0], HIGH);
  if (valor >= 512) digitalWrite(leds[1], HIGH);
  if (valor >= 768) digitalWrite(leds[2], HIGH);
  if (valor >= 921) digitalWrite(leds[3], HIGH);
}