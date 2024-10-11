const int pinLed = 10; // Pin pro LED
const int delkaTecky = 200; // Délka tečky v milisekundách
const int delkaCarky = 600; // Délka čárky v milisekundách
const int delkaMezery = 200; // Délka mezery mezi znaky v milisekundách

void setup() {
  pinMode(pinLed, OUTPUT); // Nastavení pinu LED jako výstup
  Serial.begin(9600); // Inicializace sériové komunikace
  Serial.println("Zadejte morseovku ve formátu ---..-.-.-"); // Nápověda pro uživatele
}

void loop() {
  // Kontrola, zda je k dispozici nějaký vstup ze sériového portu
  if (Serial.available() > 0) {
    String morseovka = Serial.readStringUntil('\n'); // Čtení vstupu až do nového řádku
    morseovka.trim(); // Odstranění bílých znaků na začátku a konci

    // Procházení každého znaku v morseovce
    for (int i = 0; i < morseovka.length(); i++) {
      if (morseovka[i] == '.') {
        blikani(delkaTecky); // Blikání pro tečku
      } else if (morseovka[i] == '-') {
        blikani(delkaCarky); // Blikání pro čárku
      }
      delay(delkaMezery); // Zpoždění mezi znaky
    }
  }
}

void blikani(int delka) {
  digitalWrite(pinLed, HIGH); // Zapnutí LED
  delay(delka); // Počkat po dobu 'delka'
  digitalWrite(pinLed, LOW); // Vypnutí LED
}
