#include <Arduino.h>
#include <libRobus.h>
#include "algorithme.h"
#include "RFID.h"
#include "detecteur_mur.h"


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


void algoInit()
{
    pinMode(38,INPUT);
    pinMode(39,INPUT);
    pinMode(42,INPUT);
    pinMode(28,INPUT);
    pinMode(26,INPUT);
    pinMode(27,INPUT);
    pinMode(NEXT_PIN,OUTPUT);
    long startTime = millis();
}

bool enJeu()
{
    switch (niveau){
            case 1:
                Serial.println("niveau 1");
                    suiveur_ligne(VITESSE_LENTE);
                    if (detection_distance_droite()<15.0)
                    {
                        return 1;
                    }
                else return 0;                
                break;



            case 2:
                Serial.println("niveau 2");
                suiveur_ligne(VITESSE);
                if (detection_distance_droite()<15.0){
                        return 1;
                }
                else return 0;
                break;

            case 3:
                Serial.println("niveau 39");
                    suiveur_ligne(vitesse_random(VITESSEMIN,VITESSEMAX));
                    if (detection_distance_droite()<15.0){
                        return 1;
                    }
                else return 0;
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

bool retour()
{
    stop();
    return 0;
}

void next()
{
    stop();
    digitalWrite(NEXT_PIN, HIGH);
    delay(200);
    digitalWrite(NEXT_PIN, LOW);
}

void algo(){
    //condition pour savoir le case
    
    switch(etat){
        case SYNCHRONISATION:
        stop();
            if (jeux()) 
            {
                next();
                etat = EN_JEU;
            }
        break;
            
        case EN_JEU:
            if (enJeu())
            {
                if (mode = SEUL) 
                {
                    etat = FIN_DE_JEU;
                    next();
                }
                else
                {
                     etat = SYNCHRONISATION_2;
                     next();
                }
        break;
        
        case SYNCHRONISATION_2:
                next();
                etat = EN_JEU_2;
        break;
            
        case EN_JEU_2:
            if (enJeu())  
            {
                next();
                etat = FIN_DE_JEU;
            }
        break;

        case FIN_DE_JEU:
            if (finDeJeu())  
            {
                next();
                etat = RFID;
            }
        break;

        case RFID:
        stop();
            if (RFIDloop())
            {
                next();
                etat = RETOUR;
            }
        break;

        case RETOUR:
            if (retour())
            {
                next();
                etat = SYNCHRONISATION;
            }
        break;

    }
  }
}



float vitesse_random(int vitesse_min = VITESSEMIN, int vitesse_max = VITESSEMAX){
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

bool jeux(){
    if(digitalRead(38)==HIGH){//facile 1 joueur
        mode=SEUL;
        niveau=1;
        Serial.println("seul 1");
        return 1;
    }
    if(digitalRead(39)==HIGH){
        mode=SEUL;
        niveau=2;
        Serial.println("seul 2");
        return 1;
    }
      if(digitalRead(42)==HIGH){
         mode=SEUL;
         niveau=3;
         Serial.println("seul 3");
         return 1;
     }
     if(digitalRead(28)==HIGH){
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
        Serial.println("rien");
        return 0;
    }
}