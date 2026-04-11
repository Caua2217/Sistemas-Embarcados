********************************************************

16. Controle manual de velocidade com interface discreta
Descrição: Desenvolva um sistema de controle de velocidade para um motor, utilizando
dois botões:
• Um botão incrementa a velocidade
• Outro decrementa
A velocidade deve ser representada por um sinal PWM aplicado a um LED. O sistema deve
limitar os valores mínimo e máximo e evitar estouro de faixa.

********************************************************

const int botaoUp = 2;
const int botaoDown = 3;
const int motor = 9;

int velocidade = 0;
const int passo = 25;

bool ultimoUp = HIGH;
bool ultimoDown = HIGH;

void setup() {
  pinMode(botaoUp, INPUT_PULLUP);
  pinMode(botaoDown, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
}

void loop() {
  bool up = digitalRead(botaoUp);
  bool down = digitalRead(botaoDown);

  // =========================
  // AUMENTAR VELOCIDADE
  // =========================
  if (ultimoUp == HIGH && up == LOW) {
    velocidade += passo;
    if (velocidade > 255) velocidade = 255;
  }
  ultimoUp = up;

  // =========================
  // DIMINUIR VELOCIDADE
  // =========================
  if (ultimoDown == HIGH && down == LOW) {
    velocidade -= passo;
    if (velocidade < 0) velocidade = 0;
  }
  ultimoDown = down;

  analogWrite(motor, velocidade);
}