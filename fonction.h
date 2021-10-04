/* pour stocker les fcts et les déclarations de structre */

#ifndef FONCTION_H_
#define FONCTION_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
  Déclaration de la structure matrice, avec 3 champs: longueur
  largeur pour ne pas à avoir à tout le temps les mettre dans les
  fonctions, et un pointeur de pointeur pour la matrice même (double tableau)
 */
typedef struct matrice
{
  int longueur;
  int largeur;
  long double **Mat;
} matrice;

// Les headers des fonctions
matrice *creerMatrice(int largeur, int longueur);
void destroyMatrice(matrice *mat);
void afficheMatrice(matrice mat);
void remplisAleaBcpZero(matrice *mat);
void remplisAlea(matrice *mat);
void remplisAleaInt(matrice *mat);
void remplisAleaDiagonalDominante(matrice *mat);
matrice *additionMatrice(matrice mat1, matrice mat2);
matrice *soustractino(matrice mat1, matrice mat2);
matrice *multiplicationMatrice(matrice mat1, matrice mat2);

void InversematriceD(int taille, matrice *D);

void rempliBord(matrice *A);
void rempliDingDong(matrice *A);
void rempliFranc(matrice *A);
void rempliHilbertNeg(matrice *A);
void rempliHilbertPos(matrice *A);
void rempliKms(matrice *A);
void rempliLehmer(matrice *A);
void rempliLotkin(matrice *A);
void rempliMoler(matrice *A);

matrice *Jacobi(matrice *A, matrice *B, float Eps, int nombremaxinte, int *compteur);
matrice *Gauss(matrice mat);
matrice *ResolutionParGauss(matrice A, matrice B);
void swapLine(matrice *mat, int a, int b);
float Norme(matrice *colonne);

#endif
