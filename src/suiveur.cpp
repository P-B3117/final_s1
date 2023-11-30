#include <Arduino.h>
#include <libRobus.h>
#include "suiveur.h"

#define Gauche 0
#define Droite 1
#define DISTANCE_90 1942
#define DISTANCE_180 DISTANCE_90*2

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
        
    
    else if(centre_droite==0||centre_gauche==0){
       
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
        
     
    else if(moyen_droite==0||droite==0){
       
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
       
    
     else if((moyen_gauche==0||gauche==0) && centre_gauche!=0 && extreme_gauche!=0){
         
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

void tourne90( float valeurGauche, float valeurDroite){

    Serial.print(valeurGauche);
    Serial.print("          ");
    Serial.print(ENCODER_Read(Gauche));
    Serial.print("          ");
    Serial.print(valeurDroite);
    Serial.print("          ");
    Serial.print(ENCODER_Read(Droite));
    Serial.println();

    //ENCODER_Reset(0);
    //ENCODER_Reset(1);


    MOTOR_SetSpeed(Gauche,valeurGauche);
    MOTOR_SetSpeed(Droite,valeurDroite);

    delay(350);

    
    MOTOR_SetSpeed(Gauche,0);
    MOTOR_SetSpeed(Droite,0);

/*
 while(1)
 {
  int encodeurGauche = ENCODER_Read(Gauche);
  int encodeurDroite = ENCODER_Read(Droite); 
  
  if (encodeurGauche < -DISTANCE_90 || encodeurDroite > DISTANCE_90 )
  {
    if (encodeurGauche < -DISTANCE_90 ){
        MOTOR_SetSpeed(Gauche, 0);
      if (encodeurDroite>DISTANCE_90){
        MOTOR_SetSpeed(Droite, 0);
        return;
       }     }
    else if (encodeurDroite > DISTANCE_90){
        MOTOR_SetSpeed(Droite, 0);

        if (encodeurGauche <- DISTANCE_90){
        MOTOR_SetSpeed(Gauche, 0);
        return;
       } 
      }
    }

 }
 */
}

void tourne180( float valeurGauche, float valeurDroite){

    ENCODER_Reset(0);
    ENCODER_Reset(1);


    MOTOR_SetSpeed(Gauche,valeurGauche);
    MOTOR_SetSpeed(Droite,valeurDroite);

 while(1)
 {
  int encodeurGauche = ENCODER_Read(Gauche);
  int encodeurDroite = ENCODER_Read(Droite); 
  
  if (encodeurGauche <- DISTANCE_180 || encodeurDroite > DISTANCE_180 )
  {
    if (encodeurGauche<-DISTANCE_180){
        MOTOR_SetSpeed(Gauche,0);
      if (encodeurDroite>DISTANCE_180){
        MOTOR_SetSpeed(Droite,0);
        return;
       }     }
    else if (encodeurDroite>DISTANCE_180){
        MOTOR_SetSpeed(Droite,0);

        if (encodeurGauche<-DISTANCE_180){
        MOTOR_SetSpeed(Gauche,0);
        return;
       } 
      }
    }

 }
}