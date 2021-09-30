/* pour les bibliothèque, par exemple */

#ifndef MAIN_H_
#define MAIN_H_

#include "fonction.h"
#include <stdio.h>
#include <time.h>
#include <ctype.h>



void casMultiplication(matrice *A, matrice *B, matrice *X);
void casResize(matrice *A, matrice *B, matrice *X);
void casRempli(matrice *A, matrice *B, matrice *X);
void casAutoFill(matrice *A, matrice *B, matrice *X);
matrice *casJacobi(matrice *A, matrice *B, matrice *X);
matrice *casGauss(matrice *A, matrice *B, matrice *X);
void rempliAuto(matrice *A);
void rempliMain(matrice *A);

#endif
