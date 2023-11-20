#include <Arduino.h>
#include <libRobus.h>
#include "bluetooth.h"
#include "suiveur.h"
#include "panier.h"
#include "algorithme.h"

 char msg[]="hello";

void setup() { //ne pas toucher au setup, ce que vous voulez mettre dans le setup mettez le dans votre fonction init
  BoardInit();
  Serial.begin(9600);
  //bluetoothInit();
  suiveurInit();
  panierInit();
  algoInit();
  BluetoothInit();//librobus
 
}

void loop() {
//BLUETOOTH_readCallback();
//Serial.println(BlUETOOTH_MSG);
//Serial.print("yo");
suiveur_ligne(vitesse_random(VITESSEMIN,VITESSEMAX));
//delay(200);
 //Serial.print(digitalRead(  45));
//  Serial.print(digitalRead(  49));
//  Serial.print(digitalRead(  48));
//  Serial.print(digitalRead(  47));
//  Serial.println(digitalRead(46));
}                         