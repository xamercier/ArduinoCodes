#include <VirtualWire.h>

  int Button1 = 2;
  int Button2 = 3;
  int Button3 = 4;
  int Button4 = 5;

void setup() {  
    Serial.begin(9600);
    Serial.println("Starting setup");
    pinMode(Button1, INPUT);
    pinMode(Button2, INPUT);
    pinMode(Button3, INPUT);
    pinMode(Button4, INPUT);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    Serial.println("Finishing setup ");
}




void loop() {

  if (digitalRead(Button1) == false){
    const char *msg = "1";
    Serial.println("Sending 1");
    digitalWrite(13, true);
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(13, false);
  } else if (digitalRead(Button2) == false) {
    const char *msg = "2";
    Serial.println("Sending 2");
    digitalWrite(13, true);
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(13, false);
  } else if (digitalRead(Button3) == false) {
    const char *msg = "3";
    Serial.println("Sending 3");
    digitalWrite(13, true);
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(13, false);
  } else if (digitalRead(Button4) == false) {
    const char *msg = "4";
    Serial.println("Sending 4");
    digitalWrite(13, true);
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(13, false);
  }
  delay(200);
}
