//
// Fichier Header du sous programe individu.c
//

#ifndef LO21_PROJECT_INDIVIDU_H
#define LO21_PROJECT_INDIVIDU_H
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "parametre.h"

#define TRUE 1
#define FALSE 0


// Définition de la structure de données "Individu"
typedef int BOOL;

typedef unsigned char BIT;

typedef struct elem {
    BIT value;
    struct elem *next;
} element;

typedef element * INDIVIDU;




//Fonctions :

/*
 * Fonction qui vérifie si une liste chainée est vide ou non
 * @param INDIVIDU l - liste chainée à vérifier
 * @return BOOL - booléen indiquant si la liste est vide ou non
 */
BOOL is_empty(INDIVIDU l);

/*
 * Fonction qui insère un nouvel élément en tête d'une liste chainée
 * @param INDIVIDU l - liste chainée dans laquelle insérer le nouvel élément
 * @param int e - valeur à affecter au nouvel élément
 * @return INDIVIDU - nouvel INDIVIDU qui pointe vers le début de la liste
 */
INDIVIDU insert_head(INDIVIDU l, int e);

/*
 * Fonction qui insère un nouvel élément en fin de liste chainée
 * @param INDIVIDU l - liste chainée dans laquelle insérer le nouvel élément
 * @param int e - valeur à affecter au nouvel élément
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste
 */
INDIVIDU insert_tail(INDIVIDU l, int e);

/*
 * Fonction qui supprime le premier élément d'une liste chainée
 * @param INDIVIDU l - liste chainée d'où supprimer le premier élément
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste (après suppression du premier élément)
 */
INDIVIDU remove_head(INDIVIDU l);

/*
 * Fonction qui supprime le dernier élément d'une liste chainée
 * @param INDIVIDU l - liste chainée d'où supprimer le dernier élément
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste (après suppression du dernier élément)
 */
INDIVIDU remove_tail(INDIVIDU l);

/*
 * Fonction qui affiche le contenu d'une liste chainée
 * @param INDIVIDU l - liste chainée à afficher
 * @return
 */
void print_list (INDIVIDU l);

/*
 * Fonction qui échange les valeurs de deux variables de type BIT
 * @param BIT *x - pointeur vers une variable de type BIT
 * @param BIT *y - pointeur vers une variable de type BIT
 * @return
 */
void swap_bit();

/*
 * Fonction qui initialise une liste chainée de manière aléatoire
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste initialisée
 */
INDIVIDU Initialisation();

/*
 * Fonction qui calcule la valeur numérique d'une liste chainée de bits
 * @param INDIVIDU Individu - liste chainée de bits à décoder
 * @return int - valeur numérique de la liste chainée de bits
 */
int Decodage_liste_bit();

/*
 * Fonction qui intervertit de manière aléatoire les bits de deux listes chainées
 * @param INDIVIDU* individu1 - pointeur vers le début de la première liste chainée à intervertir
 * @param INDIVIDU* individu2 - pointeur vers le début de la deuxième liste chainée à intervertir
 * @return
 */
void Intervertir_prob();

/*
 * Fonction qui calcule la qualité d'un INDIVIDU
 * @param INDIVIDU Individu - liste chainée représentant un INDIVIDU
 * @return double - qualité de l'INDIVIDU
 */
double Qualite_individu();


#endif //LO21_PROJECT_INDIVIDU_H
