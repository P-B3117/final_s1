#include <Arduino.h>
#include <libRobus.h>
#include "bluetooth.h"
#include "suiveur.h"
#include "panier.h"
#include "algorithme.h"
#include "RFID.h"

 char msg[]="hello";

void setup() { //ne pas toucher au setup, ce que vous voulez mettre dans le setup mettez le dans votre fonction init
  BoardInit();
  Serial.begin(9600);
  suiveurInit();
  panierInit();
  algoInit();
  BluetoothInit();//librobus
  RFIDInit();
  pinMode(37,OUTPUT);
  digitalWrite(37,HIGH);
}
void loop() {
RFIDloop();
//algo();
//suiveur_ligne(vitesse_random(VITESSEMIN,VITESSEMAX));
}                         