#include <Arduino.h>
#include <libRobus.h>
#include "algorithme.h"

float vitesse;
int mode;
int niveau;
int i;
float currentMillis;
long startTime;
long duration = 1000;
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
    switch (niveau){
        case 1:
            break;
        


        case 2:
            break;



        case 3:
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