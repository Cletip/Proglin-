/* toutes les fct */
#include "fonction.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* création d'une, renvoie un pointeur sur une matrice */
matrice *creerMatrice(int largeur, int longueur)
{
  /* création d'un pointeur sur une structure matrice (avec l'espace
     alloué de la structure matrice)  */
  matrice *fini = (matrice *)malloc(sizeof(matrice));

  /* attribution de la longueur et de la largeur */
  fini->longueur = longueur;
  fini->largeur = largeur;

  /* Création du double tableau, la matrice même (initialisé à 0)  */
  fini->Mat = (long double **)malloc(fini->longueur * sizeof(long double *));
  /* parcourt de la matrice avec la double boucle for */
  for (int i = 0; i < fini->longueur; i++)
  {
    fini->Mat[i] = (long double *)malloc(fini->largeur * sizeof(long double));
    for (int j = 0; j < fini->largeur; j++)
    {
      fini->Mat[i][j] = 0;
    }
  }

  /* renvoie de la fini */
  return fini;
}

/*  supprime une matrice (y compris de la mémoire) */
void destroyMatrice(matrice *mat)
{
  for (int i = 0; i < mat->longueur; i++)
  {
    free(mat->Mat[i]);
  }
  free(mat->Mat);
  mat->longueur = 0;
  mat->largeur = 0;
  free(mat);
}

/* affiche la matrice */
void afficheMatrice(matrice mat)
{
  for (int i = 0; i < mat.longueur; i++)
  {
    for (int j = 0; j < mat.largeur; j++)
    {
      printf("%LF ", mat.Mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* remplie une matrice avec (normalement) 70% de 0 */
void remplisAleaBcpZero(matrice *mat)
{
  for (int i = 0; i < mat->longueur; i++)
  {
    for (int j = 0; j < mat->largeur; j++)
    {
      if (rand() % 100 <= 70) /* calcul du pourcentage de 0 */
      {
        mat->Mat[i][j] = 0;
      }
      else
      {
        /* sinon valeur aléatoire entre -100 et 100 */
        mat->Mat[i][j] = ((long double)rand() / RAND_MAX * 2.0 - 1.0) * 100;
      }
    }
  }
}

void remplisAlea(matrice *mat){
  for(int i = 0; i < mat->longueur; i++){
    for(int j = 0; j < mat->largeur; j++){
      mat->Mat[i][j] = ((long double)rand()/RAND_MAX*2.0-1.0)*100;
    }
  }
}

void remplisAleaInt(matrice *mat){
  for(int i = 0; i < mat->longueur; i++){
    for(int j = 0; j < mat->largeur; j++){
      mat->Mat[i][j] = (long double)((int)(((float)rand()/RAND_MAX*2.0-1.0)*100));
    }
  }
}

matrice *additionMatrice(matrice mat1, matrice mat2)
{
  // initialisation des variables
  matrice *fini;
  long double res;

  // initialisation de la matrice de retour

  // création de la matrice fini avec la taille de la taille max entre
  // 2 matrices
  fini = creerMatrice(
      (mat1.largeur > mat2.largeur) ? mat1.largeur : mat2.largeur,
      (mat1.longueur > mat2.longueur) ? mat1.longueur : mat2.longueur);

  // mise du resultat dans la matrice de retour
  for (int i = 0; i < fini->longueur; i++)
  {
    for (int j = 0; j < fini->largeur; j++)
    {
      res = 0;
      if ((mat1.longueur > i) && (mat1.largeur > j))
      {
        res += mat1.Mat[i][j];
      }
      if ((mat2.longueur > i) && (mat2.largeur > j))
      {
        res += mat2.Mat[i][j];
      }
      fini->Mat[i][j] = res;
    }
  }

  // retour de la matrice de resultat
  return fini;
}

matrice *multiplicationMatrice(matrice mat1, matrice mat2){
  // verification des conditions
  if(mat1.largeur != mat2.longueur){
    printf("On ne peu pas multiplier ces deux matrices ensemble.\n");
    return NULL;
  }
  
  // initialisation des variables
  matrice *fini = creerMatrice(mat2.largeur, mat1.longueur);
  long double lambda;
  afficheMatrice(mat1);
  //calcule de chaque case une par une
  for(int i = 0; i < mat1.longueur; i++){
    for(int j = 0; j < mat2.largeur; j++){
      lambda = 0;
      for(int h = 0; h < mat1.largeur; h++){
	lambda += (mat1.Mat[i][h]*mat2.Mat[h][j]);
      }
      fini->Mat[i][j] = lambda;
    }
  }
  

  return fini;
}

/* Pour inverser une matrice dont les coeff sont nul sauf la diagonale */
void InversematriceD(int taille, matrice *D)
{
  for (int i = 0; i < D->longueur; i++)
  {
    for (int j = 0; j < D->largeur; j++)
    {
      if ((i == j) && (D->Mat[i][j] != 0))
      {
        D->Mat[i][j] = 1 / D->Mat[i][j];
      }
    }
  }
}

matrice *Jacobi(matrice *A, matrice *B)
{
  /* gestion des cas d'erreur pouvant faire echouer la methode jacobi*/
  if((A->largeur != A->longueur) || (A->longueur != B->longueur) || (B->largeur != 1)){
    printf("Les matrice ne sont pas de la taille nécessaire a leurs résolution.");
    return B;
  }else{
    for(int i = 0; i < A->longueur; i++){
      int verifieur = 0;
      for(int j = 0; j < A->longueur; j++){
	if(j != i){
	  verifieur += fabsl(A->Mat[i][j]);
	}
      }
      if(verifieur > A->Mat[i][i]){
	printf("La matrice n'est pas à diagonale dominante et ne vas donc pas converger...\n");
	return B;
      }
    }
  }

  /* création pour résoudre le système */
  matrice *x = creerMatrice(1, A->longueur);
  matrice *D = creerMatrice(A->largeur, A->longueur);
  matrice *E = creerMatrice(A->largeur, A->longueur);
  matrice *F = creerMatrice(A->largeur, A->longueur);

  /* initialisation de D E et F */
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      if (i == j)
      {
        D->Mat[i][j] = A->Mat[i][j];
        E->Mat[i][j] = 0;
        F->Mat[i][j] = 0;
      }
      else if (i < j)
      {
        D->Mat[i][j] = 0;
        E->Mat[i][j] = A->Mat[i][j];
        F->Mat[i][j] = 0;
      }
      else
      {
        D->Mat[i][j] = 0;
        E->Mat[i][j] = 0;
        F->Mat[i][j] = A->Mat[i][j];
      }
    }
  }

  int k = 0;
  float sigma = 0.0;
  while ((pow(sigma, k)) >= sigma)
  {
    // TODO: retirer cette ligne qui annule juste la boucle infini
    sigma = 3;
    printf("Test\n");
  }
  return x;
}




void rempliBord(matrice *A){
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      if(i == j){
	A->Mat[i][j] = 1;
      }else if(i == 0){
	A->Mat[i][j] = pow(2, -(j+1));
      }else if(j == 0){
	A->Mat[i][j] = pow(2, -(i+1));
      }else {
	A->Mat[i][j] = 0;
      }
    }
  }
}

void rempliDingDong(matrice *A){
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      A->Mat[i][j] = 1/(2*(A->largeur - (i+1) - (j+1) + 1.5f));
    }
  }
}

void rempliFranc(matrice *A){
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      if(i >= j+2){
	A->Mat[i][j] = 0;
      }else {
	A->Mat[i][j] = (i > j) ? (j+1) : (i+1);
      }
    }
  }
}

void rempliHilbertNeg(matrice *A){
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      A->Mat[i][j] = 1/((i+1) + (j+1) - 1.0f);
    }
  }
}

void rempliHilbertPos(matrice *A){
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      A->Mat[i][j] = 1/((i+1) + (j+1) + 1.0f);
    }
  }
}

void rempliKms(matrice *A){
  int p = ((float)rand()/RAND_MAX*2.0-1.0);
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      A->Mat[i][j] = pow(p, abs(i-j));
    }
  }
}

void rempliLehmer(matrice *A){
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      if(i <= j){
	A->Mat[i][j] = (i+1)/(j+1);
      }else{
	A->Mat[i][j] = (j+1)/(i+1);
      }
    }
  }
}

void rempliLotkin(matrice *A) {
  for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      if(i == 1){
	A->Mat[i][j] = 1;
      }else{
	A->Mat[i][j] = 1/((i+1)+(j+1)-1);
      }
    }
  }
 }

 void rempliMoler(matrice *A) {
   for(int i = 0; i < A->longueur; i++){
    for(int j = 0; j < A->largeur; j++){
      if(i == j){
	A->Mat[i][j] = (i+1);
      }else{
	A->Mat[i][j] = (i > j) ? (j+1)-2 : (i+1)-2;
      }
    }
  }
}




matrice *Gauss(matrice mat){
  /* gestion du cas d'erreur ou la matrice n'est pas carré*/
  if(mat.longueur != mat.largeur){
    printf("On échelonne uniquement des matrices carré...\n");
    return NULL;
  }

  /* initialisation des valeurs utile a la résolution de la methode de gauss*/
  long double lambda;
  int n = mat.largeur;
  int ThisLineOk = 0;
  matrice *res = creerMatrice( n, n);

  /* copi de la matrice passé en parametre dans une matrice qui poura etre retourné*/
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      res->Mat[i][j] = mat.Mat[i][j];
    }
  }

 /* échange des lignes de la matrice afin d'enler tout les 0 de la diagonale et cas d'echec si c'est impossible  (TODO : upgrade this)*/
  for(int i = 0; i < n; i++){
    if(res->Mat[i][i] == 0){
      for(int j = 0; j < n; j++){
	if(((res->Mat[j][i] != 0)  && (res->Mat[i][j] != 0) && (j < i)) || ((j > i) && (res->Mat[j][i] != 0))){
	  for(int k = 0; k < n; k++){
	    lambda = res->Mat[j][k];
	    res->Mat[j][k] = res->Mat[i][k];
	    res->Mat[i][k] = lambda;
	  }
	  break;
	}else if(j == n-1){
	  ThisLineOk = 0;
	  for(int k = 0; (k < i) && (ThisLineOk == 0); k++){
	    if(res->Mat[k][i] != 0){
	      for(int h = i+1; (h < n) && (ThisLineOk == 0); h++){
		if(res->Mat[h][k] != 0){
		  for(int p = 0; (p < n) && (ThisLineOk == 0); p++){
		    lambda = res->Mat[k][p];
		    res->Mat[k][p] = res->Mat[h][p];
		    res->Mat[h][p] = res->Mat[i][p];
		    res->Mat[i][p] = lambda;
		  }
		  ThisLineOk = 1;
		}
	      }
	    }
	  }
	  if(!ThisLineOk){
	    afficheMatrice(*res);
	    printf("Le probleme est pour la ligne %d ou on auras forcement un zéro...\n", i+1);
	    printf("Ne marche pas sur cette matrice car la diagonale a forcement au moins 1 zéro...\n\n");
	    return res;
	  }
	}
      }
    }
  }

  /* application du theoreme de gauss sur la matrice*/
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      lambda = -(res->Mat[i][j]);
      for(int k = 0; k < n; k++){
	res->Mat[i][k] = lambda*res->Mat[j][k] + res->Mat[i][k];
      }
    }
    lambda = res->Mat[i][i];
    for(int k = 0; k < n; k++){
      res->Mat[i][k] = res->Mat[i][k]/lambda;
    }
  }
  /* renvoie du resultat */
  return res;
}




matrice *ResolutionParGauss(matrice mat, matrice B){
  /* gestion du cas d'erreur ou la matrice n'est pas carré*/
  if(mat.longueur != mat.largeur){
    printf("On travaille uniquement sur des matrices carré...\n");
    return NULL;
  }

  /* initialisation des valeurs utile a la résolution de la methode de gauss*/
  long double lambda;
  int n = mat.largeur;
  int ThisLineOk = 0;
  matrice *res = creerMatrice( 1, n);
  matrice *A = creerMatrice(mat.largeur, mat.largeur);

  for(int i = 0; i < mat.largeur; i++){
    for(int j = 0; j < mat.longueur; j++){
      A->Mat[i][j] = mat.Mat[i][j];
    }
  }


  
  /* copi de la matrice passé en parametre dans une matrice qui poura etre retourné*/
  for(int j = 0; j < n; j++){
    res->Mat[j][0] = B.Mat[j][0];
  }

  /* échange des lignes de la matrice afin d'enler tout les 0 de la diagonale et cas d'echec si c'est impossible  (TODO : upgrade this)*/
  for(int i = 0; i < n; i++){
    if(A->Mat[i][i] == 0){
      for(int j = 0; j < n; j++){
	if(((A->Mat[j][i] != 0)  && (A->Mat[i][j] != 0) && (j < i)) || ((j > i) && (A->Mat[j][i] != 0))){
	  for(int k = 0; k < n; k++){
	    lambda = A->Mat[j][k];
	    A->Mat[j][k] = A->Mat[i][k];
	    A->Mat[i][k] = lambda;
	  }
	  lambda = res->Mat[j][0];
	  res->Mat[j][0] = res->Mat[i][0];
	  res->Mat[i][0] = lambda;
	  break;
	}else if(j == n-1){
	  ThisLineOk = 0;
	  for(int k = 0; (k < i) && (ThisLineOk == 0); k++){
	    if(A->Mat[k][i] != 0){
	      for(int h = i+1; (h < n) && (ThisLineOk == 0); h++){
		if(A->Mat[h][k] != 0){
		  for(int p = 0; (p < n) && (ThisLineOk == 0); p++){
		    lambda = A->Mat[k][p];
		    A->Mat[k][p] = A->Mat[h][p];
		    A->Mat[h][p] = A->Mat[i][p];
		    A->Mat[i][p] = lambda;
		  }
		  lambda = A->Mat[k][0];
		  res->Mat[k][0] = res->Mat[h][0];
		  res->Mat[h][0] = res->Mat[i][0];
		  res->Mat[i][0] = lambda;
		  ThisLineOk = 1;
		}
	      }
	    }
	  }
	  if(!ThisLineOk){
	    afficheMatrice(*A);
	    printf("Le probleme est pour la ligne %d ou on auras forcement un zéro...\n", i+1);
	    printf("Ne marche pas sur cette matrice car la diagonale a forcement au moins 1 zéro...\n\n");
	    return res;
	  }
	}
      }
    }
  }
  
  /* application du theoreme de gauss sur la matrice augmenté AB*/
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      lambda = -(A->Mat[i][j]);
      for(int k = 0; k < n; k++){
	A->Mat[i][k] = lambda*A->Mat[j][k] + A->Mat[i][k];
      }
      res->Mat[i][0] = lambda*res->Mat[j][0] + res->Mat[i][0];
    }
    lambda = A->Mat[i][i];
    for(int k = 0; k < n; k++){
      A->Mat[i][k] = A->Mat[i][k]/lambda;
    }
    res->Mat[i][0] = res->Mat[i][0]/lambda;
  }

  /* application de calcule simple sur la matrice augmenté pour obtenir le resultat */

  for(int i = n-2; i > -1; i--){
    lambda = 0;
    for(int j = i+1; j < n; j++){
      lambda -= (A->Mat[i][j]*res->Mat[j][0]);
    }
    res->Mat[i][0] += lambda; 
  }

  destroyMatrice(A);

  
  /* renvoie du resultat */
  return res;
}
