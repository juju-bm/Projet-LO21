//
// Fichier Header du sous programe population.c
//

#ifndef LO21_PROJECT_POPULATION_H
#define LO21_PROJECT_POPULATION_H
#include "individu.h"

// Définition de la structure de données "Population"
typedef struct pop {
    INDIVIDU value_i;
    struct pop *next;
} structure_pop;

typedef structure_pop * POPULATION;


//Fonctions :

/*
 * Fonction qui vérifie si une POPULATION est vide
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return BOOL - vrai si la POPULATION est vide, faux sinon
 */
BOOL is_empty_pop(POPULATION l);

/*
 * Fonction qui insère un INDIVIDU en tête d'une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @param INDIVIDU e - liste chainée représentant un INDIVIDU
 * @return POPULATION - POPULATION avec l'INDIVIDU inséré en tête
 */
POPULATION insert_head_pop(POPULATION l, INDIVIDU e);

/*
 * Fonction qui insère un INDIVIDU en fin de POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @param INDIVIDU e - liste chainée représentant un INDIVIDU
 * @return POPULATION - POPULATION avec l'INDIVIDU inséré en fin
 */
POPULATION insert_tail_pop(POPULATION l, INDIVIDU e);

/*
 * Fonction qui retire l'INDIVIDU en tête d'une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return POPULATION - POPULATION avec l'INDIVIDU en tête retiré
 */
POPULATION remove_head_pop(POPULATION l);

/*
 * Fonction qui retire l'INDIVIDU en fin de POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return POPULATION - POPULATION avec l'INDIVIDU en fin retiré
 */
POPULATION remove_tail_pop(POPULATION l);

/*
 * Fonction qui affiche une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return
 */
void print_list_pop (POPULATION l);

/*
 * Fonction qui affiche la qualité de chaque INDIVIDU d'une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return
 */
void print_qualite_pop (POPULATION l);

/*
 * Fonction qui initialise une POPULATION avec des INDIVIDUS aléatoires
 * @return POPULATION - la POPULATION créée
 */
POPULATION Initialisation_pop ();

/*
 * Fonction qui génère un nombre dans un intervalle inclus définie par TaillePop_max et TaillePop_min dans population.h
 * Attention : nécesssite la commande srand( time( NULL )) avant son utilisation
 * @return int resultat_random_borne - le nombre aléatoire généré
 */
int Random_borne ();

/*
 * Fonction qui crée une POPULATION avec un seul INDIVIDU
 * @param INDIVIDU i - liste chainée représentant un INDIVIDU
 * @return POPULATION - la POPULATION créée
 */
POPULATION Creation_pop (INDIVIDU i);

/*
 * Fonction qui retourne l'élément de fin de liste chainée
 * @param POPULATION cur - la population actuelle
 * @return POPULATION - l'élément de fin de liste chainée
 */
POPULATION getTail(POPULATION cur);

/*
 * Fonction pour échanger les données de deux noeuds de la liste chaînée
 * @param POPULATION a - la première population
 * @param POPULATION b - la seconde population
 */
void swap(POPULATION a, POPULATION b);

/*
 * Fonction de tri pour trier une liste chaînée de type POPULATION
 * @param POPULATION head - la population à trier
 * @return POPULATION head - la POPULATION triée
 */
POPULATION Tri(POPULATION head);

/*
 * Fonction qui sélectionne aléatoirement une liste de `tselect` individus dans une population donnée triée
 * @param POPULATION population - population à partir de laquelle la sélection sera effectuée
 * @return POPULATION - liste des individus sélectionnés
 */
POPULATION selectionner(POPULATION population);

/*
 * Fonction qui croise deux INDIVIDUS de la POPULATION P1 et crée une nouvelle POPULATION P2 avec ces INDIVIDUS croisés
 * @param POPULATION P1 - liste chainée représentant une POPULATION
 * @return POPULATION - POPULATION P2 avec les INDIVIDUS croisés
 */
POPULATION Croiser_pop (POPULATION P1);

/*
 * Fonction qui choisit un individu de la population de manière aléatoire.
 * @param pop La population d'individus à partir de laquelle on doit choisir un individu.
 * @param longueur La longueur de la population d'individus.
 * @return Un individu choisi de manière aléatoire parmi la population.
*/
INDIVIDU Choix_aleatoire_individu (POPULATION pop, int longueur);

#endif //LO21_PROJECT_POPULATION_H
