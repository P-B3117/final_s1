/********
Fichier: detecteur_mur.cpp
Auteurs: 
Alexis Lechasseur
Charles Poulin-Bergevin
Raphael Richard
Vincent Taylor
Xavier Robidoux
Anis Bouabid
Jordan Klaus Kodjio Kousso 
Date: 30 Novembre 2023
Description: fonstion pour détecter les mur et leur distances
********/
#include <Arduino.h>
#include <libRobus.h>
#include "detecteur_mur.h"
float detection_distance_droite (void){
    float tension_bas=ROBUS_ReadIR(3);
    float inverse_bas=1/tension_bas;
    float distance_bas=inverse_bas*6839.3-6.3;
    return distance_bas;
}

float detection_distance_gauche (void){
    float tension_bas=ROBUS_ReadIR(1);
    float inverse_bas=1/tension_bas;
    float distance_bas=inverse_bas*6839.3-6.3;
    Serial.println(distance_bas);
    return distance_bas;
}