#include <Keypad.h>

// C++ code
//

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int PIR_PIN    = 2;
const int BUZZER_PIN = 8;
const int LED_PIN    = 13; 

LiquidCrystal_I2C lcd(0x27, 16, 2);

//keep alarm activeafter motion stops
const unsigned long HOLD_TIME = 3000;
unsigned long lastMotionTime = 0;
bool alarmActive = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Security System");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);

  showNoMotion();
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    lastMotionTime = millis();
    if (!alarmActive) {
      alarmActive = true;
      showMotionDetected();
    }
  }

  // Once HOLD_TIME has passed with no new motion return to idle
  if (alarmActive && (millis() - lastMotionTime >= HOLD_TIME)) {
    alarmActive = false;showNoMotion();
  }
}

void showMotionDetected() {
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motion Detected");
  lcd.setCursor(0, 1);
  lcd.print("Alert! Deteced.");
}

void showNoMotion() {
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("No Motion");
  lcd.setCursor(0, 1);
  lcd.print("Detected.");
}