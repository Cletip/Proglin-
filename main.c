#include "main.h"
#include "fonction.h"

int main()
{
  srand(time(NULL));

  int size = 0;
  matrice *A;
  matrice *X;
  matrice *B;
  matrice *temporaire;
  char choix = 'A';

  int valeurTemporaire;
  
  A = creerMatrice(1, 1);
  X = creerMatrice(1, 1);
  B = creerMatrice(1, 1);
  
  printf("Bonjours et bienvenue dans ce programme de résolution de matrice.\n");
  printf("Pour voire l'aide utiliser la lettre h.\n");

  while(choix != 'q'){
    printf("Que voulez vous faire ?");
    scanf("%c", &choix);getchar();
    switch(choix){
    case 'h' :
      printf("    h : Afficher cette aide.\n    a : Afficher les matrices A, X et B\n    m : Multiplier 2 matrices demander ultérieurement par la commande.\n    q : Quitter.\n\n");
      break;
    case 'm' : casMultiplication(A, B, X);
      break;
    case 'a' : printf("La matrice A est :\n");afficheMatrice(*A);printf("La matrice X est :\n");afficheMatrice(*X);printf("La matrice B est :\n");afficheMatrice(*B);break;
    default : printf("Toutes les lettres a rentrés (excepté les noms de matrices) sont en minuscule. Utiliser h pour savoir quels sont vos choix.\n\n");
    }



    
  }


















  int estAdiagdomine = 0;
  int taille = 2;

  matrice *t = creerMatrice(5, 5);
  matrice *e = creerMatrice(taille, taille);
  matrice *f = creerMatrice(1, taille);

  remplisAlea(t);
  while (!estAdiagdomine)
  {
    remplisAleaBcpZero(e);
    estAdiagdomine = 1;
    for (int i = 0; i < taille; i++)
    {
      int verifieur = 0;
      for (int j = 0; j < taille; j++)
      {
        if (j != i)
        {
          verifieur += fabsl(e->Mat[i][j]);
        }
      }
      if (verifieur > e->Mat[i][i])
      {
        estAdiagdomine = 0;
        break;
      }
    }
  }

  remplisAlea(f);

  e->Mat[0][0] = 5;
  e->Mat[0][1] = 3;
  e->Mat[1][0] = 2;
  e->Mat[1][1] = 5;
  /* afficheMatrice(*t); */

  matrice *s = Gauss(*t);

  /* afficheMatrice(*s); */

  matrice *a = creerMatrice(4, 4);
  remplisAleaBcpZero(a);
  /* afficheMatrice(*a); */
  InversematriceD(4, a);
  /* afficheMatrice(*a); */

  matrice *x = Jacobi(e, f, 0.0001, 200);
  afficheMatrice(*x);

  printf(" ligne blanche\n");
  afficheMatrice(*f);

  matrice *Test = creerMatrice(3, 3);
  remplisAleaInt(Test);
  afficheMatrice(*Test);
  matrice *ResT = creerMatrice(1, 3);
  remplisAleaInt(ResT);
  afficheMatrice(*ResT);
  matrice *FC = ResolutionParGauss(*Test, *ResT);
  afficheMatrice(*FC);

  matrice *verif = multiplicationMatrice(*Test, *FC);
  afficheMatrice(*verif);

  rempliBord(Test);
  afficheMatrice(*Test);

  rempliDingDong(Test);
  afficheMatrice(*Test);

  rempliFranc(Test);
  afficheMatrice(*Test);

  rempliHilbertNeg(Test);
  afficheMatrice(*Test);

  rempliHilbertPos(Test);
  afficheMatrice(*Test);

  rempliKms(Test);
  afficheMatrice(*Test);

  rempliLehmer(Test);
  afficheMatrice(*Test);

  rempliLotkin(Test);
  afficheMatrice(*Test);

  rempliMoler(Test);
  afficheMatrice(*Test);

  return 0;
}




void casMultiplication(matrice *A, matrice *B, matrice *X){
  char choix;
  char valeurTemporaire;
  matrice *temporaire;
  printf("Vous pouvez :\n        s : Stocker le résultat.\n        a : afficher le résultat.\n Que voulez vous faire : ");scanf("%c", &choix);getchar();
  if(choix == 'a'){
    printf("Entrez le nom de la première matrice de la multiplication (A, B ou X): ");
    scanf("%c", &choix);getchar();
    valeurTemporaire = (int)(choix);
    printf("Entrez le nom de la seconde matrice de la multiplication (A, B ou X): ");
    scanf("%c", &choix);getchar();
    if(valeurTemporaire-(int)('A') == 0){
      switch (choix) {
      case 'A' : temporaire = multiplicationMatrice(*A, *A); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      case 'B' : temporaire = multiplicationMatrice(*A, *B); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      case 'X' : temporaire = multiplicationMatrice(*A, *X); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
      } 
    } else if(valeurTemporaire-(int)('B') == 0){
      switch (choix) {
      case 'A' : temporaire = multiplicationMatrice(*B, *A); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      case 'B' : temporaire = multiplicationMatrice(*B, *B); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      case 'X' : temporaire = multiplicationMatrice(*B, *X); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
      } 
    } else if(valeurTemporaire-(int)('X') == 0){
      switch (choix) {
      case 'A' : temporaire = multiplicationMatrice(*X, *A); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      case 'B' : temporaire = multiplicationMatrice(*X, *B); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      case 'X' : temporaire = multiplicationMatrice(*X, *X); if(temporaire != NULL){afficheMatrice(*temporaire); destroyMatrice(temporaire);}break;
      default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
      } 
    }else{
      printf("La première matrice que vous avez tapé n'existe pas...\n");
    }
  }else if(choix == 's'){
    printf("Dans quel matrice voulez vous stocker le résultat (A, B ou X) ? ");
    scanf("%c", &choix);getchar();
    if(choix == 'A'){
      printf("Entrez le nom de la première matrice de la multiplication (A, B ou X) : ");
      scanf("%c", &choix);getchar();
      valeurTemporaire = (int)(choix);
      printf("Entrez le nom de la seconde matrice de la multiplication (A, B ou X) : ");
      scanf("%c", &choix);getchar();
      if(valeurTemporaire-(int)('A') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*A, *A); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*A, *B); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*A, *X); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      } else if(valeurTemporaire-(int)('B') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*B, *A); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*B, *B); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*B, *X); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      } else if(valeurTemporaire-(int)('X') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*X, *A); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*X, *B); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*X, *X); if(temporaire != NULL){destroyMatrice(A); A = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      }else{
	printf("La première matrice que vous avez tapé n'existe pas...\n");
      }
    } else if(choix == 'B'){
      printf("Entrez le nom de la première matrice de la multiplication (A, B ou X) : ");
      scanf("%c", &choix);getchar();
      valeurTemporaire = (int)(choix);
      printf("Entrez le nom de la seconde matrice de la multiplication (A, B ou X) : ");
      scanf("%c", &choix);getchar();
      if(valeurTemporaire-(int)('A') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*A, *A); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*A, *B); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*A, *X); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      } else if(valeurTemporaire-(int)('B') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*B, *A); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*B, *B); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*B, *X); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      } else if(valeurTemporaire-(int)('X') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*X, *A); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*X, *B); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*X, *X); if(temporaire != NULL){destroyMatrice(B); B = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      }else{
	printf("La première matrice que vous avez tapé n'existe pas...\n");
      }
    } else if(choix == 'X'){
      printf("Entrez le nom de la première matrice de la multiplication (A, B ou X) : ");
      scanf("%c", &choix);getchar();
      valeurTemporaire = (int)(choix);
      printf("Entrez le nom de la seconde matrice de la multiplication (A, B ou X) : ");
      scanf("%c", &choix);getchar();
      if(valeurTemporaire-(int)('A') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*A, *A); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*A, *B); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*A, *X); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      } else if(valeurTemporaire-(int)('B') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*B, *A); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*B, *B); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*B, *X); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      } else if(valeurTemporaire-(int)('X') == 0){
	switch (choix) {
	case 'A' : temporaire = multiplicationMatrice(*X, *A); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	case 'B' : temporaire = multiplicationMatrice(*X, *B); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	case 'X' : temporaire = multiplicationMatrice(*X, *X); if(temporaire != NULL){destroyMatrice(X); X = temporaire;}break;
	default: printf("La seconde matrice que vous avez tapé n'existe pas...\n");break;
	} 
      }else{
	printf("La première matrice que vous avez tapé n'existe pas...\n");
      }
    }else{
      printf("Le choix que vous avez tapé n'existe pas.\n");
    }
  }else{
    printf("Le choix que vous avez tapé n'existe pas.\n");
  }  
}
