#define BLYNK_TEMPLATE_ID "TMPL3jIJGUQXK"
#define BLYNK_TEMPLATE_NAME "project"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "EmonLib.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// ---------------- CONFIG ----------------
char auth[] = "i7RNX5Dv1-KXHbhplLdEkAYc6JFrQ383";
char ssid[] = "zaheer";
char pass[] = "zaheer786";

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Energy monitor
EnergyMonitor emon;
#define vCalibration 73.8
#define currCalibration 0.50


const int DRIVER_PIN = 13;

// If your relay module is active LOW (most common), set true. If it activates on HIGH, set false.
#define RELAY_ACTIVE_LOW true

// Energy / timing
float kWh = 0.0;
unsigned long lastMillis = 0;
BlynkTimer timer;

// Test pulse (non-blocking)
bool testPulseActive = false;
unsigned long testPulseStart = 0;
unsigned long testPulseDuration = 0; // ms

// Convenience: set the relay (handles active-low)
void setRelayState(bool on) {
  if (RELAY_ACTIVE_LOW) digitalWrite(DRIVER_PIN, on ? LOW : HIGH);
  else digitalWrite(DRIVER_PIN, on ? HIGH : LOW);
}

// Blynk: V4 switch (attach a SWITCH widget to V4, mode=Switch)
BLYNK_WRITE(V4) {
  int value = param.asInt();  // 0 or 1
  bool wantOn = (value != 0);
  setRelayState(wantOn);
  // Sync back to widget (keeps UI consistent)
  Blynk.virtualWrite(V4, wantOn ? 1 : 0);
}

// Blynk: V5 momentary (push) - triggers a non-blocking test pulse of 3 seconds
BLYNK_WRITE(V5) {
  int v = param.asInt();
  if (v == 1) {
    // start test pulse for 3000 ms
    testPulseDuration = 3000;
    testPulseStart = millis();
    testPulseActive = true;
    setRelayState(true);
    // reflect immediate state to V4 (optional)
    Blynk.virtualWrite(V4, 1);
  }
}

// Timer event: measure energy, update LCD and Blynk
void myTimerEvent() {
  // Get stable readings
  emon.calcVI(20, 2000);
  float power = emon.apparentPower; // Watts
  unsigned long now = millis();
  float dtSec = (now - lastMillis) / 1000.0;
  if (dtSec > 0.0) {
    kWh += (power * dtSec) / 3600000.0; // convert W*s to kWh
  }

  // LCD output
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:"); lcd.print(emon.Vrms, 1);
  lcd.print(" I:"); lcd.print(emon.Irms, 2);
  lcd.setCursor(0, 1);
  lcd.print("P:"); lcd.print(power, 1);
  lcd.print(" kWh:"); lcd.print(kWh, 3);

  // Blynk virtual writes
  Blynk.virtualWrite(V0, emon.Vrms);
  Blynk.virtualWrite(V1, emon.Irms);
  Blynk.virtualWrite(V2, power);
  Blynk.virtualWrite(V3, kWh);

  lastMillis = now;
}

void setup() {
  // Serial for debug
  Serial.begin(115200);
  delay(50);

  // Relay driver pin
  pinMode(DRIVER_PIN, OUTPUT);
  // Start with relay OFF for safety
  setRelayState(false);

  // LCD init
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("IoT Energy");
  lcd.setCursor(2, 1);
  lcd.print("IOT Project");
  delay(1500);

  lcd.clear();
  lcd.print("Connecting WiFi...");

  // Connect to Blynk (stable on ESP32)
  Blynk.begin(auth, ssid, pass);

  // Energy monitor setup - ADC1 pins on ESP32
  emon.voltage(35, vCalibration, 1.7); // Voltage sensor to pin 35
  emon.current(34, currCalibration);  // Current sensor to pin 34

  lastMillis = millis();
  timer.setInterval(5000L, myTimerEvent); // every 5 seconds

  lcd.clear();
  lcd.print("Ready - V4 relay");
  lcd.setCursor(0, 1);
  lcd.print("V5=test pulse");
  delay(1000);
  lcd.clear();
}

// Non-blocking update for test pulse and other housekeeping
void handleTestPulse() {
  if (testPulseActive) {
    unsigned long now = millis();
    if (now - testPulseStart >= testPulseDuration) {
      // End the test pulse
      testPulseActive = false;
      setRelayState(false);
      // Sync UI
      Blynk.virtualWrite(V4, 0);
    }
  }
}

void loop() {
  Blynk.run();
  timer.run();

  // Handle non-blocking test pulse
  handleTestPulse();

  // Optional: small CPU relief
  delay(10);
}
