/********
Fichier: main.cpp
Auteurs: 
Alexis Lechasseur
Charles Poulin-Bergevin
Raphael Richard
Vincent Taylor
Xavier Robidoux
Anis Bouabid
Jordan Klaus Kodjio Kousso 
Date: 30 Novembre 2023
Description: Main du arduino
********/
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
  SERVO_Disable(SERVO_1);
  Serial.println("allo");
  suiveurInit();
  panierInit();
  RFIDInit();
  delay(3000);
  algoInit();
  SERVO_Enable(SERVO_1);
  //tourne90();
}
void loop() {
//SERVO_SetAngle(SERVO_1, 0);
//RFIDloop();
//Serial.println("debut loop");
algo();
//suiveur_ligne(vitesse_random(VITESSEMIN,VITESSEMAX));
}                         