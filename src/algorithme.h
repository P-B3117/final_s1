#pragma once

//ne pas mettre vos librairies ici mettez les dans le .cpp sinon on vas avoir des conflits de librairies
//variables globale

#define SYNCHRONISATION 0 
#define EN_JEU 1
#define SYNCHRONISATION_2 2 
#define EN_JEU_2 3
#define FIN_DE_JEU 4
#define SEUL 1
#define MULTIJOUEUR 2
#define TEMPS 10000
#define VITESSEMAX 4
#define VITESSEMIN 1
#define VITESSE_LENTE 0.2
#define VITESSE 0.3

#define NEXT_PIN 28

//suiveur ligne


float vitesse_random(int vitesse_min,int vitesse_max);
void algoInit();
void suiveur_ligne(float vitesse);
bool jeux();
void algo();