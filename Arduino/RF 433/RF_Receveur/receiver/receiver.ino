#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting setup");
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_rx_start();
    Serial.println("Finishing setup");
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
	  int i;
    digitalWrite(13, true);
	  Serial.print("Got: ");
	  for (i = 0; i < buflen; i++) {
	      Serial.print((char) buf[i]);
	  }

    String message(buf[0]);
    Serial.println(message);
   
	  Serial.println("");
    digitalWrite(13, false);
  }

    
}
