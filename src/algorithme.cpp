#include <Arduino.h>
#include <libRobus.h>
#include "algorithme.h"
int joueur1;//niveau premier joueur
int joueur2;//niveau deuxieme joueur
float vitesse;
int mode;//un ou deux joueur
int niveau;
int i;
float currentMillis;
long startTime;
long duration = 1000;
int tour_joueur=1;
void algoInit()
{
    
    long startTime = millis();
}
void algo(){
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
            delay(TEMPS);
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
}



void vitesse_random(int vitesse_min,int vitesse_max){
    long currentTime = millis();

  // Calculate the elapsed time since the timer started
  long elapsedTime = currentTime - startTime;

  // Check if the timer has reached its duration
  if (elapsedTime >= duration) {
    vitesse=random(vitesse_min,vitesse_max)/10.0;
    Serial.println(vitesse);
    // Reset the timer for the next iteration
    startTime = millis();
  }

}