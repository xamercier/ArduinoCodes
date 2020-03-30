#include <LiquidCrystal.h>                         //Inclue la librairie necessaire au fonctionnement de l'écran

const int temperaturePin = A0;                     //Définie la variable temperaturePin a A0
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);             //Définie les pins que l'écran va utiliser

void setup() {
  Serial.begin(9600);                              //Démarre la comunication série a 9600 baud
  lcd.begin(16, 2);                                //Définie que l'écran a 16 lignes et 2 colones
  lcd.clear();                                     //Efface tout texte de l'écran
  lcd.setCursor(0,0);                              //Met le curseur de l'écran en haut a gauche
  lcd.print("Temp sensor by");                     //Écrit Temp sensor by sur la ligne en haut de l'écran
  lcd.setCursor(0,1);                              //Met le curseur de l'écran en bas a gauche
  lcd.print("Xavier & Selena");                    //Écrit Xavier & Selena sur la ligne en bas de l'écran
  delay(2000);                                     //Fait le programme attendre 2 secondes
  lcd.clear();                                     //Efface tout texte de l'écran
}


void loop() {
  lcd.clear();
  
  float voltage, degresC, degresF;                 //Crée les variables voltage defreesC defreesF

  voltage = getVoltage(temperaturePin);            //Définie la variable voltage au voltage present dans la pin du capteur de température (En utilisant la fonction getVoltage)
                                   ///////         //La zone en / c'est pas la de base elle a été ajouter pour calibrer le capteur
  degresC = (voltage - 0.5) * 100.0 - 7.09;        //Fait le calcule pour transformer le voltage sur 5 volt en degrés celcius

  degresF = degresC * (9.0 / 5.0) + 32.0;          //Fait le calcule pour transformer les degrées celcius en degrés fahrenheit
  
  lcd.setCursor(0,0);                              //Met le curseur de l'écran en haut a gauche
  lcd.print("DegresC: ");                          //Affiche les degres celcius sur la ligne haute de l'écran
  lcd.print(degresC);
  
  lcd.setCursor(0,1);                              //Met le curseur de l'écran en bas a gauche
  lcd.print("DegresF: ");                          //Affiche les degres fahrenheit sur la ligne basse de l'écran
  lcd.print(degresF);

  delay(1000);                                     //Fait le programme attendre 2 secondes avant de recommencer au début de la loupe
}


float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);          //Nous donne le voltage sur 5 volt
}

