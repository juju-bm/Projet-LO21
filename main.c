
#include "population.h"

int main(int argc, char const *argv[])
{

    // On commence par initialiser le générateur de nombre pseudo-aléatoires.
    srand( time( NULL ) );

    //Initialisation de la population
    POPULATION Population;
    Population = Initialisation_pop();

    //Initialisation du nombre de génération
    int nGen = rand() %(nGen_max - nGen_min + 1) + (TaillePop_min);

    for (int i = 0; i < nGen; i++){
        
        Population = Tri(Population);
        Population = selectionner(Population);
        Population = Croiser_pop(Population);
    }

    printf("\n Le meilleur individu de la population cree est : \n");
    print_list(Population->value_i);
    

    return 0;
}


