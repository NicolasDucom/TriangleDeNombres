#include <stdio.h>
#include "Fichier.h"
#include "Arbre.h"

int main(int argc, const char * argv[])
{
    Noeud *arbre = construireArbre("/Users/valentin/Developer/C/TriangleDeNombres/TriangleDeNombres/Nombres.txt");
    trouverPlusGrandChemin(arbre);
    
    return 0;
}

