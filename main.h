/* pour les bibliothèque, par exemple */

#ifndef MAIN_H_
#define MAIN_H_

#include "fonction.h"
#include <stdio.h>
#include <time.h>
#include <ctype.h>





void casRempli(matrice *A, matrice *B, matrice *X);
void casUneCase(matrice *A, matrice *B, matrice *X);
void casAutoFill(matrice *A, matrice *B, matrice *X);
matrice *casJacobi(matrice *A, matrice *B, matrice *X);
matrice *casGauss(matrice *A, matrice *B, matrice *X);
void rempliAuto(matrice *A);
void rempliMain(matrice *A);
void rempliUneCase(matrice *A);

#endif
