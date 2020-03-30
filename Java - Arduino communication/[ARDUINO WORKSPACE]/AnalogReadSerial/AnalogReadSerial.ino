//TEST PIN
const int sendPin = 52;
//TEST PIN

//JSON LIBRARY
#include <ArduinoJson.h>
//JSON LIBRARY

//  LCD
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//  LCD

//MATRIX 8X8
#include <LedControl.h>
int DIN = 26;
int CS =  25;
int CLK = 24;
LedControl lc=LedControl(DIN,CLK,CS,0);
byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte badsmile[8]= {0x00,0x66,0x66,0x00,0x3C,0x42,0x42,0x00};
byte interogation[8]= {0x00,0x3C,0x66,0x02,0x0E,0x08,0x00,0x08};
byte good[8]= {0x01,0x03,0x06,0x8C,0xD8,0x70,0x20,0x00};
String liveMatrix;
//MATRIX 8X8

  //JSON BUFFER
  DynamicJsonBuffer jsonBuffer;
  //JSON BUFFER

void setup() {
  Serial.begin(9600);

  //TEST PIN
  pinMode(sendPin, INPUT);
  //TEST PIN

//MATRIX 8X8
  lc.shutdown(0,false);
  lc.setIntensity(0,01);
  lc.clearDisplay(0);
  printByte(smile);
//MATRIX 8X8

  //  LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.display();
  lcd.print("System is on");
  //  LCD
  
  delay(1000);
  
  //  LCD
  lcd.clear();
  lcd.print("En attente");
  //  LCD

  //MATRIX 8X8
  lc.shutdown(0,false);
  lc.setIntensity(0,01);
  lc.clearDisplay(0);
  printByte(interogation);
  //MATRIX 8X8
}

void loop() {
  if(digitalRead(sendPin) == HIGH) {
   send("PIN IS HIGH");
  } else {
    send("PIN IS LOW");
  }
  
  String message = Serial.readString();
  read(message);
  delay(500);
}

void read(String message) {
  
  String input = message;
  JsonObject& jsonObject = jsonBuffer.parseObject(input);
  String action = jsonObject["action"];
  String complInfo1 = jsonObject["complInfo1"];
  String complInfo2 = jsonObject["complInfo2"];
  
  if(action.equals("lcdWrite")){
    String line1 = complInfo1;
    String line2 = complInfo2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(line1);
    lcd.setCursor(0,1);
    lcd.print(line2);
  } else if(action.equals("setMatrix")){
    lc.clearDisplay(0);
    if(complInfo1.equals(liveMatrix)){
      return;
    } else {
      liveMatrix = complInfo1;
    }
      if(complInfo1.equals("smile")){
        printByte(smile);
      } else if(complInfo1.equals("badsmile")){
        printByte(badsmile);
      } else if(complInfo1.equals("interogation")){
        printByte(interogation);
      } else if(complInfo1.equals("good")){
        printByte(good);
      } else {
        return;
      }
  } else {
    return;
  }
}

void send(String message) {
  Serial.println(message);
}

void printByte(byte character []){
  lc.clearDisplay(0);
  delay(5);
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

