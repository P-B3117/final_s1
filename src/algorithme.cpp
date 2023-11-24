#include <Arduino.h>
#include <libRobus.h>
#include "algorithme.h"


int joueur1;//niveau premier joueur
int joueur2;//niveau deuxieme joueur
int mode = 0;//un ou deux joueur
int etat = 0;
int niveau=0;
int i;
float currentMillis;
long startTime;
long duration = 1000;
int tour_joueur = 1;

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
     pinMode(22,INPUT);
    pinMode(23,INPUT);
    pinMode(24,INPUT);
    pinMode(25,INPUT);
    pinMode(26,INPUT);
    pinMode(27,INPUT);
    long startTime = millis();
}

bool enJeu()
{
    switch (niveau){
            case 1:
                Serial.println("niveau 1");
                if(i<5){
                    suiveur_ligne(VITESSE_LENTE);

                    if (1)
                    {//detectection incémentation
                        i++;
                    }
            }
                else return 1;                
                break;



            case 2:
                Serial.println("niveau 2");
                if(i<5){
                    suiveur_ligne(VITESSE);

                    if (1){//detectection incémentation
                        i++;
                    }
            }
                else return 1;
                break;

            case 3:
                Serial.println("niveau 23");
                if(i<5){
                    suiveur_ligne(VITESSE);

                    if (1){//detectection incémentation
                        i++;
                    }
                }
                else return 1;
                break;
            }

    return 0;
}

void stop()
{
    MOTOR_SetSpeed( 0, 0 );
    MOTOR_SetSpeed( 1, 0 );
}

bool finDeJeu() 
{
    stop();
    return 0;
}

void algo(){
    //condition pour savoir le case
    
    switch(etat){
        case SYNCHRONISATION:
        stop();
            if (jeux() == true) 
            {
                digitalWrite(NEXT_PIN, HIGH);
                delay(200);
                digitalWrite(NEXT_PIN, LOW);
                etat = EN_JEU;
            }
        break;
            
        case EN_JEU:
            if (enJeu() == true)
            {
                if (mode = SEUL) etat = FIN_DE_JEU;
                else etat = SYNCHRONISATION_2;
            }
        break;
        
        case SYNCHRONISATION_2:
        stop();
            if (jeux() == true) 
            {
                digitalWrite(NEXT_PIN, HIGH);
                delay(200);
                digitalWrite(NEXT_PIN, LOW);
                etat = EN_JEU;
            }
        break;
            
        case EN_JEU_2:
            if (enJeu() == true)
            {
                if (mode = SEUL) etat = FIN_DE_JEU;
                else etat = SYNCHRONISATION_2;
            }
        break;

        case FIN_DE_JEU:
            if (finDeJeu() == true) 
        break;

    }
}



float vitesse_random(int vitesse_min,int vitesse_max){
    long currentTime = millis();
    float vitesse;
  // Calculate the elapsed time since the timer started
  long elapsedTime = currentTime - startTime;

  // Check if the timer has reached its duration
  if (elapsedTime >= duration) {
    vitesse=random(vitesse_min,vitesse_max)/10.0;
    //Serial.println(vitesse);
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
            //Serial.println("rotation droite");
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
            //Serial.println("rotation gauche");
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
             //Serial.println("tout droit");
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
            //Serial.println("tourne gauche");
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
                //Serial.println("tourne droite");
          }
      
     }
    
    
}





bool jeux(){
    if(digitalRead(22)==HIGH){//facile 1 joueur
        mode=SEUL;
        niveau=1;
        Serial.println("seul 1");
        return 1;
    }
    if(digitalRead(23)==HIGH){
        mode=SEUL;
        niveau=2;
        Serial.println("seul 2");
        return 1;
    }
      if(digitalRead(24)==HIGH){
         mode=SEUL;
         niveau=3;
         Serial.println("seul 3");
         return 1;
     }
     if(digitalRead(25)==HIGH){
        mode=MULTIJOUEUR;
        niveau=1;
        Serial.println("multi 1");
        return 1;

    }

     if(digitalRead(26)==HIGH){
        mode=MULTIJOUEUR;
        niveau=2;
        Serial.println("multi 2");
        return 1;

    }
     if(digitalRead(27)==HIGH){
        mode=MULTIJOUEUR;
        niveau=3;
        Serial.println("multi 3");
        return 1;
    }
    else{
        Serial.println("yah");
        return 0;
    }
}