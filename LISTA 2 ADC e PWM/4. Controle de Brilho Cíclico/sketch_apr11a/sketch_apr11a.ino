********************************************************

4. Controle de Brilho Cíclico:
Descrição: A cada clique no Botão A, o brilho do LED 1 deve aumentar em 25% (0%, 25%,
50%, 75%, 100%). Ao chegar em 100%, o próximo clique deve retornar o brilho para 0%.

********************************************************

const int botao = 2;
const int led = 9;

int nivel = 0; // 0 a 4

bool estadoAnterior = HIGH;

int valoresPWM[] = {0, 64, 128, 191, 255};

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool estadoAtual = digitalRead(botao);

  // Detecta clique (transição HIGH -> LOW)
  if (estadoAnterior == HIGH && estadoAtual == LOW) {
    nivel++;
    if (nivel > 4) nivel = 0;

    analogWrite(led, valoresPWM[nivel]);
  }

  estadoAnterior = estadoAtual;
}