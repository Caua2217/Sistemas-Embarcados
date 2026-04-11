********************************************************

18. Controle de Velocidade de Esteira com Emergência
Descrição: Uma linha de montagem possui um controle de velocidade manual via
potenciômetro para o motor principal (LED 1 via PWM).
O motor deve seguir o valor do potenciômetro. No entanto, o sistema possui um Botão de
Emergência (Botão A). Se a emergência for acionada, o motor deve parar instantaneamente
e o LED de status (LED 2) deve piscar indicando falha crítica até que o sistema seja
reiniciado.

********************************************************


const int pot = A0;
const int botaoEmergencia = 2;

const int motor = 9;   // PWM
const int status = 8;  // LED falha

bool falha = false;

// pisca status
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 300;
bool estadoLed = false;

// controle botão
bool ultimoBotao = HIGH;

void setup() {
  pinMode(botaoEmergencia, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
  pinMode(status, OUTPUT);
}

void loop() {
  bool botao = digitalRead(botaoEmergencia) == LOW;
  unsigned long agora = millis();

  // =========================
  // DETECÇÃO DE EMERGÊNCIA
  // =========================
  if (ultimoBotao == HIGH && botao == LOW) {
    falha = true; // trava o sistema
  }
  ultimoBotao = botao;

  // =========================
  // MODO NORMAL
  // =========================
  if (!falha) {
    int valor = analogRead(pot);
    int pwm = map(valor, 0, 1023, 0, 255);

    analogWrite(motor, pwm);
    digitalWrite(status, LOW);
  }

  // =========================
  // MODO FALHA CRÍTICA
  // =========================
  else {
    // motor sempre desligado
    analogWrite(motor, 0);

    // pisca LED de status
    if (agora - tempoAnterior >= intervalo) {
      tempoAnterior = agora;
      estadoLed = !estadoLed;
      digitalWrite(status, estadoLed);
    }
  }
}