const int trigPin1 = 22;
const int echoPin1 = 23;

const int trigPin2 = 25;
const int echoPin2 = 24;

const int laserReadPin1 = A15;
const int laserReadPin2 = A14;

const int coffreRead = 48;
const int pierreRead = 49;

long duration;
int distance;

void setup() {
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

pinMode (coffreRead, INPUT);

Serial.begin(9600);
}


void loop() {

  if (getDistance(1) == 37 && getDistance(2) == 37 && readLaser(1) > 950 && readLaser(2) < 100 && readCoffre == 0 && readPierre == 0) {
    Serial.println("Tout est clean");
  } 
  
  if (getDistance(1) < 13) {
       Serial.println("Un intru est dans la zone A");
  }
  
  if (getDistance(1) > 12 && getDistance(1) < 25) {
      Serial.println("Un intru est dans la zone D");
  }
  
  if (getDistance(1) > 24 && getDistance(1) < 34) {
    Serial.println("Un intru est dans la zone F");
  }
  
  if (getDistance(2) < 13) {
       Serial.println("Un intru est dans la zone C");
  }
  
  if (getDistance(2) > 12 && getDistance(1) < 25) {
      Serial.println("Un intru est dans la zone E");
  }
  
  if (getDistance(2) > 24 && getDistance(1) < 34) {
    Serial.println("Un intru est dans la zone H");
  }
}

int getDistance(int capteur) {
  if (capteur == 1) {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance= duration*0.0343/2;
  return distance;
  } else if (capteur == 2) {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance= duration*0.0343/2;
  return distance;
  }
}

int readLaser(int capteur) {
  if (capteur == 1) {
  int laser = analogRead(laserReadPin1);
  return laser;
  } else if (capteur == 2) {
  int laser2 = analogRead(laserReadPin2);
  return laser2;
  }
}

int readCoffre() {
  int coffre = digitalRead(coffreRead);
  return coffre;
}

int readPierre() {
  int pierre = digitalRead(pierreRead);
  return pierre;
}
