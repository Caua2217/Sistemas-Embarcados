********************************************************

24. Controle térmico com histerese
Descrição: Projete um sistema de controle de temperatura utilizando um sensor NTC. O
sistema deve acionar um elemento de aquecimento (LED) quando a temperatura estiver
abaixo de um limite inferior e desligá-lo quando ultrapassar um limite superior.
Deve-se implementar histerese para evitar chaveamentos frequentes. Os limites devem ser
definidos via software.

********************************************************

const int ntc = A0;
const int aquecimento = 9;

// limites ajustáveis
int limiteInferior = 400;
int limiteSuperior = 500;

bool aquecendo = false;

void setup() {
  pinMode(aquecimento, OUTPUT);
}

void loop() {
  int valor = analogRead(ntc);

  // =========================
  // CONTROLE COM HISTERESE
  // =========================

  // liga aquecimento
  if (valor < limiteInferior) {
    aquecendo = true;
  }

  // desliga aquecimento
  if (valor > limiteSuperior) {
    aquecendo = false;
  }

  digitalWrite(aquecimento, aquecendo ? HIGH : LOW);
}