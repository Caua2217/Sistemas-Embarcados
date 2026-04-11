********************************************************

19. Indicador térmico em barra
Descrição: Implemente um sistema de monitoramento térmico onde o valor do sensor NTC
é representado por uma barra de LEDs.
A quantidade de LEDs acesos deve ser proporcional à temperatura medida, permitindo
visualização intuitiva do estado do sistema.

********************************************************

const int sensor = A0;

const int leds[] = {8, 9, 10, 11};
const int totalLeds = 4;

void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int valor = analogRead(sensor);

  int nivel = 0;

  if (valor > 200) nivel = 1;
  if (valor > 450) nivel = 2;
  if (valor > 700) nivel = 3;
  if (valor > 900) nivel = 4;

  for (int i = 0; i < totalLeds; i++) {
    digitalWrite(leds[i], i < nivel ? HIGH : LOW);
  }
}