********************************************************

11. Detector de Pulso Curto vs. Longo:
Descrição: Se o Botão A for pressionado por menos de 1 segundo, acenda o LED 1. Se
for pressionado por mais de 2 segundos, acenda o LED 2.

********************************************************

const int botao = 2;
const int led1 = 9;
const int led2 = 10;

unsigned long tempoInicio = 0;
bool pressionado = false;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  bool estado = digitalRead(botao) == LOW;

  // botão acabou de ser pressionado
  if (estado && !pressionado) {
    pressionado = true;
    tempoInicio = millis();
  }

  // botão acabou de ser solto
  if (!estado && pressionado) {
    pressionado = false;

    unsigned long duracao = millis() - tempoInicio;

    // limpa LEDs antes de decidir
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);

    if (duracao < 1000) {
      digitalWrite(led1, HIGH);
    }
    else if (duracao > 2000) {
      digitalWrite(led2, HIGH);
    }
  }
}