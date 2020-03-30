#include "MIDIUSB.h"
#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);

void ledOnOrOff(boolean onoff, int led, byte velocity) {
  if(onoff == 1){

                if(velocity == 127) {
                    strip.setPixelColor(led, strip.Color(255,255,255));
                } else {
    
                              int redValue, greenValue, blueValue;
                              int mapRGB1, mapRGB2, constrained1, constrained2;
                              mapRGB1 = map(velocity, 0, 31, 255, 0);
                              constrained1 = constrain(mapRGB1, 0, 255);
                              mapRGB2 = map(velocity, 63, 127, 0, 255);
                              constrained2 = constrain(mapRGB2, 0, 255);
                              redValue = constrained1 + constrained2;
                              greenValue = constrain(map(velocity, 0, 31, 0, 255), 0, 255)
                                         - constrain(map(velocity, 31, 63, 0,255), 0, 255);
                              blueValue = constrain(map(velocity, 31, 63, 0, 255), 0, 255)
                                        - constrain(map(velocity, 63, 127, 0, 255), 0, 255);
                              strip.setPixelColor(led, strip.Color(redValue,greenValue,blueValue));
                              strip.show();
                }
                            
  } else {
    strip.setPixelColor(led, strip.Color(0,0,0));
    strip.show();
  }
}

void noteOn(byte pitch, byte velocity) {
  if(pitch == 127){
      ledOnOrOff(1, 0, velocity);
    } else if(pitch == 126){
        ledOnOrOff(1, 1, velocity);
      } else if(pitch == 125){
          ledOnOrOff(1, 2, velocity);
        } else if(pitch == 124){
            ledOnOrOff(1, 3, velocity);
          } else if(pitch == 123){
              ledOnOrOff(1, 4, velocity);
            } else if(pitch == 122){
                ledOnOrOff(1, 5, velocity);
              } else if(pitch == 121){
                  ledOnOrOff(1, 6, velocity);
                } else if(pitch == 120){
                    ledOnOrOff(1, 7, velocity);
                  } else if(pitch == 119){
                      ledOnOrOff(1, 8, velocity);
                    } else if(pitch == 118){
                        ledOnOrOff(1, 9, velocity);
                      }else if(pitch == 117){
                          ledOnOrOff(1, 10, velocity);
                        } else if(pitch == 116){
                            ledOnOrOff(1, 11, velocity);
                          } else if(pitch == 115){
                              ledOnOrOff(1, 12, velocity);
                            } else if(pitch == 114){
                                ledOnOrOff(1, 13, velocity);
                              } else if(pitch == 113){
                                  ledOnOrOff(1, 14, velocity);
                                } else if(pitch == 112){
                                    ledOnOrOff(1, 15, velocity);
                                  } else if(pitch == 111){
                                      ledOnOrOff(1, 16, velocity);
                                    } else if(pitch == 110){
                                        ledOnOrOff(1, 17, velocity);
                                      } else if(pitch == 109){
                                          ledOnOrOff(1, 18, velocity);
                                        } else if(pitch == 108){
                                            ledOnOrOff(1, 19, velocity);
                                          } else if(pitch == 107){
                                              ledOnOrOff(1, 20, velocity);
                                            } else if(pitch == 106){
                                                ledOnOrOff(1, 21, velocity);
                                              } else if(pitch == 105){
                                                  ledOnOrOff(1, 22, velocity);
                                                } else if(pitch == 104){
                                                    ledOnOrOff(1, 23, velocity);
                                                  }else if(pitch == 103){
                                                      ledOnOrOff(1, 24, velocity);
                                                    } else if(pitch == 102){
                                                        ledOnOrOff(1, 25, velocity);
                                                      } else if(pitch == 101){
                                                          ledOnOrOff(1, 26, velocity);
                                                        } else if(pitch == 100){
                                                            ledOnOrOff(1, 27, velocity);
                                                          } else if(pitch == 99){
                                                              ledOnOrOff(1, 28, velocity);
                                                            } else if(pitch == 98){
                                                                ledOnOrOff(1, 29, velocity);
                                                              }
}

void noteOff(byte pitch, byte velocity) {
  if(pitch == 127){
      ledOnOrOff(0, 0, velocity);
    } else if(pitch == 126){
        ledOnOrOff(0, 1, velocity);
      } else if(pitch == 125){
          ledOnOrOff(0, 2, velocity);
        } else if(pitch == 124){
            ledOnOrOff(0, 3, velocity);
          } else if(pitch == 123){
              ledOnOrOff(0, 4, velocity);
            } else if(pitch == 122){
                ledOnOrOff(0, 5, velocity);
              } else if(pitch == 121){
                  ledOnOrOff(0, 6, velocity);
                } else if(pitch == 120){
                    ledOnOrOff(0, 7, velocity);
                  } else if(pitch == 119){
                      ledOnOrOff(0, 8, velocity);
                    } else if(pitch == 118){
                        ledOnOrOff(0, 9, velocity);
                      }else if(pitch == 117){
                          ledOnOrOff(0, 10, velocity);
                        } else if(pitch == 116){
                            ledOnOrOff(0, 11, velocity);
                          } else if(pitch == 115){
                              ledOnOrOff(0, 12, velocity);
                            } else if(pitch == 114){
                                ledOnOrOff(0, 13, velocity);
                              } else if(pitch == 113){
                                  ledOnOrOff(0, 14, velocity);
                                } else if(pitch == 112){
                                    ledOnOrOff(0, 15, velocity);
                                  } else if(pitch == 111){
                                      ledOnOrOff(0, 16, velocity);
                                    } else if(pitch == 110){
                                        ledOnOrOff(0, 17, velocity);
                                      } else if(pitch == 109){
                                          ledOnOrOff(0, 18, velocity);
                                        } else if(pitch == 108){
                                            ledOnOrOff(0, 19, velocity);
                                          } else if(pitch == 107){
                                              ledOnOrOff(0, 20, velocity);
                                            } else if(pitch == 106){
                                                ledOnOrOff(0, 21, velocity);
                                              } else if(pitch == 105){
                                                  ledOnOrOff(0, 22, velocity);
                                                } else if(pitch == 104){
                                                    ledOnOrOff(0, 23, velocity);
                                                  }else if(pitch == 103){
                                                      ledOnOrOff(0, 24, velocity);
                                                    } else if(pitch == 102){
                                                        ledOnOrOff(0, 25, velocity);
                                                      } else if(pitch == 101){
                                                          ledOnOrOff(0, 26, velocity);
                                                        } else if(pitch == 100){
                                                            ledOnOrOff(0, 27, velocity);
                                                          } else if(pitch == 99){
                                                              ledOnOrOff(0, 28, velocity);
                                                            } else if(pitch == 98){
                                                                ledOnOrOff(0, 29, velocity);
                                                              }
}

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
      if(rx.header == 9) {  //IF NOTE ON
        noteOn(rx.byte2, rx.byte3);
      } else if (rx.header == 8) {  //IF NOTE OFF
        noteOff(rx.byte2, rx.byte3);
      }
    }
  } while (rx.header != 0);
}
