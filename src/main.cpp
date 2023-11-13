#include <Arduino.h>
#include <libRobus.h>
#include "bluetooth.h"
#include "suiveur.h"
#include "panier.h"
#include "algorithme.h"


void setup() { //ne pas toucher au setup, ce que vous voulez mettre dans le setup mettez le dans votre fonction init
  BoardInit();
  Serial.begin(9600);
  bluetoothInit();
  suiveurInit();
  panierInit();
  algoInit();
}

void loop() {
//Serial.println(SONAR_GetRange(1)); 
//Serial.println(SONAR_GetRange(0)); 
//delay(100);
bluetoothLoop();

}                         