#ifndef TriangleDeNombres_Arbre_h
#define TriangleDeNombres_Arbre_h

typedef struct Noeud {
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droit;
} Noeud;

Noeud* construireArbre(char* fichier);

void placerAlaRacine(Noeud *arbre, int valeur);
void placerDansFilsGauche(Noeud *arbre, int valeur);
void placerDansFilsDroit(Noeud *arbre, int valeur);
void placerDansFilsGaucheEtDroit(Noeud *arbre, int valeur);

void trouverPlusGrandChemin(Noeud *arbre);

#endif
