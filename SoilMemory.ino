// C++ code
//

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = A0;

int moisture;
int previousMoisture = -1;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("SoilMemory");
  delay(1500);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  // Typical analog sensor: lower reading means wetter soil.
  // Adjust the mapping after testing your sensor.
  moisture = map(sensorValue, 1023, 0, 0, 100);
  moisture = constrain(moisture, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisture);
  lcd.print("%   ");

  lcd.setCursor(0, 1);

  if (previousMoisture != -1 &&
      moisture < previousMoisture) {
    lcd.print("Moisture Decreased");
  } else {
    lcd.print("Moisture Present ");
  }

  previousMoisture = moisture;

  delay(1000);
}
