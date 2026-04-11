********************************************************

7. Frequência Variável:
Descrição: Utilize o Potenciômetro para controlar a velocidade de piscada do LED 2. No
valor mínimo do potenciômetro, o LED pisca a cada 2 segundos; no valor máximo, pisca a
cada 100ms.


********************************************************

const int pot = A0;
const int led = 10;

unsigned long tempoAnterior = 0;
bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);

  // Mapeia: quanto maior o valor, menor o tempo
  int intervalo = map(valor, 0, 1023, 2000, 100);

  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;
    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);
  }
}