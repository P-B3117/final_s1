#include <Arduino.h>
#include <libRobus.h>
#include "algorithme.h"


int joueur1;//niveau premier joueur
int joueur2;//niveau deuxieme joueur
int mode;//un ou deux joueur
int niveau;
int i;
float currentMillis;
long startTime;
long duration = 1000;
int tour_joueur=1;
//suiveur ligne
bool extreme_gauche=digitalRead(53);
bool gauche=digitalRead(52);
bool moyen_gauche=digitalRead(51);  
bool centre_gauche=digitalRead(45);
bool centre_droite=digitalRead(49);
bool moyen_droite=digitalRead(48);
bool droite=digitalRead(47);
bool extreme_droite=digitalRead(46);


void algoInit()
{
    pinMode(53,INPUT);
    pinMode(52,INPUT);
    pinMode(51,INPUT);
    pinMode(45,INPUT);
    pinMode(49,INPUT);
    pinMode(48,INPUT);
    pinMode(47,INPUT);
    pinMode(46,INPUT);

    long startTime = millis();
}


/*void algo(){
    //condition pour savoir le case


    switch (mode){
        case SEUL:
        switch (niveau){
        case 1:
        for(i=0; i<5;i++){
            //suiveurligne(vitesse);
            MOTOR_SetSpeed(LEFT,vitesse);
            MOTOR_SetSpeed(RIGHT,vitesse);
            if(1){//detection ligne = 1pour live ou bloc
            //suiveurligne(0);
            MOTOR_SetSpeed(LEFT,0);
            MOTOR_SetSpeed(RIGHT,0);
            delay(TEMPS);//changer millis
            }
        }
            mode=STOP;
            break;
        


        case 2:
        i=0;
        while(i<5){
            //suiveurligne(vitesse);
            MOTOR_SetSpeed(LEFT,vitesse);
            MOTOR_SetSpeed(RIGHT,vitesse);
            if (1){//detectection incémentation
                i++;
            }
        }
        mode=STOP;
            break;



        case 3:
        i=0;
        while(i<5){
            //suiveurligne(vitesse);
            vitesse_random(VITESSEMIN,VITESSEMAX);
            MOTOR_SetSpeed(LEFT,vitesse);
            MOTOR_SetSpeed(RIGHT,vitesse);
            if (1){//detectection incémentation
                i++;
            }
        }
        mode=STOP;

        break;
        
        case STOP:
        MOTOR_SetSpeed(LEFT,0);
        MOTOR_SetSpeed(RIGHT,0);
        break;

    break;
        }


        case MULTIJOUEUR:
        niveau=joueur1;
    switch (niveau){
        case 1:
        for(i=0; i<5;i++){
            //suiveurligne(vitesse);
            MOTOR_SetSpeed(LEFT,vitesse);
            MOTOR_SetSpeed(RIGHT,vitesse);
            if(1){//detection ligne = 1pour live ou bloc
            //suiveurligne(0);
            MOTOR_SetSpeed(LEFT,0);
            MOTOR_SetSpeed(RIGHT,0);
            delay(TEMPS);
            }
        }
        if(tour_joueur==2){
            mode=STOP;
        }
        else{
            tour_joueur++;
            niveau=joueur2;
        }
            break;
        


        case 2: i=0;
        while(i<5){
            //suiveurligne(vitesse);
            MOTOR_SetSpeed(LEFT,vitesse);
            MOTOR_SetSpeed(RIGHT,vitesse);
            if (1){//detectection incémentation
                i++;
            }
        }
       if(tour_joueur==2){
            mode=STOP;
        }
        else{
            tour_joueur++;
            niveau=joueur2;
        }
            break;


            break;



        case 3:
        i=0;
        while(i<5){
            //suiveurligne(vitesse);
            vitesse_random(VITESSEMIN,VITESSEMAX);
            MOTOR_SetSpeed(LEFT,vitesse);
            MOTOR_SetSpeed(RIGHT,vitesse);
            if (1){//detectection incémentation
                i++;
            }
        }
        if(tour_joueur==2){
            mode=STOP;
        }
        else{
            tour_joueur++;
            niveau=joueur2;
        }
        break;
        }
    break;
    }
return;
}*/



float vitesse_random(int vitesse_min,int vitesse_max){
    long currentTime = millis();
    float vitesse;
  // Calculate the elapsed time since the timer started
  long elapsedTime = currentTime - startTime;

  // Check if the timer has reached its duration
  if (elapsedTime >= duration) {
    vitesse=random(vitesse_min,vitesse_max)/10.0;
    Serial.println(vitesse);
    // Reset the timer for the next iteration
    startTime = millis();
  }
    return vitesse;
}


void suiveur_ligne(float vitesse){
    extreme_gauche=digitalRead(53);
    gauche=digitalRead(52);
    moyen_gauche=digitalRead(51);
    centre_gauche=digitalRead(45);
    centre_droite=digitalRead(49);
    moyen_droite=digitalRead(48);
    droite=digitalRead(47);
    extreme_droite=digitalRead(46);
    if(extreme_droite==0 && droite!=0){
        while(extreme_droite==0 && droite!=0){
             extreme_gauche=digitalRead(53);
            gauche=digitalRead(52);
            moyen_gauche=digitalRead(51);
            centre_gauche=digitalRead(45);
            centre_droite=digitalRead(49);
            moyen_droite=digitalRead(48);
            droite=digitalRead(47);
            MOTOR_SetSpeed(RIGHT,-vitesse/2);
            MOTOR_SetSpeed(LEFT,vitesse/2);
            Serial.println("rotation droite");
        }
       
    }
    else if(extreme_gauche==0 && gauche!=0){
        while(extreme_gauche==0 && gauche!=0){
            extreme_gauche=digitalRead(53);
            gauche=digitalRead(52);
            moyen_gauche=digitalRead(51);
            centre_gauche=digitalRead(45);
            centre_droite=digitalRead(49);
            moyen_droite=digitalRead(48);
            droite=digitalRead(47);
            MOTOR_SetSpeed(RIGHT,vitesse/2);
            MOTOR_SetSpeed(LEFT,-vitesse/2);
            Serial.println("rotation gauche");
        }
        
    }
    else if(centre_droite==0||centre_gauche==0){
        while(centre_droite==0||centre_gauche==0){
 extreme_gauche=digitalRead(53);
    gauche=digitalRead(52);
    moyen_gauche=digitalRead(51);
    centre_gauche=digitalRead(45);
    centre_droite=digitalRead(49);
    moyen_droite=digitalRead(48);
    droite=digitalRead(47);
         MOTOR_SetSpeed(RIGHT,vitesse);
         MOTOR_SetSpeed(LEFT,vitesse);
         Serial.println("tout droit");
         }
        
     }
    else if(moyen_droite==0||droite==0){
         while(moyen_droite==0||droite==0){
            extreme_gauche=digitalRead(53);
            gauche=digitalRead(52);
            moyen_gauche=digitalRead(51);
            centre_gauche=digitalRead(45);
            centre_droite=digitalRead(49);
            moyen_droite=digitalRead(48);
            droite=digitalRead(47);
            MOTOR_SetSpeed(RIGHT,0);
            MOTOR_SetSpeed(LEFT,vitesse);
            Serial.println("tourne gauche");
         }
       
    }
     else if((moyen_gauche==0||gauche==0) && centre_gauche!=0 && extreme_gauche!=0){
          while((moyen_gauche==0||gauche==0) && centre_gauche!=0 && extreme_gauche!=0){
              extreme_gauche=digitalRead(53);
             gauche=digitalRead(52);
             moyen_gauche=digitalRead(51);
             centre_gauche=digitalRead(45);
             centre_droite=digitalRead(49);
             moyen_droite=digitalRead(48);
             droite=digitalRead(47);
             MOTOR_SetSpeed(RIGHT,vitesse);
             MOTOR_SetSpeed(LEFT,0);
             Serial.println("tourne droite");
          }
      
     }
    
    
}