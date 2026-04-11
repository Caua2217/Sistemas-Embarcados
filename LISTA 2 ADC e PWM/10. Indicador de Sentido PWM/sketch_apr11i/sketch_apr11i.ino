********************************************************

10. Indicador de Sentido PWM:
Descrição: Use o Potenciômetro com "zero central". Se estiver abaixo de 512, o LED 1
aumenta o brilho conforme o valor diminui. Se estiver acima de 512, o LED 2 aumenta o
brilho conforme o valor aumenta.

********************************************************

const int pot = A0;
const int led1 = 9;
const int led2 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);

  if (valor < 512) {
    // LED 1 responde (quanto mais perto de 0, mais forte)
    int brilho = map(valor, 511, 0, 0, 255);

    analogWrite(led1, brilho);
    analogWrite(led2, 0);
  } 
  else if (valor > 512) {
    // LED 2 responde (quanto mais perto de 1023, mais forte)
    int brilho = map(valor, 513, 1023, 0, 255);

    analogWrite(led2, brilho);
    analogWrite(led1, 0);
  } 
  else {
    // centro: tudo apagado
    analogWrite(led1, 0);
    analogWrite(led2, 0);
  }
}
