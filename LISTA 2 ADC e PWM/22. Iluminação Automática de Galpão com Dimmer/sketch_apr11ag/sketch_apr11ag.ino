********************************************************

22. Iluminação Automática de Galpão com Dimmer
Descrição: Para economizar energia, a iluminação de um galpão (LED 1 via PWM) deve
compensar a luz natural (LDR).
Quanto mais luz natural houver, menor deve ser a intensidade do LED 1. O sistema deve
tentar manter a soma da luz natural + luz do LED em um nível constante. Se o galpão estiver
vazio (Botão A não pressionado), a luz deve ficar em apenas 10% de brilho, independente
do potenciômetro.

********************************************************

const int ldr = A0;
const int botao = 2;
const int led = 9;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool ocupado = digitalRead(botao) == LOW;

  int luzAmbiente = analogRead(ldr);

  int pwm = 0;

  // =========================
  // GALPÃO VAZIO
  // =========================
  if (!ocupado) {
    pwm = 26; // ~10% de 255
  }

  // =========================
  // GALPÃO OCUPADO
  // =========================
  else {
    // inverter leitura (quanto mais luz natural, menos LED)
    pwm = map(luzAmbiente, 0, 1023, 255, 0);

    // limita mínimo pra não apagar totalmente
    if (pwm < 10) pwm = 10;
  }

  analogWrite(led, pwm);
}