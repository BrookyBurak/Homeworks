// Pin atamalari.
int ledPinleri[] = {9, 10, 11, 12, 13};
int numLED = sizeof(ledPinleri) / sizeof(ledPinleri[0]);

// Her led icin kaç flick edecegi
int flickSayaci[] = {3, 1, 0, 2, 5};

// Flick gecikmesi ve suresi
int flickGecikme = 1000; // milisaniye
int flickSuresi = 500; // milisaniye

void setup() {
  // Led pinlerinin cikislari
  for (int i = 0; i < numLED; i++) {
    pinMode(ledPinleri[i], OUTPUT);
  }
}

void loop() {
  // LED'leri Flick attırma.
  for (int i = 0; i < numLED; i++) {
    int count = flickSayaci[i];
    for (int j = 0; j < count; j++) {
      digitalWrite(ledPinleri[i], HIGH);
      delay(flickSuresi);
      digitalWrite(ledPinleri[i], LOW);
      delay(flickGecikme);
    }
  }

  //Bir dahaki komutu bekleme
  delay(1000); // milisaniye
}
