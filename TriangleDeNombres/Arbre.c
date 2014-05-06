#include <stdio.h>
#include <stdlib.h>
#include "Arbre.h"
#include "Fichier.h"

void placerAlaRacine(Noeud *arbre, int valeur)
{
    arbre->valeur = valeur;
}

void placerDansFilsGauche(Noeud *arbre, int valeur)
{
    Noeud *ptr = arbre;
    Noeud *nvNoeud = malloc(sizeof(Noeud));
    nvNoeud->valeur = valeur;
    
    while (ptr->gauche != NULL)
        ptr = ptr->gauche;
    
    ptr->gauche = nvNoeud;
}

void placerDansFilsDroit(Noeud *arbre, int valeur)
{
    Noeud *ptr = arbre;
    Noeud *nvNoeud = malloc(sizeof(Noeud));
    nvNoeud->valeur = valeur;
    
    while (ptr->droit != NULL)
        ptr = ptr->droit;
    
    ptr->droit = nvNoeud;
}

void placerDansFilsGaucheEtDroit(Noeud *arbre, int valeur)
{
    Noeud *ptr = arbre;
    Noeud *nvNoeud = malloc(sizeof(Noeud));
    nvNoeud->valeur = valeur;
    
    while (ptr->gauche != NULL) {
        if (ptr->droit == NULL) {
            ptr->droit = nvNoeud;
            break;
        }
        ptr = ptr->gauche;
    }
    
    while (ptr->droit != NULL) {
        if (ptr->gauche == NULL) {
            ptr->gauche = nvNoeud;
            break;
        }
        ptr = ptr->droit;
    }
}

void trouverPlusGrandChemin(Noeud *arbre)
{
    int total = arbre->valeur;
    
    printf("Plus long chemin : %d ", arbre->valeur);
    
    Noeud *ptr = arbre;
    while (ptr != NULL) {
        if (ptr->gauche != NULL && ptr->droit != NULL) {
            if (ptr->gauche->valeur > ptr->droit->valeur)
                ptr = ptr->gauche;
            else
                ptr = ptr->droit;
        } else if (ptr->gauche != NULL)
            ptr = ptr->gauche;
        else if (ptr->droit != NULL)
            ptr = ptr->droit;
        else
            break;
        
        total += ptr->valeur;
        printf("%d ", ptr->valeur);
    }
    
    printf("\nTotal : %d\n\n", total);
}

Noeud* construireArbre(char* nomFichier)
{
    Noeud *arbre = malloc(sizeof(Noeud));
    int i = 0, j = 0;
    
    FILE *fichier = lireFichier(nomFichier);
    int **tableauDeNombres = placerNombresDuFichierDansUnTableau(fichier);
    
    while (i < nombreDeLignesDuFichier(fichier)) {
        while (j < i + 1) {
            if (i == 0 && j == 0)
                placerAlaRacine(arbre, tableauDeNombres[i][j]);
            else if (j == 0)
                placerDansFilsGauche(arbre, tableauDeNombres[i][j]);
            else if (j == i)
                placerDansFilsDroit(arbre, tableauDeNombres[i][j]);
            else
                placerDansFilsGaucheEtDroit(arbre, tableauDeNombres[i][j]);
            j++;
        }
        i++;
        j = 0;
    }
    
    return arbre;
}