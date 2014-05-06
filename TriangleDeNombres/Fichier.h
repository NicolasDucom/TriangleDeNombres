#ifndef TriangleDeNombres_Fichier_h
#define TriangleDeNombres_Fichier_h

FILE *lireFichier();
int nombreDeLignesDuFichier(FILE *fichier);
int nombreDeNombresDuFichier(FILE *fichier);
int** placerNombresDuFichierDansUnTableau(FILE *fichier);

#endif
