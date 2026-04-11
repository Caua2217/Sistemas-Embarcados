********************************************************

14. Monitoramento de nível com sinalização escalonada
Descrição: Implemente um sistema de monitoramento de nível de um reservatório,
utilizando um potenciômetro como sensor.
O sistema deve classificar o nível em faixas (baixo, médio, alto) e sinalizar por meio de
LEDs distintos. Em condição crítica (nível muito baixo ou muito alto), o sistema deve emitir
um alerta visual piscante

********************************************************

const int sensor = A0;

const int baixo = 8;
const int medio = 9;
const int alto = 10;
const int alerta = 11;

bool estadoAlerta = false;
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 300;

void setup() {
  pinMode(baixo, OUTPUT);
  pinMode(medio, OUTPUT);
  pinMode(alto, OUTPUT);
  pinMode(alerta, OUTPUT);
}

void loop() {
  int valor = analogRead(sensor);
  unsigned long agora = millis();

  bool critico = (valor < 200 || valor > 950);

  // =========================
  // ALERTA CRÍTICO (PISCANTE)
  // =========================
  if (critico) {
    digitalWrite(baixo, LOW);
    digitalWrite(medio, LOW);
    digitalWrite(alto, LOW);

    if (agora - tempoAnterior >= intervalo) {
      tempoAnterior = agora;
      estadoAlerta = !estadoAlerta;
      digitalWrite(alerta, estadoAlerta);
    }
    return;
  }

  digitalWrite(alerta, LOW);

  // =========================
  // FAIXAS NORMAIS
  // =========================
  if (valor <= 300) {
    digitalWrite(baixo, HIGH);
    digitalWrite(medio, LOW);
    digitalWrite(alto, LOW);
  }
  else if (valor <= 700) {
    digitalWrite(baixo, LOW);
    digitalWrite(medio, HIGH);
    digitalWrite(alto, LOW);
  }
  else {
    digitalWrite(baixo, LOW);
    digitalWrite(medio, LOW);
    digitalWrite(alto, HIGH);
  }
}