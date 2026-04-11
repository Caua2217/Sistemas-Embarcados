********************************************************

15. Sistema de segurança com acionamento bimanual
Descrição: Projete um sistema de segurança industrial onde uma máquina só pode ser
acionada mediante o pressionamento simultâneo de dois botões.
Caso apenas um botão seja pressionado, o sistema não deve permitir o acionamento. O
controle deve garantir simultaneidade real (janela de tempo pequena, por exemplo 200 ms).

********************************************************
const int botaoA = 2;
const int botaoB = 3;
const int maquina = 8;

unsigned long tempoA = 0;
unsigned long tempoB = 0;

bool A_pressionado = false;
bool B_pressionado = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(maquina, OUTPUT);
}

void loop() {
  bool A = digitalRead(botaoA) == LOW;
  bool B = digitalRead(botaoB) == LOW;

  // detectar borda de A
  if (A && !A_pressionado) {
    tempoA = millis();
    A_pressionado = true;
  }
  if (!A) A_pressionado = false;

  // detectar borda de B
  if (B && !B_pressionado) {
    tempoB = millis();
    B_pressionado = true;
  }
  if (!B) B_pressionado = false;

  // =========================
  // LÓGICA BIMANUAL
  // =========================
  if (A && B) {
    unsigned long diferenca =
      (tempoA > tempoB) ? (tempoA - tempoB) : (tempoB - tempoA);

    if (diferenca <= 200) {
      digitalWrite(maquina, HIGH);
    } else {
      digitalWrite(maquina, LOW);
    }
  } else {
    digitalWrite(maquina, LOW);
  }
}