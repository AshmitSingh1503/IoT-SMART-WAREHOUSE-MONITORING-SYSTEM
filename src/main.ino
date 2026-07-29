#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPL3ZoVUuA3u"
#define BLYNK_TEMPLATE_NAME "SENTINEL"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

// ---- WiFi credentials ----
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";


// ---- DHT22 ----
#define DHT_PIN 4
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);

// ---- PIR (HW-416) / Active Buzzer / LED ----
#define PIR_PIN 13
#define BUZZER_PIN 12
#define LED_PIN 14
#define TEMP_LIMIT 29.0

// ---- LCD 16x2 I2C ----
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---- RFID RC522 ----
#define RFID_SS_PIN 15
#define RFID_RST_PIN 27
MFRC522 rfid(RFID_SS_PIN, RFID_RST_PIN);

// ---- HC-SR04 ----
#define TRIG_PIN 26
#define ECHO_PIN 25

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  SPI.begin();
  rfid.PCD_Init();

  Serial.println("Warehouse Monitoring System Started...");
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(1500);
}

void loop() {
   Serial.println("Object Detected");  
  // ---- DHT22 ----
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C  Hum: ");
  Serial.print(humidity);
  Serial.println(" %");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(humidity);
  lcd.print("%");

  if (temperature > TEMP_LIMIT) {
    Serial.println("ALERT: Temperature too high!");
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // ---- PIR Motion ----
  int motionDetected = digitalRead(PIR_PIN);
  if (motionDetected == HIGH) {
    Serial.println("ALERT: Motion detected!");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
      delay(200);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // ---- HC-SR04 Distance ----
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distanceCm = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // ---- RFID Scan ----
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uidText = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uidText += String(rfid.uid.uidByte[i], HEX);
      uidText += " ";
    }
    Serial.print("Card UID: ");
    Serial.println(uidText);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Card Scanned:");
    lcd.setCursor(0, 1);
    lcd.print(uidText);
    delay(2000);

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

  delay(2000);
}
