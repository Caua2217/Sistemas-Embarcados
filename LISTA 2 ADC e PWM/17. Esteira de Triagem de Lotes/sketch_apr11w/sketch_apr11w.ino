********************************************************

17. Esteira de Triagem de Lotes
Descrição: Uma esteira transportadora (LED 1) move caixas que são detectadas por um
sensor de presença (Botão A).A esteira deve iniciar ao pressionar o Botão A. A cada 5 caixas detectadas pelo Botão B, a
esteira deve parar por 3 segundos para que um braço pneumático empurre o lote. Após
esse tempo, a esteira retoma automaticamente. O número total de caixas deve ser
monitorado e, ao atingir 20 caixas, o sistema para e aguarda um "Reset" pelo Botão A.


********************************************************

const int botaoA = 2;
const int botaoB = 3;

const int esteira = 8;

bool rodando = false;
bool fimSistema = false;

// contadores
int totalCaixas = 0;
int caixasLote = 0;

// controle de borda
bool ultimoB = HIGH;

// pausa
unsigned long tempoPausa = 0;
const unsigned long tempoParada = 3000;
bool emPausa = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(esteira, OUTPUT);
}

void loop() {
  bool A = digitalRead(botaoA) == LOW;
  bool B = digitalRead(botaoB) == LOW;

  unsigned long agora = millis();

  // =========================
  // RESET / START
  // =========================
  if (A) {
    rodando = true;
    fimSistema = false;
    totalCaixas = 0;
    caixasLote = 0;
    emPausa = false;
  }

  // =========================
  // SISTEMA FINALIZADO
  // =========================
  if (totalCaixas >= 20) {
    rodando = false;
    fimSistema = true;
  }

  // LED desligado se parado
  if (!rodando) {
    digitalWrite(esteira, LOW);
  }

  // =========================
  // EXECUÇÃO NORMAL
  // =========================
  if (rodando && !fimSistema) {

    // sensor de caixa (detecção de borda)
    if (ultimoB == HIGH && B == LOW) {
      totalCaixas++;
      caixasLote++;
    }
    ultimoB = B;

    // pausa a cada 5 caixas
    if (caixasLote >= 5 && !emPausa) {
      emPausa = true;
      tempoPausa = agora;
      digitalWrite(esteira, LOW);
    }

    // controle da pausa
    if (emPausa) {
      digitalWrite(esteira, LOW);

      if (agora - tempoPausa >= tempoParada) {
        emPausa = false;
        caixasLote = 0;
      }
    }

    // esteira rodando normalmente
    if (!emPausa) {
      digitalWrite(esteira, HIGH);
    }
  }
}