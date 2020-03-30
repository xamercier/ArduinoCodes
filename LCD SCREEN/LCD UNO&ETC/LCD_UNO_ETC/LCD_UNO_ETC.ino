//LCD UNO&ETC

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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
