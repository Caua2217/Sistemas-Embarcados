const int pin_botaoA = 2;
const int pin_botaoB = 3;
const int led_vermelho = 5;
const int led_verde = 6;
const int led_amarelo = 7;

bool botaoA = false;
bool botaoB = false;

void setup() {
  pinMode(pin_botaoA, INPUT_PULLUP);
  pinMode(pin_botaoB, INPUT_PULLUP);
  pinMode(led_vermelho, OUTPUT);           // nunca esquecer de definir entradas e saidas
  pinMode(led_verde, OUTPUT);             //definir as variaveis
  pinMode(led_amarelo, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  botaoA = digitalRead(pin_botaoA);
  botaoB = digitalRead(pin_botaoB);
  if (botaoA == 0 && botaoB == 0) {    // Liga A & B
    digitalWrite(led_vermelho, HIGH);
  } else {
    digitalWrite(led_vermelho, LOW);
  }
  if (botaoA == 0 || botaoB == 0) {     //liga A ou B
    digitalWrite(led_verde, HIGH);
  }
  else {
    digitalWrite(led_verde, LOW);
  }
  if(botaoA == 0 ^ botaoB == 0){         //liga A xor B
    digitalWrite(led_amarelo, HIGH);
  }
  else{
    digitalWrite(led_amarelo, LOW);
  }
}
