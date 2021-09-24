/* toutes les fct */
#include "fonction.h"


matrice *creerMatrice(int largeur, int longueur){
  matrice *fini = (matrice *)malloc(sizeof(matrice));

  fini->longueur = longueur;
  fini->largeur = largeur;

  fini->Mat = (long double **)malloc(fini->longueur*sizeof(long double*));
  for(int i = 0; i < fini->longueur; i++){
    fini->Mat[i] = (long double*)malloc(fini->largeur*sizeof(long double));
        for(int j = 0; j < fini->largeur; j++){
	  fini->Mat[i][j] = 0;
	}
  }
  return fini;
}

void destroyMatrice(matrice *mat){
  for(int i = 0; i < mat->longueur; i++){
    free(mat->Mat[i]);
  }
  free(mat->Mat);
  mat->longueur = 0;
  mat->largeur = 0;
}

void afficheMatrice(matrice mat){
  for(int i = 0; i < mat.longueur; i++){
    for(int j = 0; j < mat.largeur; j++){
      printf("%LF ", mat.Mat[i][j]);
    }
    printf("\n");
  } 
  printf("\n");
}

void remplisAleaBcpZero(matrice *mat){
  for(int i = 0; i < mat->longueur; i++){
    for(int j = 0; j < mat->largeur; j++){
      if(rand()%100 <= 70){
	mat->Mat[i][j] = 0;
      }else{
	mat->Mat[i][j] = ((long double)rand()/RAND_MAX*2.0-1.0)*100;
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
 
matrice *additionMatrice(matrice mat1, matrice mat2){
  // initialisation des variable
  matrice *fini = (matrice *)malloc(sizeof(matrice));
  long double res;

  // initialisation de la matrice de retour
  fini->longueur = (mat1.longueur>mat2.longueur)?mat1.longueur:mat2.longueur;
  fini->largeur = (mat1.largeur>mat2.largeur)?mat1.largeur:mat2.largeur;
  fini->Mat = (long double **)malloc(fini->longueur*sizeof(long double*));
  for(int i = 0; i < fini->longueur; i++){
    fini->Mat[i] = (long double*)malloc(fini->largeur*sizeof(long double));
  }

  //mise du resultat dans la matrice de retour
  for(int i = 0; i < fini->longueur; i++){
    for(int j = 0; j < fini->largeur; j++){
      res = 0;
      if((mat1.longueur > i) && (mat1.largeur > j)){
	res+=mat1.Mat[i][j];
      }
      if((mat2.longueur > i) && (mat2.largeur > j)){
	res+=mat2.Mat[i][j];
      }
      fini->Mat[i][j] = res;
    }
  }

  //retour de la matrice de resultat
  return fini;
}


matrice *Gauss(matrice mat){
  if(mat.longueur != mat.largeur){
    printf("On échelonne uniquement des matrices carré...\n");
    return NULL;
  }else {
    long double lambda;
    int n = mat.largeur;
    matrice *res = creerMatrice( n, n);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	res->Mat[i][j] = mat.Mat[i][j];
      }
    }
    afficheMatrice(*res);
    for(int i = 0; i < n; i++){
      if(res->Mat[i][i] == 0){
	for(int j = 0; j < n; j++){
	  if((res->Mat[j][i] != 0) && (res->Mat[i][j] != 0)){
	    for(int k = 0; k < n; k++){
	      lambda = res->Mat[j][k];
	      res->Mat[j][k] = res->Mat[i][k];
	      res->Mat[i][k] = lambda;
	    }
	    break;
	  }else if(j == n-1){
	    printf("Ne marche pas sur cette matrice car la diagonale a forcement au moins 1 zéro...\n");
	    return res;
	  }
	}
      }
    }
    afficheMatrice(*res);
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
    
    return res;
  }
}
