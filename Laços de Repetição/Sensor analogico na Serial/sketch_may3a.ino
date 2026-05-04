//4. Ler quatro sensores analógicos e exibir valores no Serial Monitor.

int sensores[] = {A0, A1, A2, A3};

unsigned long previousMillis = 0;
const long interval = 500;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    for (int i = 0; i < 4; i++) {
      int valor = analogRead(sensores[i]);
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(valor);
    }
    Serial.println("------");
  }
}
