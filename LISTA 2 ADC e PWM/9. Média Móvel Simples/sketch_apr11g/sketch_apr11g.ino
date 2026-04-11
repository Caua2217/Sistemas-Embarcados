********************************************************

9. Média Móvel Simples:
Descrição: Leia o Potenciômetro 10 vezes seguidas com um pequeno intervalo e calcule
a média. Exiba o resultado acendendo o LED 3 apenas se a média for superior a 700.

********************************************************
const int pot = A0;
const int led = 10;

const int totalAmostras = 10;
const int intervalo = 10;

int amostras[totalAmostras];
int indice = 0;

unsigned long tempoAnterior = 0;
bool amostrando = true;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long tempoAtual = millis();

  // Coleta amostras sem travar o programa
  if (amostrando && tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    amostras[indice] = analogRead(pot);
    indice++;

    if (indice >= totalAmostras) {
      indice = 0;
      amostrando = false; // terminou coleta
    }
  }

  // Quando tiver 10 amostras, calcula média
  if (!amostrando) {
    long soma = 0;

    for (int i = 0; i < totalAmostras; i++) {
      soma += amostras[i];
    }

    int media = soma / totalAmostras;

    Serial.println(media);

    if (media > 700) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }

    // reinicia nova coleta
    amostrando = true;
    indice = 0;
    tempoAnterior = millis();
  }
}