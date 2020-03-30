//LCD MEGA

#include <LiquidCrystal.h>
LiquidCrystal lcd(47, 45, 31, 43, 30, 37);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello World");
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello World");
}
