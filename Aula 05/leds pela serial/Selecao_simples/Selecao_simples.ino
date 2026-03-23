/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Seleção simples

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

const int led_vermelho = 5;  //
const int led_verde = 6;     //
const int led_amarelo = 7;   //
char led;                    //

void setup() {
  pinMode(led_vermelho, OUTPUT);  //
  pinMode(led_verde, OUTPUT);     //
  pinMode(led_amarelo, OUTPUT);   //
  Serial.begin(115200);           // Definição da velocide de transmissão em 115200 bps
}

void loop() {
  if (Serial.available()) {              //
    led = Serial.read();                 //
    if (led == 'R') {                    // Led vermelho - red
      digitalWrite(led_vermelho, HIGH);  // Acende led
    }
    if (led == 'G') {                 // Led verde - green
      digitalWrite(led_verde, HIGH);  // Acende led
    }
    if (led == 'Y') {                   // Led amarelo - yellow
      digitalWrite(led_amarelo, HIGH);  // Acende led
    }
    if (led == 'r') {      //se digitar r minusculo
      digitalWrite(led_vermelho, LOW);   //led apaga
    }
    if (led == 'g') {     //se digitar g minusculo
      digitalWrite(led_verde, LOW);   //led apaga
    }
    if (led == 'y') {    //se digitar y minusculo
      digitalWrite(led_amarelo, LOW);  //led apaga
    }
    if (led == 'T') {    ////se eu digitar T maiusculo todos os leds acenderam
      digitalWrite(led_vermelho, HIGH);  //todos os leds ligam
      digitalWrite(led_verde, HIGH);     //nao esquecer de colocar o ponto e virgulo no final
      digitalWrite(led_amarelo, HIGH);
    }
    if (led == 't') {   //se eu digitar t minusculo todos os leds apagaram
      digitalWrite(led_vermelho, LOW); //todos os leds apagam
      digitalWrite(led_verde, LOW);    //nao esquecer de colocar o ponto e virgulo no final
      digitalWrite(led_amarelo, LOW);
    }
  }
}
