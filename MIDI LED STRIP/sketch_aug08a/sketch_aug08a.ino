/*
 * -------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <LedControl.h>

constexpr uint8_t RST_PIN = 5;
constexpr uint8_t SS_PIN = 53;
 
MFRC522 rfid(SS_PIN, RST_PIN);

int DIN = 26;
int CS =  25;
int CLK = 24;

LedControl lc=LedControl(DIN,CLK,CS,0);

LiquidCrystal lcd(47, 45, 32, 43, 30, 37);

byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte badsmile[8]= {0x00,0x66,0x66,0x00,0x3C,0x42,0x42,0x00};
byte waitid[8]= {0x00,0x3C,0x66,0x02,0x0E,0x08,0x00,0x08};
byte gotid[8]= {0x01,0x03,0x06,0x8C,0xD8,0x70,0x20,0x00};

byte nuidAUTH[4];
byte nuidPICC[4];

boolean firstRead;

void setup() { 
  Serial.begin(9600);
  
  SPI.begin();
  rfid.PCD_Init();
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SYSTEM DEMARER!");

  lc.shutdown(0,false);
  lc.setIntensity(0,01);
  lc.clearDisplay(0);
  printByte(smile);
  
  firstRead = true;
  
  delay(2000);
}
 
void loop() {

  if (UIDVALID() == true) {
    lc.clearDisplay(0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AUTHORISATION");
    lcd.setCursor(0,1);
    lcd.print("POUR 5 SECONDES!");
    printByte(smile);
    delay(5000);
    lcd.clear();
    lc.clearDisplay(0);
  } else {
    if(firstRead == true) {
      lc.clearDisplay(0);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SYSTEM EN");
      lcd.setCursor(0,1);
      lcd.print("ATTENTE D'ID!");
      printByte(waitid);
      
      Serial.println("Pas de first ID ...");
      
    } else {
      lc.clearDisplay(0);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SYSTEM ARMER!");
      lcd.setCursor(0,1);
      lcd.print("EN ATTENTE!");
      printByte(badsmile);
      delay(1000);
    }
  }
delay(500);
}

boolean UIDVALID() {
  
    if (firstRead == true) {
      
      if ( ! rfid.PICC_IsNewCardPresent()) {
        return false;
      }
      
      if ( ! rfid.PICC_ReadCardSerial()) {
        return false;
      }
      for (byte i = 0; i < 4; i++) {
        nuidAUTH[i] = rfid.uid.uidByte[i];
      }
      Serial.print(F("HEX: "));
      Serial.println();
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
      firstRead = false;
      Serial.println("" + firstRead);
      lc.clearDisplay(0);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ID ENTREE DANS");
      lcd.setCursor(0,1);
      lcd.print("LE SYSTEM!");
      printByte(gotid);
      delay(2000);
      return true;
      
    } else {

      if ( ! rfid.PICC_IsNewCardPresent())
      {
        return false;
      }
      if ( ! rfid.PICC_ReadCardSerial())
      {
        return false;
      }
      for (byte i = 0; i < 4; i++) {
        nuidPICC[i] = rfid.uid.uidByte[i];
      }
      Serial.print(F("HEX: "));
      Serial.println();
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
      if (memcmp(nuidAUTH, nuidPICC, 4) == 0) {
        return true;
      } else {
        return false;
      }
      
    }
}

void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
