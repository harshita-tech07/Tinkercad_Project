LiquidCrystal_I2C lcd(0x20,16,2);
// C++ code
//
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello Harshita");
  lcd.setCursor(6,1);
  lcd.print("");
  
}

void loop()
{

}