******************************************************************************

19. Forno de Tratamento Térmico com Histerese
Descrição: Um forno industrial precisa manter a temperatura entre 150°C e 160°C
(simulados por valores de leitura do NTC).
Ao ligar o sistema pelo Botão A, a resistência de aquecimento (LED 1) deve ser ligada.
Quando o NTC atingir o valor correspondente a 160°C, o aquecimento desliga. O
aquecimento só deve ser ligado novamente quando a temperatura cair para 150°C. O LED
2 deve indicar se o forno está dentro da faixa de trabalho (150-160).

******************************************************************************

const int sensor = A0;
const int botao = 2;

const int aquecimento = 8; // LED 1
const int status = 9;      // LED 2

// histerese (ajustável no Tinkercad)
const int LIMITE_LIGA = 600;   // 150°C
const int LIMITE_DESLIGA = 550; // 160°C

bool sistemaLigado = false;
bool aquecendo = false;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(aquecimento, OUTPUT);
  pinMode(status, OUTPUT);
}

void loop() {
  int valor = analogRead(sensor);
  bool botaoA = digitalRead(botao) == LOW;

  // =========================
  // LIGA SISTEMA
  // =========================
  if (botaoA) {
    sistemaLigado = true;
  }

  if (!sistemaLigado) {
    digitalWrite(aquecimento, LOW);
    digitalWrite(status, LOW);
    return;
  }

  // =========================
  // CONTROLE COM HISTERESE
  // =========================

  // desliga ao atingir alta temperatura
  if (valor < LIMITE_DESLIGA) {
    aquecendo = false;
  }

  // liga ao esfriar
  if (valor > LIMITE_LIGA) {
    aquecendo = true;
  }

  digitalWrite(aquecimento, aquecendo ? HIGH : LOW);

  // =========================
  // LED DE FAIXA IDEAL
  // =========================
  if (valor <= LIMITE_LIGA && valor >= LIMITE_DESLIGA) {
    digitalWrite(status, HIGH);
  } else {
    digitalWrite(status, LOW);
  }
}