//  https://az835927.vo.msecnd.net/sites/iot/Resources/images/ShiftRegister/ShiftRegisterSampleDrawing_schem_75.png
int datapin = 2; 
int clockpin = 3;
int latchpin = 4;

byte data = 0;

void setup()
{
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
}

void loop()
{
  shiftWrite(0, LOW);
  delay(100);
  shiftWrite(0, HIGH);
  delay(100);
}

void shiftWrite(int desiredPin, boolean desiredState)
{
  bitWrite(data,desiredPin,desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data);
  digitalWrite(latchpin, HIGH); 
  digitalWrite(latchpin, LOW); 
}
