/* toutes les fct */
#include "fonction.h"
#include "matricetest.c"
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
      if(i == j){
	printf("\033[0;31m"); 
	printf("%12.7LF ", mat.Mat[i][j]);
	printf("\033[0m");
      }else{
	printf("%12.7LF ", mat.Mat[i][j]);
      }
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

void remplisAleaDiagonalDominante(matrice *mat){
  long double somme;
  for(int i = 0; i < mat->largeur; i++){
    somme = 0;
    for(int j = 0; j < mat->longueur; j++){
      if(i != j){
	
	mat->Mat[j][i] = ((long double)rand()/RAND_MAX*2.0-1.0)*100;
	somme += fabsl(mat->Mat[j][i]);
      }
    }
    if(i < mat->longueur){
      mat->Mat[i][i] = somme + fabsl(((long double)rand()/RAND_MAX*2.0-1.0)*100);
    }
  }
}

void remplisBeaucoupZeroDiagDomi(matrice *mat){
  remplisAleaDiagonalDominante(mat);
  int nb = 0;
  int value = (int)((mat->largeur*mat->longueur)*0.7f);
  int echec = 0;
  while((nb <= value) && (echec < 10)){
    int x = (int)(rand())%(mat->longueur);
    int y = (int)(rand())%(mat->largeur);
    if(x != y){
      if(mat->Mat[x][y] != 0){
	mat->Mat[x][y] =0;
	echec = 0;
	nb++;
      }else{
	echec++;
      }
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

matrice *soustractino(matrice mat1, matrice mat2)
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
        res = mat1.Mat[i][j];
      }
      if ((mat2.longueur > i) && (mat2.largeur > j))
      {
        res -= mat2.Mat[i][j];
      }
      fini->Mat[i][j] = res;
    }
  }

  // retour de la matrice de resultat
  return fini;
}

matrice *multiplicationMatrice(matrice mat1, matrice mat2)
{
  // verification des conditions
  if (mat1.largeur != mat2.longueur)
  {
    printf("On ne peu pas multiplier ces deux matrices ensemble.\n");
    return NULL;
  }

  // initialisation des variables
  matrice *Xfini = creerMatrice(mat2.largeur, mat1.longueur);
  long double lambda;
  /* afficheMatrice(mat1); */
  // calcule de chaque case une par une
  for (int i = 0; i < mat1.longueur; i++)
  {
    for (int j = 0; j < mat2.largeur; j++)
    {
      lambda = 0;
      for (int h = 0; h < mat1.largeur; h++)
      {
        lambda += (mat1.Mat[i][h] * mat2.Mat[h][j]);
      }
      Xfini->Mat[i][j] = lambda;
    }
  }

  return Xfini;
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

float Norme(matrice *colonne)
{
  float norme = 0;
  for (int i = 0; i < colonne->longueur; ++i)
  {
    norme = norme + pow(colonne->Mat[i][0], 2);
  }
  return sqrt(norme);
}

matrice *Jacobi(matrice *A, matrice *B, float Eps, int nombremaxinte, int *compteur)
{
  /* gestion des cas d'erreur pouvant faire echouer la methode jacobi*/
  if ((A->largeur != A->longueur) || (A->longueur != B->longueur) ||
      (B->largeur != 1))
  {
    printf(
        "Les matrice ne sont pas de la taille nécessaire a leurs résolution.");
    return B;
  }
  else
  {
    for (int i = 0; i < A->longueur; i++)
    {
      int verifieur = 0;
      for (int j = 0; j < A->longueur; j++)
      {
        if (j != i)
        {
          verifieur += fabsl(A->Mat[i][j]);
        }
      }
      if (verifieur > A->Mat[i][i])
      {
        printf("La matrice n'est pas à diagonale dominante et ne vas donc pas "
               "converger...\n");
        return B;
      }
    }
  }

  /* création pour résoudre le système */
  matrice *x = creerMatrice(1, A->longueur);
  matrice *D = creerMatrice(A->largeur, A->longueur);
  matrice *E = creerMatrice(A->largeur, A->longueur);
  matrice *F = creerMatrice(A->largeur, A->longueur);
  matrice *N = creerMatrice(A->largeur, A->longueur);

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
        E->Mat[i][j] = -(A->Mat[i][j]);
        F->Mat[i][j] = 0;
      }
      else
      {
        D->Mat[i][j] = 0;
        E->Mat[i][j] = 0;
        F->Mat[i][j] = -(A->Mat[i][j]);
      }
      N->Mat[i][j] = E->Mat[i][j] + F->Mat[i][j];
    }
  }

  // initialisation de x
  /* for (int i = 0; i < x->longueur; ++i) */
  /* { */
  /* x->Mat[0][i] = 0; */
  /* } */

  float erreur = Eps + 1;
  *compteur = 0;
  InversematriceD(D->longueur, D);

  
  /* while ((pow(sigma, k)) >= sigma) */
  while ((erreur > Eps) && (nombremaxinte > *compteur))
  {
    // nouvelle valeur de x selon la formule
    x = multiplicationMatrice(
        *D, *additionMatrice(*(multiplicationMatrice(*N, *x)), *B));

    // TODO: retirer cette ligne qui annule juste la boucle infini
    erreur = Norme(soustractino(*multiplicationMatrice(*A, *x), *B));
    (*compteur)++;
  }
  //printf("Le nombre d'itération de jacobi est de %d\n", compteur);
  return x;
}

matrice *Gauss(matrice mat){
  /* gestion du cas d'erreur ou la matrice n'est pas carré*/
  if (mat.longueur != mat.largeur)
  {
    printf("On échelonne uniquement des matrices carré...\n");
    return NULL;
  }

  /* initialisation des valeurs utile a la résolution de la methode de gauss*/
  long double lambda;
  int n = mat.largeur;
  matrice *res = creerMatrice(n, n);
  int okayDiag = 0;

  /* copie de la matrice passé en paramètre dans une matrice qui pourra être
   * retournée
   */
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      res->Mat[i][j] = mat.Mat[i][j];
    }
  }

  /* échange des lignes de la matrice afin d'enler tout les 0 de la diagonale et
   * cas d’échec si c'est impossible
   */
  for(int i = 0; i < n; i++){
    if(res->Mat[i][i] == 0){
      okayDiag++;
    }
  }
  while(okayDiag){
    int change = 0;
    for(int i = 0; i < n; i++){
      if(res->Mat[i][i] == 0){
	for(int j = 0; j < n; j++){
	  if(j < i){
	    if(res->Mat[i][j] != 0 && res->Mat[j][i] != 0){
	      swapLine(res, i, j);
	      okayDiag--;
	      change++;
	      break;
	    }
	  }else if(j > i){
	    if(res->Mat[j][i] != 0){
	      if(res->Mat[i][j] != 0){
		okayDiag--;
	      }
	      swapLine(res, i, j);
	      change++;
	      break;
	    }
	  }
	  
	}
      }
    }
    if(change == 0){
      okayDiag = 0;
      for(int i = 0; i < n; i++){
	if(res->Mat[i][i] == 0){
	  okayDiag++;
	}
      }
      if(okayDiag){
	printf("La matrice ne peut avoir de diagonale sans zéros...\n");
	return res;
      }
    }
  }

  

  
  /* application du theoreme de gauss sur la matrice*/
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      lambda = -(res->Mat[i][j]);
      for (int k = 0; k < n; k++)
      {
        res->Mat[i][k] = lambda * res->Mat[j][k] + res->Mat[i][k];
      }
    }
    lambda = res->Mat[i][i];
    for (int k = i; k < n; k++)
    {
      res->Mat[i][k] = res->Mat[i][k] / lambda;
    }
  }
  /* renvoie du resultat */
  return res;
}

void swapLine(matrice *mat, int a, int b){
  //  long double temp;
  //for(int i = 0; i < mat->largeur; i++){
  //  temp = mat->Mat[a][i];
  //  mat->Mat[a][i] = mat->Mat[b][i];
  //  mat->Mat[b][i] = temp;
  //}

  long double *tempo;
  tempo = mat->Mat[a];
  mat->Mat[a] = mat->Mat[b];
  mat->Mat[b] = tempo;  
}

matrice *ResolutionParGauss(matrice mat, matrice B)
{
  /* gestion du cas d'erreur ou la matrice n'est pas carré*/
  if (mat.longueur != mat.largeur)
  {
    printf("On travaille uniquement sur des matrices carré...\n");
    return NULL;
  }

  /* initialisation des valeurs utile a la résolution de la methode de gauss*/
  long double lambda;
  int n = mat.largeur;
  int okayDiag = 0;
  matrice *res = creerMatrice(1, n);
  matrice *A = creerMatrice(mat.largeur, mat.largeur);

  
  
  for (int i = 0; i < mat.largeur; i++)
  {
    for (int j = 0; j < mat.longueur; j++)
    {
      A->Mat[i][j] = mat.Mat[i][j];
    }
  }

  /* copi de la matrice passé en parametre dans une matrice qui poura etre
   * retourné*/
  for (int j = 0; j < n; j++)
  {
    res->Mat[j][0] = B.Mat[j][0];
  }

  
  for (int i = 0; i < mat.largeur; i++)
  {
    for (int j = 0; j < mat.longueur; j++)
    {
      A->Mat[i][j] = mat.Mat[i][j];
    }
  }

  /* copi de la matrice passé en parametre dans une matrice qui poura etre
   * retourné*/
  for (int j = 0; j < n; j++)
  {
    res->Mat[j][0] = B.Mat[j][0];
  }


  /* échange des lignes de la matrice afin d'enler tout les 0 de la diagonale et
   * cas d’échec si c'est impossible
   */
  for(int i = 0; i < n; i++){
    if(A->Mat[i][i] == 0){
      okayDiag++;
    }
  }
  while(okayDiag){
    int change = 0;
    for(int i = 0; i < n; i++){
      if(A->Mat[i][i] == 0){
	for(int j = 0; j < n; j++){
	  if(j < i){
	    if(A->Mat[i][j] != 0 && A->Mat[j][i] != 0){
	      swapLine(A, i, j);
	      swapLine(res, i, j);
	      okayDiag--;
	      change++;
	      break;
	    }
	  }else if(j > i){
	    if(A->Mat[j][i] != 0){
	      if(A->Mat[i][j] != 0){
		okayDiag--;
	      }
	      swapLine(A, i, j);
	      swapLine(res, i, j);
	      change++;
	      break;
	    }
	  }
	  
	}
      }
    }
    if(change == 0){
      okayDiag = 0;
      for(int i = 0; i < n; i++){
	if(A->Mat[i][i] == 0){
	  okayDiag++;
	}
      }
      if(okayDiag){
	printf("La matrice ne peut avoir de diagonale sans zéros...\n");
	destroyMatrice(res);
	return A;
      }
    }
  }

  
  /* application du theoreme de gauss sur la matrice augmenté AB*/
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      lambda = -(A->Mat[i][j]);
      for (int k = 0; k < n; k++)
      {
        A->Mat[i][k] = lambda * A->Mat[j][k] + A->Mat[i][k];
      }
      res->Mat[i][0] = lambda * res->Mat[j][0] + res->Mat[i][0];
    }
    lambda = A->Mat[i][i];
    for (int k = 0; k < n; k++)
    {
      A->Mat[i][k] = A->Mat[i][k] / lambda;
    }
    res->Mat[i][0] = res->Mat[i][0] / lambda;
  }

  /* application de calcule simple sur la matrice augmenté pour obtenir le
   * resultat */

  for (int i = n - 2; i > -1; i--)
  {
    lambda = 0;
    for (int j = i + 1; j < n; j++)
    {
      lambda -= (A->Mat[i][j] * res->Mat[j][0]);
    }
    res->Mat[i][0] += lambda;
  }

  destroyMatrice(A);

  /* renvoie du resultat */
  return res;
}
