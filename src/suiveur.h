/********
Fichier:suiveur.h
Auteurs: 
Alexis Lechasseur
Charles Poulin-Bergevin
Raphael Richard
Vincent Taylor
Xavier Robidoux
Anis Bouabid
Jordan Klaus Kodjio Kousso 
Date: 30 Novembre 2023
Description: déclaration fontion pour le suiveur de ligne
********/
#pragma once
//ne pas mettre vos librairies ici mettez les dans le .cpp sinon on vas avoir des conflits de librairies

void suiveurInit();
void tourne90( float valeurGauche = -0.2, float valeurDroite = 0.2);
void tourne180( float valeurGauche = -0.2, float valeurDroite = 0.2);