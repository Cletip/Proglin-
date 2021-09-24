/* pour stocker les fcts et les déclarations de structre */

#ifndef FONCTION_H_
#define FONCTION_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct matrice
{
  int longueur;
  int largeur;
  long double **Mat;
}matrice;

matrice *creerMatrice(int largeur, int longueur);
void destroyMatrice(matrice *mat);
void afficheMatrice(matrice mat);
void remplisAleaBcpZero(matrice *mat);
void remplisAlea(matrice *mat);
void remplisAleaInt(matrice *mat);
matrice *additionMatrice(matrice mat1, matrice mat2);

matrice *Gauss(matrice mat);


#endif
