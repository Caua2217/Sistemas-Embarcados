********************************************************

12. Sequenciador de Partida:
Descrição: Ao pressionar o Botão 1, os LEDs devem acender um por um (1, depois 2,
depois 3, depois 4) com intervalo de 1 segundo entre eles, permanecendo todos acesos ao
final. O Botão 2 apaga todos.

********************************************************

const int botao1 = 2;
const int botao2 = 3;

const int leds[] = {8, 9, 10, 11};
const int totalLeds = 4;

int etapa = 0;
bool sequenciaAtiva = false;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 1000;

// controle de botão (anti múltiplo disparo simples)
bool ultimoBotao1 = HIGH;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  for (int i = 0; i < totalLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  bool b1 = digitalRead(botao1);
  bool b2 = digitalRead(botao2);

  // RESET (Botão 2)
  if (b2 == LOW) {
    sequenciaAtiva = false;
    etapa = 0;

    for (int i = 0; i < totalLeds; i++) {
      digitalWrite(leds[i], LOW);
    }
  }

  // detectar clique do botão 1 (borda de descida)
  if (ultimoBotao1 == HIGH && b1 == LOW) {
    sequenciaAtiva = true;
    tempoAnterior = millis();
  }

  ultimoBotao1 = b1;

  // execução da sequência
  if (sequenciaAtiva && etapa < totalLeds) {
    if (millis() - tempoAnterior >= intervalo) {
      tempoAnterior = millis();

      digitalWrite(leds[etapa], HIGH);
      etapa++;

      // terminou sequência
      if (etapa >= totalLeds) {
        sequenciaAtiva = false;
      }
    }
  }
}