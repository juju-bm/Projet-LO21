//
// Fichier Header contenant tous les paramètres du projets pouvant être modifiés
//

#ifndef LO21_PROJECT_PARAMETRE_H
#define LO21_PROJECT_PARAMETRE_H

//Paramètres du Type abstrait « Individu » (Partie 1) :
#define longIndiv 16 //Entier : Longeur de l'individu en nombre de bits
#define pCroise 0.5 //Réel ∈ [0,1] : Probabilité indiqué pour croiser une liste de bits
#define A 0.1 //Réel : paramètre A de la fonction qualité
#define B 5 //Réel : paramètre B de la fonction qualité
#define f(x) -ln(x) //fonction : fonction qualité de X   f1(x)= -x*x et f2(x)=-log(x)

//Paramètres du Type abstrait « Population » (Partie 2) :
#define TaillePop_min 20 //Entier : Taille minimum de la population 
#define TaillePop_max 200 //Entier : Taille maximum de la population
//#define tselect 4 //Entier : Taux de selection de la fonction selection

//Paramètres
#define tSelect_min 10 //Entier : Taux minimal de selection de la fonction selection
#define tSelect_max 90 //Entier : Taux maximal de selection de la fonction selection
#define nGen_min 10 //Entier : Nombre de générations minimal
#define nGen_max 90 //Entier : Nombre de générations maximal

#endif //LO21_PROJECT_PARAMETRE_H
