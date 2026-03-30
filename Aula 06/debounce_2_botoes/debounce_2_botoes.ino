//debounce 2 botões para ligar 1 led
const int pinoBotaoa = 9;
const int pinoBotaob = 10;
const int pinoLED   = 8;

// Variáveis de controle de estado
int estadoLED = LOW;         
int estadoBotaoa;             // Estado estável atual (será HIGH por padrão no Pull-up)
int ultimoEstadobotaoa = HIGH; // No Pull-up, o estado de repouso é HIGH
int estadoBotaob;             
int ultimoEstadobotaob = HIGH;
// Variáveis para o tempo (millis)
unsigned long ultimoTempoDebouncea = 0; 
unsigned long ultimoTempoDebounceb = 0; 
unsigned long tempoDebounce = 50; 

void setup() {
  // Ativa o resistor interno de Pull-up (dispensa resistor externo no botão)
  pinMode(pinoBotaoa, INPUT_PULLUP); 
  pinMode(pinoBotaob, INPUT_PULLUP);

  pinMode(pinoLED, OUTPUT);
  digitalWrite(pinoLED, estadoLED);
  
  // Inicializa o estado estável como HIGH (solto)
  estadoBotaoa = HIGH;
  estadoBotaob = HIGH;
}

void loop() {
  // 1. Lê o estado bruto do botão
  int leituraa = digitalRead(pinoBotaoa);
  int leiturab = digitalRead(pinoBotaob);

  // 2. Verifica se o sinal mudou (ruído ou início de clique)
  if (leituraa != ultimoEstadobotaoa) {
    ultimoTempoDebouncea = millis(); // Reinicia o cronômetro
  }
  if (leiturab != ultimoEstadobotaob) {
    ultimoTempoDebounceb = millis(); // Reinicia o cronômetro
  }

  // 3. Verifica se o sinal permaneceu o mesmo por tempo suficiente
  if ((millis() - ultimoTempoDebouncea) > tempoDebounce) {
    
    // Se o sinal estabilizou em um valor diferente do "estadoBotao" anterior
    if (leituraa != estadoBotaoa) {
      estadoBotaoa = leituraa;

      // 4. LÓGICA INVERTIDA: Se o estado estável agora for LOW, significa PRESSIONADO
      if (estadoBotaoa == LOW) {
        estadoLED = HIGH; // Inverte o LED
      }
    }
  }
  if ((millis() - ultimoTempoDebounceb) > tempoDebounce) {
    
    // Se o sinal estabilizou em um valor diferente do "estadoBotao" anterior
    if (leiturab != estadoBotaob) {
      estadoBotaob = leiturab;

      // 4. LÓGICA INVERTIDA: Se o estado estável agora for LOW, significa PRESSIONADO
      if (estadoBotaob == LOW) {
        estadoLED = LOW; // Inverte o LED
      }
    }
  }

  // Atualiza o hardware e a memória para o próximo loop
  digitalWrite(pinoLED, estadoLED);
  ultimoEstadobotaoa = leituraa;
  ultimoEstadobotaob = leiturab;
}