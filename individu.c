//
// Executable du sous programe individu
//

#include "individu.h"


/*
 * Fonction qui vérifie si une liste chainée est vide ou non
 * @param INDIVIDU l - liste chainée à vérifier
 * @return BOOL - booléen indiquant si la liste est vide ou non
 */
BOOL is_empty(INDIVIDU l) {

    // Si l est égal à NULL, cela signifie que la liste est vide.
    if (l == NULL) {
        return TRUE;
    } 
    
    // Si l n'est pas égal à NULL, cela signifie que la liste n'est pas vide.
    else {
        return FALSE;
    }
}

/*
 * Fonction qui insère un nouvel élément en tête d'une liste chainée
 * @param INDIVIDU l - liste chainée dans laquelle insérer le nouvel élément
 * @param int e - valeur à affecter au nouvel élément
 * @return INDIVIDU - nouvel INDIVIDU qui pointe vers le début de la liste
 */
INDIVIDU insert_head(INDIVIDU l, int e) {
    
    // Création d'un nouvel élément de la liste.
    INDIVIDU newel;
    
    // Allocation de mémoire pour le nouvel élément.
    newel=(element *) malloc(sizeof(element));
    
    // Affectation de la valeur de l'entier e au nouvel élément.
    newel->value=e;
    
    // Affectation de l (l'INDIVIDU passé en entrée) comme étant l'élément suivant du nouvel élément.
    newel->next=l;
    
    // Renvoi du nouvel INDIVIDU qui pointe vers le début de la liste.
    return newel;
}

/*
 * Fonction qui insère un nouvel élément en fin de liste chainée
 * @param INDIVIDU l - liste chainée dans laquelle insérer le nouvel élément
 * @param int e - valeur à affecter au nouvel élément
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste
 */
INDIVIDU insert_tail(INDIVIDU l, int e) {
    
    // Création d'un nouvel élément de la liste.
    INDIVIDU newel;
    
    // Création d'un INDIVIDU pour parcourir la liste.
    INDIVIDU p;
    
    // Allocation de mémoire pour le nouvel élément.
    newel=(element *) malloc(sizeof(element));
    
    // Affectation de la valeur de l'entier e au nouvel élément.
    newel->value=e;
    
    // Affectation de NULL comme étant l'élément suivant du nouvel élément (car il se trouve en fin de liste).
    newel->next=NULL;
       
    // Si l'INDIVIDU passé en entrée est égal à NULL, cela signifie que la liste est vide.
    // Dans ce cas, le nouvel élément devient le début de la liste.
    if(l == NULL) {
        l=newel;
    }
    // Sinon, si la liste n'est pas vide, nous parcourons la liste à l'aide de l'INDIVIDU p
    // jusqu'à trouver l'élément qui se trouve en fin de liste (dont le champ "next" est égal à NULL).
    // Nous insérons alors le nouvel élément juste après cet élément.
    else {
        p= l;
        while (p->next !=NULL) {
            p=p->next;
        }
        p->next=newel;
    }
    
    // Renvoi de l'INDIVIDU qui pointe vers le début de la liste.
    return l;
}

/*
 * Fonction qui supprime le premier élément d'une liste chainée
 * @param INDIVIDU l - liste chainée d'où supprimer le premier élément
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste (après suppression du premier élément)
 */
INDIVIDU remove_head(INDIVIDU l) {
    
    // Création d'un INDIVIDU pour stocker le nouveau début de la liste (après suppression du premier élément).
    INDIVIDU p;
    
    // Si l'INDIVIDU passé en entrée est égal à NULL, cela signifie que la liste est vide.
    // Dans ce cas, le nouveau début de la liste est égal à NULL.
    if (l == NULL) {
        p=NULL;
    }
    // Sinon, si la liste n'est pas vide, le nouveau début de la liste est l'élément suivant du premier élément.
    // Nous libérons alors la mémoire allouée pour le premier élément de la liste.
    else {
        p=l->next;
        free(l);
    }
    
    // Renvoi de l'INDIVIDU qui pointe vers le début de la liste (après suppression du premier élément).
    return p;
}

/*
 * Fonction qui supprime le dernier élément d'une liste chainée
 * @param INDIVIDU l - liste chainée d'où supprimer le dernier élément
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste (après suppression du dernier élément)
 */
INDIVIDU remove_tail(INDIVIDU l) {
    
    // Si l'INDIVIDU passé en entrée n'est pas égal à NULL, cela signifie que la liste n'est pas vide.
    if (l != NULL) {
        
        // Si l'élément suivant du premier élément de la liste est égal à NULL, cela signifie que la liste ne contient qu'un seul élément.
        // Dans ce cas, nous libérons la mémoire allouée pour ce seul élément et mettons à jour l'INDIVIDU qui pointe vers le début de la liste (qui devient égal à NULL).
        if (l->next == NULL) {
            free(l);
            l=NULL;
        }
        // Sinon, si la liste contient plusieurs éléments, nous parcourons la liste à l'aide de l'INDIVIDU p jusqu'à trouver l'avant-dernier élément de la liste (dont le champ "next" de l'élément suivant est égal à NULL).
        // Nous libérons alors la mémoire allouée pour le dernier élément de la liste et mettons à jour le champ "next" de l'avant-dernier élément (qui devient égal à NULL).
        else {
            INDIVIDU p=l;
            while (p->next->next !=NULL) {
                p=p->next;
            }
            free(p->next);
            p->next=NULL;
        }
    }
    
    // Renvoi de l'INDIVIDU qui pointe vers le début de la liste (après suppression du dernier élément).
    return l;
}

/*
 * Fonction qui affiche le contenu d'une liste chainée
 * @param INDIVIDU l - liste chainée à afficher
 * @return
 */
void print_list(INDIVIDU l) {

    if( is_empty(l) ) {
        printf(" *** EMPTY LIST *** \n");
    } else {
        INDIVIDU p = l;

        printf ("[ " );
        while (p->next !=NULL) {
            printf("%d ", p->value);
            p=p->next;
        }
        printf ("]\n");
    }
}

/*
 * Fonction qui initialise une liste chainée de manière aléatoire
 * @return INDIVIDU - INDIVIDU qui pointe vers le début de la liste initialisée
 */
INDIVIDU Initialisation(){
    
    // Création d'un INDIVIDU qui pointe vers le début de la liste à initialiser.
    INDIVIDU Individu_new;
    
    // Allocation de mémoire pour le premier élément de la liste.
    Individu_new = (element *) malloc(sizeof(element));
    
    // Déclaration d'une variable "value_bit" qui stockera la valeur du bit généré aléatoirement.
    int value_bit;
    
    // Boucle qui génère "longIndiv" bits aléatoirement et les insère en tête de la liste.
    for (int i = 0; i < longIndiv; i++)
    {
        // Génération d'un bit aléatoire (0 ou 1).
        value_bit = rand()%2;
        
        // Insertion du bit en tête de la liste.
        Individu_new = insert_head(Individu_new , value_bit);
    }
    
    // Renvoi de l'INDIVIDU qui pointe vers le début de la liste initialisée.
    return Individu_new;
}

/*
 * Fonction qui calcule la valeur numérique d'une liste chainée de bits
 * @param INDIVIDU Individu - liste chainée de bits à décoder
 * @return int - valeur numérique de la liste chainée de bits
 */
int Decodage_liste_bit(INDIVIDU Individu){
    
    // Si l'INDIVIDU passé en entrée est égal à NULL, cela signifie que la liste est vide. Dans ce cas, la fonction renvoie 0.
    if( is_empty(Individu) ) {
        return 0;
    }
    // Sinon, si la liste n'est pas vide, nous parcourons la liste à l'aide de l'INDIVIDU p et nous calculons la valeur numérique de la liste en additionnant les valeurs de chaque bit de la liste.
    else {
        INDIVIDU p = Individu;
        
        // Déclaration de la variable "valeur" qui stockera la valeur numérique de la liste.
        int valeur = 0;
        
        // Parcours de la liste et calcul de la valeur numérique.
        while (p->next !=NULL) {
            valeur = valeur + p->value;
            p=p->next;
        }
        
        // Renvoi de la valeur numérique de la liste.
        return valeur;
    }
}

/*
 * Fonction qui intervertit de manière aléatoire les bits de deux listes chainées
 * @param INDIVIDU* individu1 - pointeur vers le début de la première liste chainée à intervertir
 * @param INDIVIDU* individu2 - pointeur vers le début de la deuxième liste chainée à intervertir
 * @return
 */
void Intervertir_prob(INDIVIDU* individu1, INDIVIDU* individu2){
    
    // Si l'un des deux INDIVIDUs passés en entrée est égal à NULL, cela signifie que l'une des listes est vide. Dans ce cas, la fonction ne fait rien et s'arrête.
    if( is_empty(*individu1) || is_empty(*individu2) ) {
        return;
    }
    // Sinon, si les deux listes ne sont pas vides, nous parcourons les listes et intervertissons les bits de manière aléatoire.
    else {
        
        // Déclaration de la variable "n" qui stockera un nombre aléatoire généré à l'aide de la fonction "rand()".
        float n = 0;
        
        // Génération d'un nombre aléatoire et comparaison avec "pCroise" pour déterminer si le bit courant de la première liste doit être interverti avec le bit courant de la deuxième liste. Si "n" est supérieur à "pCroise", les bits ne sont pas intervertis. Sinon, ils le sont.
        n = (float)rand()/RAND_MAX;
        if (n > pCroise)
        {
            // Interversion des bits grâce à la fonction "swap_bit()".
            swap_bit(&(*individu1)->value,&(*individu2)->value);
        }

        // Déclaration de deux INDIVIDUs, "p" et "q", qui pointent respectivement vers le début de la première et de la deuxième liste.
        INDIVIDU p = *individu1;
        INDIVIDU q = *individu2;
        
        // Si les deux listes ont au moins un élément (c'est-à-dire si leur tête n'est pas égale à NULL), nous parcourons les listes et intervertissons de manière aléatoire les bits de chaque élément.
        if (p->next !=NULL || q->next !=NULL)
        {
            // Parcours des listes et interversion des bits.
            while (p->next !=NULL || q->next !=NULL) {
                
                // Génération d'un nombre aléatoire et comparaison avec "pCroise" pour déterminer si le bit courant de la première liste doit être interverti avec le bit courant de la deuxième liste. Si "n" est inférieur à "pCroise", les bits sont intervertis. Sinon, ils ne le sont pas.
                n = (float)rand()/RAND_MAX;
                if (n < pCroise)
                {
                    // Interversion des bits grâce à la fonction "swap_bit()".
                    swap_bit(&p->value,&q->value);
                }
                
                // Avancement des pointeurs "p" et "q" vers l'élément suivant de chaque liste.
                p=p->next;
                q=q->next;
            }
            
            // Génération d'un nombre aléatoire et comparaison avec "pCroise" pour déterminer si le bit courant de la première liste doit être interverti avec le bit courant de la deuxième liste. Si "n" est inférieur à "pCroise", les bits sont intervertis. Sinon, ils ne le sont pas.
            n = (float)rand()/RAND_MAX;
            if (n < pCroise)
            {
                // Interversion des bits grâce à la fonction "swap_bit()".
                swap_bit(&p->value,&q->value);
            }
        }
        
        // Mise à jour des valeurs des pointeurs "individu1" et "individu2" avec les valeurs de "p" et "q" pour refléter les modifications apportées aux listes.
        (*individu1) = p;
        (*individu2) = q;
    }
}


/*
 * Fonction qui calcule la qualité d'un INDIVIDU
 * @param INDIVIDU Individu - liste chainée représentant un INDIVIDU
 * @return double - qualité de l'INDIVIDU
 */
double Qualite_individu(INDIVIDU Individu){
    
    // Récupération de la valeur décodée de l'INDIVIDU grâce à la fonction "Decodage_liste_bit()".
    int valeur = Decodage_liste_bit(Individu);
    
    // Initialisation de la variable "qualite" à 0.
    double qualite = 0;
    
    // Calcul de la qualité de l'INDIVIDU à l'aide de la valeur décodée et de la formule indiquée.
    double X = (valeur/(pow(2,longIndiv)))*(B-A)+A ;
    qualite = f(X) ;
    
    // Renvoi de la qualité de l'INDIVIDU.
    return qualite;
}

/*
 * Fonction qui échange les valeurs de deux variables de type BIT
 * @param BIT *x - pointeur vers une variable de type BIT
 * @param BIT *y - pointeur vers une variable de type BIT
 * @return
 */
void swap_bit(BIT *x, BIT *y) {
    
    // Création d'une variable temporaire qui stockera la valeur de x.
    BIT temp = *x;
    
    // Mise à jour de la valeur de x avec la valeur de y.
    *x = *y;
    
    // Mise à jour de la valeur de y avec la valeur de la variable temporaire (ancienne valeur de x).
    *y = temp;
}
