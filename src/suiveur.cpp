#include <Arduino.h>
#include <libRobus.h>
#include "suiveur.h"

void suiveurInit()
{
    pinMode(53,INPUT);
    pinMode(44,INPUT);
    pinMode(40,INPUT);
    pinMode(45,INPUT);
    pinMode(49,INPUT);
    pinMode(48,INPUT);
    pinMode(47,INPUT);
    pinMode(46,INPUT);
}

bool extreme_gauche=digitalRead(53);
bool gauche=digitalRead(44);
bool moyen_gauche=digitalRead(40);  
bool centre_gauche=digitalRead(45);
bool centre_droite=digitalRead(49);
bool moyen_droite=digitalRead(48);
bool droite=digitalRead(47);
bool extreme_droite=digitalRead(46);

void suiveur_ligne(float vitesse){

    extreme_gauche=digitalRead(53);
    gauche=digitalRead(44);
    moyen_gauche=digitalRead(40);
    centre_gauche=digitalRead(45);
    centre_droite=digitalRead(49);
    moyen_droite=digitalRead(48);
    droite=digitalRead(47);
    extreme_droite=digitalRead(46);
    if(extreme_droite==0 && droite!=0){
        while(extreme_droite==0 && droite!=0){
             extreme_gauche=digitalRead(53);
            gauche=digitalRead(44);
            moyen_gauche=digitalRead(40);
            centre_gauche=digitalRead(45);
            centre_droite=digitalRead(49);
            moyen_droite=digitalRead(48);
            droite=digitalRead(47);
            MOTOR_SetSpeed(RIGHT,-vitesse/2);
            MOTOR_SetSpeed(LEFT,vitesse/2);
            //Serial.println("rotation droite");
        }
       
    }
    else if(extreme_gauche==0 && gauche!=0){
        while(extreme_gauche==0 && gauche!=0){
            extreme_gauche=digitalRead(53);
            gauche=digitalRead(44);
            moyen_gauche=digitalRead(40);
            centre_gauche=digitalRead(45);
            centre_droite=digitalRead(49);
            moyen_droite=digitalRead(48);
            droite=digitalRead(47);
            MOTOR_SetSpeed(RIGHT,vitesse/2);
            MOTOR_SetSpeed(LEFT,-vitesse/2);
            //Serial.println("rotation gauche");
        }
        
    }
    else if(centre_droite==0||centre_gauche==0){
        while(centre_droite==0||centre_gauche==0){
            extreme_gauche=digitalRead(53);
            gauche=digitalRead(44);
            moyen_gauche=digitalRead(40);
            centre_gauche=digitalRead(45);
            centre_droite=digitalRead(49);
            moyen_droite=digitalRead(48);
            droite=digitalRead(47);
            MOTOR_SetSpeed(RIGHT,vitesse);
            MOTOR_SetSpeed(LEFT,vitesse);
             //Serial.println("tout droit");
         }
        
     }
    else if(moyen_droite==0||droite==0){
         while(moyen_droite==0||droite==0){
            extreme_gauche=digitalRead(53);
            gauche=digitalRead(44);
            moyen_gauche=digitalRead(40);
            centre_gauche=digitalRead(45);
            centre_droite=digitalRead(49);
            moyen_droite=digitalRead(48);
            droite=digitalRead(47);
            MOTOR_SetSpeed(RIGHT,0);
            MOTOR_SetSpeed(LEFT,vitesse);
            //Serial.println("tourne gauche");
         }
       
    }
     else if((moyen_gauche==0||gauche==0) && centre_gauche!=0 && extreme_gauche!=0){
          while((moyen_gauche==0||gauche==0) && centre_gauche!=0 && extreme_gauche!=0){
                extreme_gauche=digitalRead(53);
                gauche=digitalRead(44);
                moyen_gauche=digitalRead(40);
                centre_gauche=digitalRead(45);
                centre_droite=digitalRead(49);
                moyen_droite=digitalRead(48);
                droite=digitalRead(47);
                MOTOR_SetSpeed(RIGHT,vitesse);
                MOTOR_SetSpeed(LEFT,0);
                //Serial.println("tourne droite");
          }
      
     }
    
    
}