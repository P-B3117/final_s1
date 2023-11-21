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

//suiveur_ligne(vitesse_random(VITESSEMIN,VITESSEMAX));

}                         