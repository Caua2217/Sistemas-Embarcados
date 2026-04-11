********************************************************

8. Temporizador Reversível:
Descrição: Ao pressionar o Botão A, o LED 1 acende por 5 segundos. Se o Botão B for
pressionado durante esse tempo, o LED deve apagar imediatamente (função de
cancelamento)

********************************************************

const int botaoA = 2;
const int botaoB = 3;
const int led = 13;

unsigned long tempoInicio = 0;
bool ativo = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool A = digitalRead(botaoA) == LOW;
  bool B = digitalRead(botaoB) == LOW;

  // Inicia temporizador ao pressionar A
  if (A && !ativo) {
    ativo = true;
    tempoInicio = millis();
    digitalWrite(led, HIGH);
  }

  // Cancelamento imediato com B
  if (ativo && B) {
    ativo = false;
    digitalWrite(led, LOW);
  }

  // Verifica tempo de 5 segundos
  if (ativo && millis() - tempoInicio >= 5000) {
    ativo = false;
    digitalWrite(led, LOW);
  }
}