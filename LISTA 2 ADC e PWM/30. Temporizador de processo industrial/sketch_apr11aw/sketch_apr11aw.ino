********************************************************

18. Temporizador de processo industrial
Descrição: Desenvolva um sistema onde um botão inicia um ciclo de operação. Ao ser
acionado, um atuador (LED) deve permanecer ligado por um tempo pré-determinado (por
exemplo, 5 segundos), desligando automaticamente ao final.
O sistema deve utilizar controle por millis() e permitir reinicialização do ciclo.

********************************************************

const int botao = 2;
const int led = 8;

bool cicloAtivo = false;

unsigned long tempoInicio = 0;
const unsigned long tempoCiclo = 5000;

bool ultimoBotao = HIGH;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool b = digitalRead(botao);
  unsigned long agora = millis();

  // =========================
  // DETECÇÃO DE BORDA (INÍCIO)
  // =========================
  if (ultimoBotao == HIGH && b == LOW) {
    cicloAtivo = true;
    tempoInicio = agora;
    digitalWrite(led, HIGH);
  }

  ultimoBotao = b;

  // =========================
  // CONTROLE DO TEMPO
  // =========================
  if (cicloAtivo) {
    if (agora - tempoInicio >= tempoCiclo) {
      cicloAtivo = false;
      digitalWrite(led, LOW);
    }
  }
}