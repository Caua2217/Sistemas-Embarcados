********************************************************

20. Ciclo de Lavagem Industrial
Descrição: Uma máquina de lavar peças possui um ciclo automatizado com três etapas:
Enchimento, Lavagem e Drenagem.
Ao pressionar o Botão A, o ciclo inicia:
1. Enchimento (LED 1 aceso) por 4 segundos.
2. Lavagem (LED 2 e LED 3 piscando alternadamente em PWM a 50%) por 8
segundos.
3. Drenagem (LED 4 aceso) por 4 segundos. O ciclo não pode ser reiniciado
enquanto estiver em execução.

********************************************************

const int botao = 2;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

enum Estado { IDLE, ENCHIMENTO, LAVAGEM, DRENAGEM };
Estado estado = IDLE;

unsigned long tempoInicio = 0;

// controle PWM alternado
bool pwmState = false;
unsigned long tempoPWM = 0;

void setup() {
  pinMode(botao, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  bool A = digitalRead(botao) == LOW;
  unsigned long agora = millis();

  // =========================
  // INÍCIO DO CICLO
  // =========================
  if (A && estado == IDLE) {
    estado = ENCHIMENTO;
    tempoInicio = agora;
  }

  // =========================
  // ENCHIMENTO (4s)
  // =========================
  if (estado == ENCHIMENTO) {
    digitalWrite(led1, HIGH);

    if (agora - tempoInicio >= 4000) {
      estado = LAVAGEM;
      tempoInicio = agora;
      digitalWrite(led1, LOW);
    }
  }

  // =========================
  // LAVAGEM (8s) - PWM alternado
  // =========================
  if (estado == LAVAGEM) {

    if (agora - tempoPWM >= 200) { // alternância rápida (~50%)
      tempoPWM = agora;
      pwmState = !pwmState;

      analogWrite(led2, pwmState ? 255 : 0);
      analogWrite(led3, pwmState ? 0 : 255);
    }

    if (agora - tempoInicio >= 8000) {
      estado = DRENAGEM;
      tempoInicio = agora;

      analogWrite(led2, 0);
      analogWrite(led3, 0);
    }
  }

  // =========================
  // DRENAGEM (4s)
  // =========================
  if (estado == DRENAGEM) {
    digitalWrite(led4, HIGH);

    if (agora - tempoInicio >= 4000) {
      estado = IDLE;
      digitalWrite(led4, LOW);
    }
  }

  // =========================
  // SEGURANÇA: impede reinício durante ciclo
  // (já garantido pelo estado != IDLE)
  // =========================
}