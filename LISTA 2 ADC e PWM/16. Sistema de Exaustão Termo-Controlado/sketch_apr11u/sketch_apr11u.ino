********************************************************

16. Sistema de Exaustão Termo-Controlado
Descrição: Um túnel de pintura precisa de exaustão constante, mas a velocidade dos
ventiladores deve variar conforme a temperatura dos gases.
O NTC monitora a temperatura. Se a temperatura for menor que 30°C, o exaustor (LED 2
em PWM) opera com 20% de potência. Entre 30°C e 60°C, a potência deve subir
proporcionalmente (Linear) entre 20% e 100%. Acima de 60°C, o exaustor opera em 100%
e o LED 1 acende indicando "Capacidade Máxima"

********************************************************

const int sensor = A0;

const int exaustor = 9; // PWM (LED 2)
const int alerta = 8;    // LED 1

// limites aproximados (ajustáveis no Tinkercad)
const int LIMITE_BAIXO = 300; // ~30°C
const int LIMITE_ALTO = 700;   // ~60°C

void setup() {
  pinMode(exaustor, OUTPUT);
  pinMode(alerta, OUTPUT);
}

void loop() {
  int valor = analogRead(sensor);

  int pwm = 0;

  // =========================
  // ZONA FRIA (< 30°C)
  // =========================
  if (valor < LIMITE_BAIXO) {
    pwm = 51; // 20% de 255
    digitalWrite(alerta, LOW);
  }

  // =========================
  // ZONA LINEAR (30°C–60°C)
  // =========================
  else if (valor <= LIMITE_ALTO) {
    pwm = map(valor, LIMITE_BAIXO, LIMITE_ALTO, 51, 255);
    digitalWrite(alerta, LOW);
  }

  // =========================
  // ZONA CRÍTICA (> 60°C)
  // =========================
  else {
    pwm = 255;
    digitalWrite(alerta, HIGH);
  }

  analogWrite(exaustor, pwm);
}
