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
    float tension_bas=ROBUS_ReadIR(0);
    float inverse_bas=1/tension_bas;
    float distance_bas=inverse_bas*6839.3-6.3;
    return distance_bas;
}