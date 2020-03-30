int magnetic = 0;
int buzzer = 1;

void setup() {
pinMode(magnetic, INPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {
  int sound;
  sound = digitalRead(magnetic);
  if(sound == HIGH) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
}
