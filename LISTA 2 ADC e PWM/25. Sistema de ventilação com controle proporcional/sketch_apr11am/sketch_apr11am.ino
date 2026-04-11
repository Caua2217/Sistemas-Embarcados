********************************************************

13. Sistema de ventilação com controle proporcional
Descrição: Desenvolva um sistema de ventilação industrial onde a velocidade do ventilador
é controlada conforme a temperatura do ambiente.
O sensor NTC fornece a entrada analógica e o atuador (LED PWM) deve variar sua
intensidade proporcionalmente à temperatura medida. O sistema deve operar de forma
contínua e estável.

********************************************************

const int ntc = A0;
const int ventilador = 9;

void setup() {
  pinMode(ventilador, OUTPUT);
}

void loop() {
  int leitura = analogRead(ntc);

  // zona útil (ajuste fino)
  int pwm = map(leitura, 200, 800, 0, 255);

  // limita valores
  if (pwm < 0) pwm = 0;
  if (pwm > 255) pwm = 255;

  analogWrite(ventilador, pwm);
}