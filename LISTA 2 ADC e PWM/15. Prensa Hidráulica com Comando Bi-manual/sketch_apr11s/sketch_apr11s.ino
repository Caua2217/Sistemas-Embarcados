********************************************************

15. Prensa Hidráulica com Comando Bi-manual
Descrição: Para atender às normas de segurança (NR-12), uma prensa (LED 1) só pode
descer se o operador posicionar as duas mãos nos comandos.
O LED 1 só deve ser ativado se o Botão A e o Botão B forem pressionados com uma
diferença de tempo menor que 500ms entre eles. Se apenas um botão for pressionado, ou
se o tempo entre os dois for maior que o permitido, o sistema deve ignorar o comando e
acionar um LED de erro (LED 4).

********************************************************

const int botaoA = 2;
const int botaoB = 3;

const int prensa = 8; // LED 1
const int erro = 11;  // LED 4

unsigned long tempoA = 0;
unsigned long tempoB = 0;

bool A_pressionado = false;
bool B_pressionado = false;

bool erroAtivo = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);

  pinMode(prensa, OUTPUT);
  pinMode(erro, OUTPUT);
}

void loop() {
  bool A = digitalRead(botaoA) == LOW;
  bool B = digitalRead(botaoB) == LOW;

  unsigned long agora = millis();

  // Detecta pressão do botão A
  if (A && !A_pressionado) {
    A_pressionado = true;
    tempoA = agora;
  }

  if (!A) {
    A_pressionado = false;
  }

  // Detecta pressão do botão B
  if (B && !B_pressionado) {
    B_pressionado = true;
    tempoB = agora;
  }

  if (!B) {
    B_pressionado = false;
  }

  // =========================
  // LÓGICA BI-MANUAL
  // =========================

  if (A_pressionado && B_pressionado) {
    unsigned long diferenca = (tempoA > tempoB) ? (tempoA - tempoB) : (tempoB - tempoA);

    if (diferenca <= 500) {
      erroAtivo = false;
      digitalWrite(prensa, HIGH);
      digitalWrite(erro, LOW);
    } else {
      erroAtivo = true;
    }
  }

  // Se erro aconteceu
  if (erroAtivo) {
    digitalWrite(prensa, LOW);
    digitalWrite(erro, HIGH);
  }

  // Se nenhum comando válido
  if (!(A_pressionado && B_pressionado) && !erroAtivo) {
    digitalWrite(prensa, LOW);
    digitalWrite(erro, LOW);
  }
}

