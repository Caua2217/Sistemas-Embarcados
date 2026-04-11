********************************************************

23. Máquina de Solda Ponto Automatizada
Descrição: Uma célula robotizada de solda precisa sincronizar o fechamento do eletrodo
com a passagem da corrente.
O operador posiciona a peça e pressiona o Botão A.
1. O sistema aguarda 800ms para estabilização mecânica.
2. O LED 1 (Atuador de pressão) acende.
3. Após 200ms, o LED 2 (Corrente de Solda) acende por 1,5 segundos em PWM
(potência ajustada pelo Potenciômetro).
4. O LED 2 apaga, mas o LED 1 permanece aceso por mais 500ms para
resfriamento da solda sob pressão.
5. O sistema libera a peça e acende o LED 3 (Pronto) por 2 segundos.

********************************************************

const int botao = 2;
const int pot = A0;

const int pressao = 8;
const int solda = 9;
const int pronto = 10;

// estados
enum Estado { IDLE, ESTABILIZA, PRESSAO, SOLDA, RESFRIA, FINAL };
Estado estado = IDLE;

unsigned long tempoInicio = 0;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(pressao, OUTPUT);
  pinMode(solda, OUTPUT);
  pinMode(pronto, OUTPUT);
}

void loop() {
  bool A = digitalRead(botao) == LOW;
  unsigned long agora = millis();

  // =========================
  // INÍCIO DO CICLO
  // =========================
  if (A && estado == IDLE) {
    estado = ESTABILIZA;
    tempoInicio = agora;
  }

  int pwm = map(analogRead(pot), 0, 1023, 0, 255);

  // =========================
  // ESTABILIZAÇÃO (800ms)
  // =========================
  if (estado == ESTABILIZA) {
    digitalWrite(pressao, LOW);
    digitalWrite(solda, LOW);
    digitalWrite(pronto, LOW);

    if (agora - tempoInicio >= 800) {
      estado = PRESSAO;
      tempoInicio = agora;
    }
  }

  // =========================
  // PRESSÃO (LED1)
  // =========================
  else if (estado == PRESSAO) {
    digitalWrite(pressao, HIGH);

    if (agora - tempoInicio >= 200) {
      estado = SOLDA;
      tempoInicio = agora;
    }
  }

  // =========================
  // SOLDA (PWM 1.5s)
  // =========================
  else if (estado == SOLDA) {
    analogWrite(solda, pwm);

    if (agora - tempoInicio >= 1500) {
      digitalWrite(solda, LOW);
      estado = RESFRIA;
      tempoInicio = agora;
    }
  }

  // =========================
  // RESFRIAMENTO (LED1 +500ms)
  // =========================
  else if (estado == RESFRIA) {
    digitalWrite(pressao, HIGH);

    if (agora - tempoInicio >= 500) {
      digitalWrite(pressao, LOW);
      estado = FINAL;
      tempoInicio = agora;
    }
  }

  // =========================
  // FINAL (LED3 2s)
  // =========================
  else if (estado == FINAL) {
    digitalWrite(pronto, HIGH);

    if (agora - tempoInicio >= 2000) {
      digitalWrite(pronto, LOW);
      estado = IDLE;
    }
  }
}