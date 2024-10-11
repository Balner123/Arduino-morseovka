const int pinLed = 10;
const int delkaTecky = 200;
const int delkaCarky = 600;
const int delkaMezery = 200;

void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Zadejte morseovku ve formátu ---..-.-.-");
}

void loop() {
  if (Serial.available() > 0) {
    String morseovka = Serial.readStringUntil('\n');
    morseovka.trim();

    for (int i = 0; i < morseovka.length(); i++) {
      if (morseovka[i] == '.') {
        blikani(delkaTecky);
      } else if (morseovka[i] == '-') {
        blikani(delkaCarky);
      }
      delay(delkaMezery);
    }
  }
}

void blikani(int delka) {
  digitalWrite(pinLed, HIGH);
  delay(delka);
  digitalWrite(pinLed, LOW);
}
