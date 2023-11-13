#pragma once

//ne pas mettre vos librairies ici mettez les dans le .cpp sinon on vas avoir des conflits de librairies
//variables globale

#define SEUL 1
#define MULTIJOUEUR 2
#define TEMPS 10000
#define STOP 4
#define VITESSEMAX 4
#define VITESSEMIN 1


void vitesse_random(int vitesse_min,int vitesse_max);
void algoInit();