********************************************************

17. Sistema de alarme por condição crítica
Descrição: Projete um sistema de alarme baseado em leitura analógica (potenciômetro).
Quando o valor ultrapassar um limite crítico, o sistema deve entrar em estado de alerta,
sinalizado por LEDs piscando em alta frequência. Em condição normal, o sistema deve
permanecer em estado estável.

********************************************************

const int sensor = A0;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

const int limiteCritico = 800;

bool estadoAlarme = false;
bool estadoLed = false;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 100; // alta frequência

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int valor = analogRead(sensor);
  unsigned long agora = millis();

  // =========================
  // CONDIÇÃO CRÍTICA
  // =========================
  if (valor > limiteCritico) {
    estadoAlarme = true;
  } else {
    estadoAlarme = false;
  }

  // =========================
  // MODO NORMAL
  // =========================
  if (!estadoAlarme) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    return;
  }

  // =========================
  // MODO ALERTA (PISCANDO RÁPIDO)
  // =========================
  if (agora - tempoAnterior >= intervalo) {
    tempoAnterior = agora;
    estadoLed = !estadoLed;

    digitalWrite(led1, estadoLed);
    digitalWrite(led2, !estadoLed);
    digitalWrite(led3, estadoLed);
  }
}