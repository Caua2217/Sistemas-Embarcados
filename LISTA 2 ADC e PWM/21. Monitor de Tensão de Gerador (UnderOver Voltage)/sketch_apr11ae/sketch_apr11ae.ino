********************************************************

21. Monitor de Tensão de Gerador (Under/Over Voltage)
Descrição: Um gerador deve fornecer uma tensão estável. O Potenciômetro simula a saída
do gerador (0 a 1023 representando 0 a 250 V).
Se a tensão estiver entre 210 V e 230 V, o LED 1 (Verde) fica aceso. Se cair abaixo de 210
V, o LED 2 (Amarelo) acende. Se subir acima de 230 V, o LED 3 (Vermelho) acende. Se a
tensão sair da faixa de segurança (< 180 V ou > 240 V) por mais de 2 segundos, o sistema
deve desligar uma chave geral (LED 4) por segurança.


********************************************************

const int pot = A0;

const int verde = 8;
const int amarelo = 9;
const int vermelho = 10;
const int chaveGeral = 11;

bool sistemaAtivo = true;

// timer de falha crítica
unsigned long tempoFalha = 0;
bool emFalhaCritica = false;

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(chaveGeral, OUTPUT);
}

void loop() {
  int leitura = analogRead(pot);

  // conversão para tensão (0–250V)
  float tensao = (leitura / 1023.0) * 250.0;

  unsigned long agora = millis();

  // =========================
  // DETECÇÃO DE FAIXA CRÍTICA
  // =========================
  if (tensao < 180 || tensao > 240) {
    if (!emFalhaCritica) {
      emFalhaCritica = true;
      tempoFalha = agora;
    }

    if (agora - tempoFalha >= 2000) {
      sistemaAtivo = false; // TRIP
    }
  } else {
    emFalhaCritica = false;
  }

  // =========================
  // CHAVE GERAL
  // =========================
  if (!sistemaAtivo) {
    digitalWrite(chaveGeral, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
    return;
  } else {
    digitalWrite(chaveGeral, HIGH);
  }

  // =========================
  // INDICAÇÃO NORMAL
  // =========================
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);

  if (tensao >= 210 && tensao <= 230) {
    digitalWrite(verde, HIGH);
  }
  else if (tensao < 210) {
    digitalWrite(amarelo, HIGH);
  }
  else if (tensao > 230) {
    digitalWrite(vermelho, HIGH);
  }
}