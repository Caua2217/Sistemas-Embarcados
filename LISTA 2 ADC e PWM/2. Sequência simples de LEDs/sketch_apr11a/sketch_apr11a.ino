*****************************************************

2. Sequência simples de LEDs:
Descrição: Acionar 4 LEDs em sequência (efeito “corrida”), com intervalo de 200 ms entre
eles, utilizando controle não bloqueante (sem delay())

*****************************************************
const int leds[] = {8, 9, 10, 11};
const int totalLeds = 4;

unsigned long tempoAnterior = 0;
const int intervalo = 200;

int ledAtual = 0;

void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    // Apaga só o LED anterior
    digitalWrite(leds[ledAtual], LOW);

    // Avança para o próximo
    ledAtual = (ledAtual + 1) % totalLeds;

    // Liga o novo LED
    digitalWrite(leds[ledAtual], HIGH);
  }
}