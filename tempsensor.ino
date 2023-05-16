#include <TimeLib.h>      

// Pin atamalari.
int ledPinleri[] = {9, 10, 11};
int numLED = sizeof(ledPinleri) / sizeof(ledPinleri[0]);

// LM35 pin
int tempPin = A0;
int sicaklik;
int tarih, saat;

void setup() {
  // Led pinlerinin cikislari
  for (int i = 0; i < numLED; i++) {
    pinMode(ledPinleri[i], OUTPUT);
  }
  
  // Seri haberlesme frekansi.
  Serial.begin(9600);

  /* Dosyayi hem yazar hem okur modda actik.
  FILE *dosya;
  dosya = fopen("tempdeger.txt", "a+");
  if (dosya == NULL) {
    Serial.println("Dosya açılamadı!");
    return;
  }
*/
  // Tarih ve saat
  tarih = day();
  saat = hour();

  // Isiyi analog degerden okuma
  sicaklik = analogRead(tempPin);
  sicaklik = map(sicaklik, 0, 1023, 0, 50); /* Map fonksiyonu kullanimi ise (deger,altdeger,ustdeger,cevirilecek alt deger, cevirelecek ust deger)
   LM35 0-1023 arasi deger aldigindan bunun alt ve ust degerlerini 0-50 Celsius arasina kisitladik */

  /* Veri logu dosyaya yazdirma.
  fprintf(dosya, "Tarih: %d\tSaat: %d\tSıcaklık: %d\n", tarih, saat, sicaklik);
  fclose(dosya);
  */
}

void loop() {
  // Sicaklik okuma
  sicaklik = analogRead(tempPin);
  sicaklik = map(sicaklik, 0, 1023, 0, 50); // 0-50 Celsius arasina indirgedik

  // LED sicakligina gore yanacak ledler
  if (sicaklik < 20) {    //0-20 C arasi:
    digitalWrite(9, HIGH);  // Mavi LEDi yak
    digitalWrite(10, LOW);  // Sari LEDi kapa
    digitalWrite(11, LOW);  // Kirmizi LEDİ kapa
  } else if (sicaklik > 25) {
    digitalWrite(9, LOW);   // Mavi LEDi kapa
    digitalWrite(10, HIGH); // Sari LEDi yak
    digitalWrite(11, LOW);  // Kirmizi LEDİ kapa
  } else {
    digitalWrite(9, LOW);   // Mavi LEDİ kapa
    digitalWrite(10, LOW);  // Sari LEDİ kapa
    digitalWrite(11, HIGH); // Kirmizi LEDİ yak
  }
  // Verileri seri monitorde görüntüle
  Serial.print("Tarih: ");
  Serial.print(tarih);
  Serial.print("\tSaat: ");
  Serial.print(saat);
  Serial.print("\tSıcaklık: ");
  Serial.println(sicaklik);

  // 1 saniye bekle.
  delay(1000);
}
