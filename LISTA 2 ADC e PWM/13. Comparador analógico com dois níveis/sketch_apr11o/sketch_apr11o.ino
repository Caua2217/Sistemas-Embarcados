********************************************************************************************

13. Comparador analógico com dois níveis:
Descrição: Utilizar o potenciômetro para definir dois níveis de operação:
Abaixo do nível 1 (menor ou igual a 2,0 V) → LED desligado
Entre nível 1 e 2 (entre 2,0 e 4,0 V) → LED piscando
Acima do nível 2 (maior ou igual a 4,0 V) → LED ligado.

********************************************************************************************

const int pot = A0;
const int led = 9;

const int nivel1 = 410;
const int nivel2 = 820;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 200;

bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);
  unsigned long agora = millis();

  // NÍVEL 1: desligado
  if (valor <= nivel1) {
    digitalWrite(led, LOW);
  }

  // NÍVEL 2: piscando
  else if (valor < nivel2) {
    if (agora - tempoAnterior >= intervalo) {
      tempoAnterior = agora;
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  }

  // NÍVEL 3: ligado fixo
  else {
    digitalWrite(led, HIGH);
  }
}