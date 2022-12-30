//
// Created by officialfirephenomenon on 21/12/22.
//
#include "population.h"

/*
 * Fonction qui vérifie si une POPULATION est vide
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return BOOL - vrai si la POPULATION est vide, faux sinon
 */
BOOL is_empty_pop(POPULATION l) {
    if (l == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * Fonction qui insère un INDIVIDU en tête d'une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @param INDIVIDU e - liste chainée représentant un INDIVIDU
 * @return POPULATION - POPULATION avec l'INDIVIDU inséré en tête
 */
POPULATION insert_head_pop(POPULATION l, INDIVIDU e){
    // Allocation mémoire et initialisation d'un nouvel élément de la POPULATION.
    POPULATION newel_pop;
    newel_pop=(structure_pop *) malloc(sizeof(structure_pop));
    newel_pop->value_i=e;

    // Mise à jour de la tête de la POPULATION en y insérant le nouvel élément.
    newel_pop->next=l;
    return newel_pop;
}

/*
 * Fonction qui insère un INDIVIDU en fin de POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @param INDIVIDU e - liste chainée représentant un INDIVIDU
 * @return POPULATION - POPULATION avec l'INDIVIDU inséré en fin
 */
POPULATION insert_tail_pop(POPULATION l, INDIVIDU e){

    // Création d'un nouvel élément de la POPULATION contenant l'INDIVIDU à insérer.
    POPULATION newel = Creation_pop(e);
    // Initialisation d'un pointeur sur la tête de la POPULATION.
    POPULATION p;

    // Si la POPULATION est vide, le nouvel élément devient la tête de la POPULATION.
    if(l == NULL) {
        l=newel;
    } else { // Sinon, on parcourt la POPULATION jusqu'à trouver l'élément qui sera suivi par le nouvel élément.
        p= l;

        while (p->next->next !=NULL) {
            p=p->next;
        }
        // Insertion du nouvel élément en fin de POPULATION.
        p->next=newel;
    }
    // Renvoi de la POPULATION avec l'INDIVIDU inséré en fin.
    return l;
}

/*
 * Fonction qui retire l'INDIVIDU en tête d'une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return POPULATION - POPULATION avec l'INDIVIDU en tête retiré
 */
POPULATION remove_head_pop(POPULATION l){
    // Initialisation d'un pointeur sur l'INDIVIDU en tête de la POPULATION.
    POPULATION p;
    
    // Si la POPULATION est vide, on renvoie NULL.
    if (l == NULL) {
        p=NULL;
    } 
    // Sinon, on met à jour la tête de la POPULATION en retirant l'INDIVIDU en tête.
    else {
        p=l->next;
        free(l);
    }
    // Renvoi de la POPULATION avec l'INDIVIDU en tête retiré.
    return p;
}

/*
 * Fonction qui retire l'INDIVIDU en fin de POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return POPULATION - POPULATION avec l'INDIVIDU en fin retiré
 */
POPULATION remove_tail_pop(POPULATION l){
    // Si la POPULATION n'est pas vide...
    if (l != NULL) {
        // Si la POPULATION n'a qu'un seul élément, on libère cet élément et on met à jour la tête de la POPULATION (NULL).
        if (l->next == NULL) {
            free(l);
            l=NULL;
        }
        // Sinon, on parcourt la POPULATION jusqu'à trouver l'élément précédant l'INDIVIDU en fin.
        else {
            POPULATION p=l;
            while (p->next->next !=NULL) {
                p=p->next;
            }
            // On libère l'INDIVIDU en fin et on met à jour la fin de la POPULATION (NULL).
            free(p->next);
            p->next=NULL;
        }
    }
    // Renvoi de la POPULATION avec l'INDIVIDU en fin retiré.
    return l;
}

/*
 * Fonction qui affiche une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return
 */
void print_list_pop (POPULATION l){

    // Si la POPULATION est vide, on affiche un message.
    if( is_empty_pop(l) ) {
        printf(" *** EMPTY POPULATION *** \n");
    } 
    // Sinon, on parcourt la POPULATION et on affiche chaque INDIVIDU.
    else {
        POPULATION p = l;

        printf ("{\n" );
        while (p->next != NULL) {
            print_list(p->value_i);
            p=p->next;
        }
        printf ("}\n");
    }
}

/*
 * Fonction qui affiche la qualité de chaque INDIVIDU d'une POPULATION
 * @param POPULATION l - liste chainée représentant une POPULATION
 * @return
 */
void print_qualite_pop (POPULATION l){

    // Si la POPULATION est vide, on affiche un message.
    if( is_empty_pop(l) ) {
        printf(" *** EMPTY POPULATION *** \n");
    } 
    // Sinon, on parcourt la POPULATION et on affiche la qualité de chaque INDIVIDU.
    else {
        POPULATION p = l;

        printf ("{\n" );
        double a;
        while (p->next != NULL) {
            a = Qualite_individu(p->value_i);
            printf("%f \n", a);
            p=p->next;
        }
        printf ("}\n");
    }
}


/*
 * Fonction qui initialise une POPULATION avec des INDIVIDUS aléatoires
 * @return POPULATION - la POPULATION créée
 */
POPULATION Initialisation_pop(){
    // Création d'un pointeur de structure_pop
    POPULATION Population_new;
    // Allocation de mémoire pour la structure_pop
    Population_new = (structure_pop *) malloc(sizeof(structure_pop));
    // Appel de la fonction Random_borne() pour obtenir la taille de la POPULATION
    int TaillePop = Random_borne();
    // Création d'un pointeur d'INDIVIDU
    INDIVIDU Individu_newel;

    // Boucle qui initialise chaque INDIVIDU de la POPULATION
    for (int i = 0; i < TaillePop; i++)
    {
        // Appel de la fonction Initialisation() pour créer un INDIVIDU aléatoire
        Individu_newel = Initialisation();
        // Ajout de l'INDIVIDU créé en tête de la POPULATION
        Population_new = insert_head_pop(Population_new, Individu_newel);
    }

    // Retourne la POPULATION créée
    return Population_new;
    // Libération de la mémoire allouée pour la structure_pop
    free (Population_new);
}


/*
 * Fonction qui génère un nombre dans un intervalle inclus définie par TaillePop_max et TaillePop_min dans population.h
 * Attention : nécesssite la commande srand( time( NULL )) avant son utilisation
 * @return int resultat_random_borne - le nombre aléatoire généré
 */
int Random_borne (){
    int resultat_random_borne = 0;

    resultat_random_borne = rand() %(TaillePop_max - TaillePop_min + 1) + (TaillePop_min);

    return resultat_random_borne;
}

/*
 * Fonction qui crée une POPULATION avec un seul INDIVIDU
 * @param INDIVIDU i - liste chainée représentant un INDIVIDU
 * @return POPULATION - la POPULATION créée
 */
POPULATION Creation_pop (INDIVIDU i) {
    POPULATION Population_new;
    Population_new = (structure_pop *) malloc(sizeof(structure_pop));
    Population_new = insert_head_pop(Population_new, i);
    return Population_new;
    free (Population_new);
}


/*
 * Fonction qui retourne l'élément de fin de liste de la population
 * @param POPULATION cur - la population actuelle
 * @return POPULATION - l'élément de fin de liste de la population
 */
POPULATION getTail(POPULATION cur) {
    POPULATION tmp = cur;
    cur = cur->next;
    do
    {
        cur = cur->next;
        tmp = tmp->next;
    } while (cur != NULL && cur->next != NULL);

    return tmp;
}

/*
 * Fonction de tri pour trier une liste chaînée de type POPULATION
 * @param POPULATION head - la population à trier
 * @return POPULATION head - la POPULATION triée
 */
POPULATION Tri(POPULATION head) {
    // Booléen pour vérifier s'il y a eu un échange de noeuds lors de l'itération en cours
    int swapped = 0;
    // Pointeurs pour parcourir la liste chaînée
    POPULATION ptr1 = head;
    POPULATION lptr = getTail(head)->next;

    // Si la liste est vide, il n'y a rien à trier
    if (head == NULL)
        return head;

    // Parcourir la liste chaînée jusqu'au dernier noeud trié lors de l'itération précédente
    while (ptr1->next != lptr) {
        // Si la qualité de l'individu du noeud courant (pivot) est supérieure à celle de l'individu du noeud suivant, échanger les deux noeuds
        if (Qualite_individu(ptr1->value_i) < Qualite_individu(ptr1->next->value_i)) {
            swap(ptr1, ptr1->next);
            swapped = 1;
        }
        ptr1 = ptr1->next;
    }
    // Mettre à jour le dernier noeud trié pour l'itération suivante
    lptr = ptr1;


    // Répéter le tri de manière réccursive tant qu'il y a eu un échange de noeuds lors de l'itération précédente
    if(swapped == 1) Tri(head);

    return head;
}


/*
 * Fonction pour échanger les données de deux noeuds de la liste chaînée
 * @param POPULATION a - la première population
 * @param POPULATION b - la seconde population
 */
void swap(POPULATION a, POPULATION b) {
    INDIVIDU temp = a->value_i;
    a->value_i = b->value_i;
    b->value_i = temp;
}

/*
 * Fonction qui sélectionne aléatoirement une liste de `tselect` individus dans une population donnée triée
 * @param POPULATION population - population à partir de laquelle la sélection sera effectuée
 * @return POPULATION - liste des individus sélectionnés
 */
POPULATION selectionner(POPULATION population) {
    int marqueur = 1; // Compteur qui indique le numéro de l'individu actuellement sélectionné
    POPULATION pop = population; // Pointeur qui parcoure la population
    POPULATION marqueur_pop = population->next; // Pointeur qui parcoure la population en parallèle de pop et qui sert à détecter la fin de la population
    POPULATION p_select = Creation_pop (pop->value_i); // Population qui stockera les individus sélectionnés
    
    // Détermination du nombre d'individus à sélectionner
    int tselect = rand() %(tSelect_max - tSelect_min + 1) + (tSelect_min); // Génération d'un nombre aléatoire entre tSelect_min et tSelect_max
    
    // Sélection des individus
    do {
        // Si le compteur est inférieur au nombre d'individus à sélectionner, on sélectionne l'individu actuel et on incrémente le compteur
        if (marqueur < tselect){
            pop = pop->next;
            p_select = insert_tail_pop(p_select, pop->value_i);
            marqueur++;
        } else { //Sinon on remet le compteur à 0 et on sélectionne le premier individu
            marqueur = 1;
            pop = population;
            p_select = insert_tail_pop(p_select, pop->value_i);
        }
        marqueur_pop = marqueur_pop->next;
    } while (marqueur_pop->next != NULL);

    return p_select;
}

/*
 * Fonction qui croise deux INDIVIDUS de la POPULATION P1 et crée une nouvelle POPULATION P2 avec ces INDIVIDUS croisés
 * @param POPULATION P1 - liste chainée représentant une POPULATION
 * @return POPULATION - POPULATION P2 avec les INDIVIDUS croisés
 */
POPULATION Croiser_pop (POPULATION P1) {
    // Initialisation de variables pour stocker les INDIVIDUS à croiser et la nouvelle POPULATION.
    INDIVIDU i1;
    INDIVIDU i2;
    POPULATION P2;

    // Initialisation d'un pointeur sur la tête de la POPULATION P1.
    POPULATION pop_marqueur = P1;

    // Si la POPULATION P1 est vide, on renvoie P1 sans effectuer de croisement.
    if(!is_empty_pop(P1) || !is_empty_pop(P1)) return P1;

    // Initialisation de la variable longueur pour stocker la longueur de la POPULATION P1.
    int longueur = 0;

    // Parcours de la POPULATION P1 jusqu'à la fin pour trouver sa longueur.
    while (pop_marqueur->next != NULL){
        longueur++;
        pop_marqueur = pop_marqueur->next;
    }

    // Choix aléatoire de deux INDIVIDUS de la POPULATION P1.
    i1 = Choix_aleatoire_individu(P1,longueur);
    i2 = Choix_aleatoire_individu(P1,longueur);

    // Croisement des INDIVIDUS i1 et i2.
    Intervertir_prob(i1,i2);

    // Création de la nouvelle POPULATION P2 avec les INDIVIDUS croisés i1 et i2.
    P2 = Creation_pop(i1);
    P2 = insert_head_pop(P2, i2);

    // Initialisation d'un nouveau pointeur sur la tête de la POPULATION P1.
    pop_marqueur = P1->next->next;

    // Si la POPULATION P1 comprend au moins deux autres INDIVIDUS, on effectue un croisement sur ces INDIVIDUS et on les ajoute à la POPULATION P2.
    if (!is_empty_pop(pop_marqueur) || !is_empty_pop(pop_marqueur->next)) {
        do {
            // Choix aléatoire de deux INDIVIDUS de la POPULATION P1.
            i1 = Choix_aleatoire_individu(P1, longueur);
            i2 = Choix_aleatoire_individu(P1, longueur);

            // Croisement des INDIVIDUS i1 et i2.
            Intervertir_prob(i1, i2);
            // Ajout des INDIVIDUS croisés i1 et i2 à la tête de la POPULATION P2.
            P2 = insert_head_pop(P2, i1);
            P2 = insert_head_pop(P2, i2);

            // Mise à jour du pointeur sur la POPULATION P1.
            pop_marqueur = pop_marqueur->next->next;
        } while (pop_marqueur->next != NULL);
    }

    // Renvoi de la POPULATION P2 avec les INDIVIDUS croisés.
    return P2;
}


/*
 * Fonction qui choisit un individu de la population de manière aléatoire.
 * @param pop La population d'individus à partir de laquelle on doit choisir un individu.
 * @param longueur La longueur de la population d'individus.
 * @return Un individu choisi de manière aléatoire parmi la population.
*/
INDIVIDU Choix_aleatoire_individu (POPULATION pop, int longueur) {
    // Génère un nombre aléatoire compris entre 1 et la longueur de la population.
    int nb_aleatoire = rand()%longueur+1;
    // Compteur pour parcourir la population jusqu'à trouver l'individu choisi aléatoirement.
    int marqueur = 0;
    while (marqueur < nb_aleatoire){
        pop = pop->next;
        marqueur++;
    }
    return pop->value_i;
}