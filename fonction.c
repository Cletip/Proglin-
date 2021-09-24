/* toutes les fct */
#include "fonction.h"

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

matrice *additionMatrice(matrice mat1, matrice mat2)
{
  // initialisation des variables
  matrice *fini = (matrice *)malloc(sizeof(matrice));
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
    printf("Test\n");
  }
  return x;
}
