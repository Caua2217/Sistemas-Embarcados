****************************************************************************************************************

20. Sistema simplificado de controle de tanque
Descrição: Desenvolva um sistema embarcado para simular o controle de um tanque
industrial.
Entradas:
• Potenciômetro → nível do tanque
• NTC → temperatura
• Botão → habilitação do sistema
Saídas:
• LED1 → válvula de entrada
• LED2 (PWM) → aquecedor
• LED3 → alarme
Regras:
• Nível baixo → abrir válvula
• Nível alto → fechar válvula
• Temperatura baixa → ligar aquecedor
• Temperatura alta → desligar aquecedor e ativar alarme
O sistema deve operar continuamente e respeitar todas as condições simultaneamente.

****************************************************************************************************************

const int nivelSensor = A0;
const int tempSensor = A1;
const int botao = 2;

const int valvula = 8;
const int aquecedor = 9;
const int alarme = 10;

// limites nível
const int NIVEL_BAIXO = 300;
const int NIVEL_ALTO  = 700;

// limites temperatura
const int TEMP_BAIXA = 400;
const int TEMP_ALTA  = 750;

void setup() {
  pinMode(botao, INPUT_PULLUP);

  pinMode(valvula, OUTPUT);
  pinMode(aquecedor, OUTPUT);
  pinMode(alarme, OUTPUT);
}

void loop() {
  bool sistema = digitalRead(botao) == LOW;

  int nivel = analogRead(nivelSensor);
  int temp  = analogRead(tempSensor);

  // =========================
  // SISTEMA DESLIGADO
  // =========================
  if (!sistema) {
    digitalWrite(valvula, LOW);
    analogWrite(aquecedor, 0);
    digitalWrite(alarme, LOW);
    return;
  }

  // =========================
  // CONTROLE DE NÍVEL
  // =========================
  if (nivel < NIVEL_BAIXO) {
    digitalWrite(valvula, HIGH);
  }
  else if (nivel > NIVEL_ALTO) {
    digitalWrite(valvula, LOW);
  }

  // =========================
  // CONTROLE DE TEMPERATURA
  // =========================

  // PRIORIDADE: temperatura alta = emergência
  if (temp > TEMP_ALTA) {
    analogWrite(aquecedor, 0);
    digitalWrite(alarme, HIGH);
  }
  else {
    digitalWrite(alarme, LOW);

    if (temp < TEMP_BAIXA) {
      analogWrite(aquecedor, 255);
    } else {
      analogWrite(aquecedor, 120); // manutenção
    }
  }
}