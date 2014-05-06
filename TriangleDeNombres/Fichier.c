#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "Fichier.h"

FILE *lireFichier(char *nom_fichier)
{
    FILE *fichier; size_t taille; char *ligne;
    
	fichier = fopen(nom_fichier, "r");
	
    if (fichier == NULL)
		err(1, nom_fichier);
    else
        return fichier;
}

int nombreDeLignesDuFichier(FILE *fichier)
{
    int nbLignes = 0;
    char *ligne; size_t taille; char *pch;
    
    rewind(fichier);
    
    while ((ligne = fgetln(fichier, &taille))) {
		pch = strtok(ligne, "\n");
        while (pch != NULL) {
            nbLignes++;
            pch = strtok (NULL, "\n");
        }
	}
    
    return nbLignes-1;
}

int nombreDeNombresDuFichier(FILE *fichier)
{
    int nbNombres = 0;
    char *ligne; size_t taille; char *pch;
    
    rewind(fichier);
    
    while ((ligne = fgetln(fichier, &taille))) {
		pch = strtok(ligne, " ");
        while (pch != NULL) {
            nbNombres++;
            pch = strtok (NULL, " ");
        }
	}
    
    return nbNombres;
}

int** placerNombresDuFichierDansUnTableau(FILE *fichier)
{
    char *ligne; size_t taille; char *pch0; char *pch; int pos = 0; char *garbage = NULL;
    
    int** tableauDeNombres = (int**) malloc(nombreDeLignesDuFichier(fichier) * sizeof(int*));
    for (int z = 0; z < nombreDeLignesDuFichier(fichier); z++) {
        tableauDeNombres[z] = (int*) malloc(z * sizeof(int));
    }
        
    rewind(fichier);
    
    int i = 0, j = 0;
    
    while ((ligne = fgetln(fichier, &taille))) {
        pch0 = strtok(ligne, "\n"); // Décomposition en lignes
        while (pch0 != NULL) {
            pch = strtok(pch0, " "); // Décomposition en espaces
            while (pch != NULL) {
                tableauDeNombres[i][j] = atoi(pch);
                pch = strtok (NULL, " ");
                pos++;
                j++;
            }
            pch0 = strtok (NULL, "\n");
            j++;
        }
        i++;
        j = 0;
	}
    
    return  tableauDeNombres;
}