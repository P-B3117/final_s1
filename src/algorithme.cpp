#include <Arduino.h>
#include <libRobus.h>
#include "algorithme.h"
#include "RFID.h"
#include "detecteur_mur.h"
#include "suiveur.h"


int joueur1;//niveau premier joueur
int joueur2;//niveau deuxieme joueur
int mode = 0;//un ou deux joueur
int etat = 0;
int niveau=0;
int i;
float currentMillis;
long startTime = 0;
long duration = 1000;
int tour_joueur = 1;
float vitesse = 0;
int etatFin = 0;

#define OUVERT 180
#define FERME 0
#define TEMPS_DECHARGE 2500
#define DISTANCE_DETECTION 20
#define GAUCHE 0
#define DROITE 1


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


void stop()
{
    MOTOR_SetSpeed( GAUCHE, 0 );
    MOTOR_SetSpeed( DROITE, 0 );
}

bool pasLignes()
{
    if ( digitalRead(53) == LOW && digitalRead(44) == LOW && digitalRead(40) == LOW && digitalRead(45) == LOW && digitalRead(49) == LOW && digitalRead(48) == LOW &&  digitalRead(47) == LOW )

    { return 1; }

    return 0;
}

void tourne()
{
    
        MOTOR_SetSpeed(GAUCHE, -VITESSE_LENTE);
        MOTOR_SetSpeed(DROITE, VITESSE_LENTE);

        delay(350);

        while(digitalRead(45) == HIGH && digitalRead(49) == HIGH) {}

        stop();
        return;
}

bool enJeu()
{
    switch (niveau){
            case 1:
                Serial.println("niveau 1");
                    suiveur_ligne(VITESSE_LENTE);         
                break;

            case 2:
                Serial.println("niveau 2");
                suiveur_ligne(VITESSE);
                break;

            case 3:
                Serial.println("niveau 3");
                    suiveur_ligne(vitesse_random(VITESSEMIN,VITESSEMAX));
                break;
            }

    if (detection_distance_gauche() <= DISTANCE_DETECTION)
    {
        stop();
        return 1;
    }

    return 0;
}

bool finDeJeu() 
{
    switch(etatFin)
    {
        case 0:
        Serial.println("rendu");
        tourne();
        Serial.println("a tourné");
        etatFin++;

        break;

        case 1:
        Serial.println("go");
        MOTOR_SetSpeed(GAUCHE, VITESSE_LENTE);
        MOTOR_SetSpeed(DROITE, VITESSE_LENTE);
        delay(100);
        Serial.println("fin go");
        etatFin++;
        break;

        case 2:
        Serial.println("suis");

                suiveur_ligne(VITESSE);

                if (detection_distance_droite() <= DISTANCE_DETECTION )
                {
                    
                        Serial.println("Fin suis");
                        stop();
                        etatFin = 0;
                        return 1;
                }

        break;
    }
    
        return 0;
}

bool retour()
{
    
    switch (etatFin)
    {

    case 0:

    tourne();
    etatFin++;

        break;

    case 1:
        Serial.println("go");
        MOTOR_SetSpeed(GAUCHE, VITESSE_LENTE);
        MOTOR_SetSpeed(DROITE, VITESSE_LENTE);
        delay(100);
        Serial.println("fin go");
        etatFin++;
    break;
    
    case 2:

    suiveur_ligne(VITESSE);

    if (detection_distance_droite() <= DISTANCE_DETECTION )
    { 

     delay(1000);
     tourne();
     etatFin = 0;
     stop();

     return 1;

    }

    break;
    }

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
        etatFin = 0;
        stop();
        SERVO_SetAngle(SERVO_1, FERME);
            if (jeux()) 
            {
                next();
                SERVO_Disable(SERVO_1);
                etat = EN_JEU;
                MOTOR_SetSpeed(GAUCHE, VITESSE_LENTE);
                MOTOR_SetSpeed(DROITE, VITESSE_LENTE);
                delay(100);
            }
        break;
            
        case EN_JEU:
            if (enJeu())
            {
                if (mode == SEUL) 
                {
                    etat = FIN_DE_JEU;
                    next();
                }
                else
                {
                     etat = SYNCHRONISATION_2;
                     next();
                     Serial.println("go to synchro 2");
                }
        break;
        
        case SYNCHRONISATION_2:
                Serial.println("arrived at 2");
                delay(5000);
                next();
                Serial.println("go to en jeu 2");
                etat = EN_JEU_2;
        break;
            
        case EN_JEU_2:
            Serial.println("arrived at jeu 2");
            if (enJeu())  
            {
                next();
                etat = FIN_DE_JEU;
            }
        break;

        case FIN_DE_JEU:
        Serial.println("fin de jeu");
            if (finDeJeu())
            {
                Serial.println("fin");
                next();
                etat = RFID;
                SERVO_SetAngle(SERVO_1, FERME);
            }
        break;

        case RFID:
        stop();
            if (RFIDloop())
            {
                SERVO_SetAngle(SERVO_1, OUVERT);
                delay(TEMPS_DECHARGE);
                etat = RETOUR;
            }
        break;

        case RETOUR:
            if (retour())
            {
                etat = SYNCHRONISATION;
            }
        break;

    }
  }
}



float vitesse_random(int vitesse_min = VITESSEMIN, int vitesse_max = VITESSEMAX){
    long currentTime = millis();
    Serial.println("rando1");
  // Calculate the elapsed time since the timer started
  long elapsedTime = currentTime - startTime;
    Serial.println("rando2");

  // Check if the timer has reached its duration
  if (elapsedTime >= duration) {
    vitesse= (float)random(vitesse_min,vitesse_max)/10.0;
    
    Serial.println("rando3");
    //Serial.println(vitesse);
    // Reset the timer for the next iteration
    startTime = millis();
    
    Serial.println("rando4");
  }
  
    Serial.println("rando5");
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
        //Serial.println("rien");
        return 0;
    }
}