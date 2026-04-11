*********************************************

1. Intertravamento de Segurança:
Descrição: Implemente uma lógica onde o LED 1 só pode ser ligado pelo Botão A se o
Botão B (atuando como uma chave de permissão) estiver pressionado simultaneamente.
Se o Botão B for solto, o LED 1 deve apagar imediatamente.

*********************************************
const int botaoA = 2;
const int botaoB = 3;
const int led1 = 13;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  bool A = digitalRead(botaoA) == LOW; // pressionado
  bool B = digitalRead(botaoB) == LOW; // pressionado

  if (A && B) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}