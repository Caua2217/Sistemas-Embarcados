//2. Criar um sistema que aguarde botão pressionado usando while.

const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  while (digitalRead(buttonPin) == HIGH) {
    // espera botão (não pressionado)
    // pode fazer outras tarefas aqui se quiser
  }

  digitalWrite(ledPin, HIGH); // acende ao pressionar
}