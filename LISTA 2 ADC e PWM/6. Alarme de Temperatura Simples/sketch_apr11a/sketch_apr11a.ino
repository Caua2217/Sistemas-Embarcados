**********************************************************

6. Alarme de Temperatura Simples:
Descrição: Leia o sensor NTC. Se a leitura analógica ultrapassar um valor de referência
(ex: equivalente a 40°C), o LED 4 deve piscar rapidamente (intervalo de 100ms).

**********************************************************
const int ntc = A0;
const int led = 11;

const int limite = 650; // ajuste no Tinkercad

unsigned long tempoAnterior = 0;
const int intervalo = 100;

bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(ntc);
  unsigned long tempoAtual = millis();

  if (valor > limite) {
    // Pisca rápido
    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  } else {
    // Temperatura normal
    digitalWrite(led, LOW);
  }
}