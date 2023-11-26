#include <Arduino.h>
#include <libRobus.h>
#include "bluetooth.h"
#include "suiveur.h"
#include "panier.h"
#include "algorithme.h"
#include "RFID.h"

 char msg[]="hello";

void setup() { //ne pas toucher au setup, ce que vous voulez mettre dans le setup mettez le dans votre fonction init
  Serial.begin(9600);
  while (!Serial)
  {  }
  Serial.println("allo");
  BoardInit();
  Serial.println("allo");
  suiveurInit();
  panierInit();
  RFIDInit();
  delay(3000);
  algoInit();
}
void loop() {
//RFIDloop();
//Serial.println("debut loop");
algo();
//suiveur_ligne(vitesse_random(VITESSEMIN,VITESSEMAX));
}                         