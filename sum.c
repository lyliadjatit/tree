#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 
#include "tree_aux.h" //necessaire pour tree_load_int   


int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];

    // Chargement de l’arbre
    tree* t =tree_load_int(filename);
    if (t == NULL) {
        fprintf(stderr, "Error: cannot load tree from file %s\n", filename);
        return EXIT_FAILURE;
    }

    // Calcul de la somme
    int sum = tree_sum_int(t);

    // Affichage du résultat
    printf("tree sum: %d\n", sum);

    // Libération de la mémoire
    tree_free(t);

    return EXIT_SUCCESS;
}
