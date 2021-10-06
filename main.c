#include "main.h"
#include "fonction.h"
#include <ctype.h>
#include <stdio.h>

int main()
{
  srand(time(NULL));

  matrice *A;
  matrice *X;
  matrice *B;
  char choix = 'A';
  int large = -1;
  int longu = -1;

  char valeurTemporaire;
  matrice *temporaire;

  A = creerMatrice(1, 1);
  X = creerMatrice(1, 1);
  B = creerMatrice(1, 1);


  printf("Bonjours et bienvenue dans ce programme de résolution de matrice.\n");
  printf("Pour voire l'aide utiliser la lettre h.\n");
  while (choix != 'q')
  {
    printf("Que voulez vous faire ? ");
    scanf("%c", &choix);
    getchar();
    switch (choix)
    {
    case 'h':
      printf("    h : Afficher cette aide.\n    a : Afficher les matrices A, X "
             "et B\n    m : Multiplier 2 matrices demander ultérieurement par "
             "la commande.\n    c : Changer la taille d'une matrice.\n    r : "
             "remplir manuellement une matrice.\n    f : Remplissage "
             "automatique d'une matrice.\n    j : Résoudre AX = B avec la "
             "méthode de Jacobi.\n    g : Résoudre AX = B avec la méthode de "
             "Gauss.\n    e : rendre une matrice échelonné.\n    v : Changer "
             "la valeur d'une case.\n    p : Testes automatiques.\n    q : Quitter.\n\n");
      break;
    case 'p': casDeVerif();break;
    case 'v':
      casUneCase(A, B, X);
      break;
    case 'e':
      printf("Quelle matrice voulez-vous échelonner (A, B ou X)? ");
      scanf("%c", &choix);
      getchar();
      switch (choix)
      {
      case 'A':
        A = Gauss(*A);
        break;
      case 'B':
        B = Gauss(*B);
        break;
      case 'X':
        X = Gauss(*X);
        break;
      default:
        printf(
            "Vous ne pouvez pas échelonner une matrice qui n'existe pas...\n");
        break;
      }
      break;
    case 'g':
      X = casGauss(A, B, X);
      break;
    case 'j':
      X = casJacobi(A, B, X);
      break;
    case 'f':
      casAutoFill(A, B, X);
      break;
    case 'm':
      printf("Vous pouvez :\n        s : Stocker le résultat.\n        a : "
             "afficher le résultat.\n Que voulez vous faire : ");
      scanf("%c", &choix);
      getchar();
      if (choix == 'a')
      {
        printf("Entrez le nom de la première matrice de la multiplication (A, "
               "B ou X): ");
        scanf("%c", &choix);
        getchar();
        valeurTemporaire = (int)(choix);
        printf("Entrez le nom de la seconde matrice de la multiplication (A, B "
               "ou X): ");
        scanf("%c", &choix);
        getchar();
        if (valeurTemporaire - (int)('A') == 0)
        {
          switch (choix)
          {
          case 'A':
            temporaire = multiplicationMatrice(*A, *A);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          case 'B':
            temporaire = multiplicationMatrice(*A, *B);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          case 'X':
            temporaire = multiplicationMatrice(*A, *X);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          default:
            printf("La seconde matrice que vous avez tapé n'existe pas...\n");
            break;
          }
        }
        else if (valeurTemporaire - (int)('B') == 0)
        {
          switch (choix)
          {
          case 'A':
            temporaire = multiplicationMatrice(*B, *A);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          case 'B':
            temporaire = multiplicationMatrice(*B, *B);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          case 'X':
            temporaire = multiplicationMatrice(*B, *X);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          default:
            printf("La seconde matrice que vous avez tapé n'existe pas...\n");
            break;
          }
        }
        else if (valeurTemporaire - (int)('X') == 0)
        {
          switch (choix)
          {
          case 'A':
            temporaire = multiplicationMatrice(*X, *A);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          case 'B':
            temporaire = multiplicationMatrice(*X, *B);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          case 'X':
            temporaire = multiplicationMatrice(*X, *X);
            if (temporaire != NULL)
            {
              afficheMatrice(*temporaire);
              destroyMatrice(temporaire);
            }
            break;
          default:
            printf("La seconde matrice que vous avez tapé n'existe pas...\n");
            break;
          }
        }
        else
        {
          printf("La première matrice que vous avez tapé n'existe pas...\n");
        }
      }
      else if (choix == 's')
      {
        printf(
            "Dans quel matrice voulez vous stocker le résultat (A, B ou X) ? ");
        scanf("%c", &choix);
        getchar();
        if (choix == 'A')
        {
          printf("Entrez le nom de la première matrice de la multiplication "
                 "(A, B ou X) : ");
          scanf("%c", &choix);
          getchar();
          valeurTemporaire = (int)(choix);
          printf("Entrez le nom de la seconde matrice de la multiplication (A, "
                 "B ou X) : ");
          scanf("%c", &choix);
          getchar();
          if (valeurTemporaire - (int)('A') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*A, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*A, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*A, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else if (valeurTemporaire - (int)('B') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*B, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*B, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*B, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else if (valeurTemporaire - (int)('X') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*X, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*X, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*X, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(A);
                A = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else
          {
            printf("La première matrice que vous avez tapé n'existe pas...\n");
          }
        }
        else if (choix == 'B')
        {
          printf("Entrez le nom de la première matrice de la multiplication "
                 "(A, B ou X) : ");
          scanf("%c", &choix);
          getchar();
          valeurTemporaire = (int)(choix);
          printf("Entrez le nom de la seconde matrice de la multiplication (A, "
                 "B ou X) : ");
          scanf("%c", &choix);
          getchar();
          if (valeurTemporaire - (int)('A') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*A, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*A, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*A, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else if (valeurTemporaire - (int)('B') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*B, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*B, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*B, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else if (valeurTemporaire - (int)('X') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*X, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*X, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*X, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(B);
                B = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else
          {
            printf("La première matrice que vous avez tapé n'existe pas...\n");
          }
        }
        else if (choix == 'X')
        {
          printf("Entrez le nom de la première matrice de la multiplication "
                 "(A, B ou X) : ");
          scanf("%c", &choix);
          getchar();
          valeurTemporaire = (int)(choix);
          printf("Entrez le nom de la seconde matrice de la multiplication (A, "
                 "B ou X) : ");
          scanf("%c", &choix);
          getchar();
          if (valeurTemporaire - (int)('A') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*A, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*A, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*A, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else if (valeurTemporaire - (int)('B') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*B, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*B, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*B, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else if (valeurTemporaire - (int)('X') == 0)
          {
            switch (choix)
            {
            case 'A':
              temporaire = multiplicationMatrice(*X, *A);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            case 'B':
              temporaire = multiplicationMatrice(*X, *B);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            case 'X':
              temporaire = multiplicationMatrice(*X, *X);
              if (temporaire != NULL)
              {
                destroyMatrice(X);
                X = temporaire;
              }
              break;
            default:
              printf("La seconde matrice que vous avez tapé n'existe pas...\n");
              break;
            }
          }
          else
          {
            printf("La première matrice que vous avez tapé n'existe pas...\n");
          }
        }
        else
        {
          printf("Le choix que vous avez tapé n'existe pas.\n");
        }
      }
      else
      {
        printf("Le choix que vous avez tapé n'existe pas.\n");
      }
      break;
    case 'c':
      large = -1;
      longu = -1;
      printf("Quelle matrice voulez-vous modifier la taille (A, B ou X)? ");
      scanf("%c", &choix);
      getchar();
      printf("Entrez maintenant le nombre de colonnes souhaité(un nombre "
             "entier positif) : ");
      while (large < 1)
      {
        scanf("%d", &large);
        getchar();
      }
      printf("Entrez maintenant le nombre de lignes souhaité(un nombre entier "
             "positif) : ");
      while (longu < 1)
      {
        scanf("%d", &longu);
        getchar();
      }
      switch (choix)
      {
      case 'A':
        destroyMatrice(A);
        A = creerMatrice(large, longu);
        break;
      case 'B':
        destroyMatrice(B);
        B = creerMatrice(large, longu);
        break;
      case 'X':
        destroyMatrice(X);
        X = creerMatrice(large, longu);
        break;
      default:
        printf("Vous avez choisi une matrice inexistante...\n");
        break;
      }
      break;
    case 'r':
      casRempli(A, B, X);
      break;
    case 'a':
      printf("La matrice A est :\n");
      afficheMatrice(*A);
      printf("La matrice X est :\n");
      afficheMatrice(*X);
      printf("La matrice B est :\n");
      afficheMatrice(*B);
      break;
    case 'q':
      printf("Au revoir!!!\n");
      break;
    default:
      printf("Toutes les lettres a rentrés (excepté les noms de matrices) sont "
             "en minuscule. Utiliser h pour savoir quels sont vos choix.\n\n");
      getchar();
      break;
    }
  }

  // TODO : Ajouter , soustraire
  // inverse de matrice,
  // norme d'une colonne
 
  return 0;
}

void casDeVerif()
{

  int compteur = -1;
  int larg = -1;
  float epsilon = 0.001;
  int maxIter = -1;

  char choixA = 'A';
  char choixB = 'A';

  int chiffrenotok = 1;
  char s[50];
  int curseur;

  printf("Entrez le nombre de tests (un nombre entier positif) : ");
  while (compteur < 0)
  {
    scanf("%d", &compteur);
    getchar();
  }
  printf("Entrez la taille des matrices de test (un nombre entier positif) : ");
  while (larg < 0)
  {
    scanf("%d", &larg);
    getchar();
  }
  printf("Maintenant pour le cas de Jacobi :\n");

  while (chiffrenotok)
  {
    printf("    Veuillez entrez la valeur de epsilon : ");
    scanf("%s", s);
    getchar();
    curseur = 0;
    chiffrenotok = 0;
    while (s[curseur] != '\0')
    {
      if (s[curseur] == ',' || s[curseur] == '.')
      {
        s[curseur] = '.';
      }
      else if (!isdigit(s[curseur]))
      {
        chiffrenotok = 1;
        break;
      }
      curseur++;
    }
  }
  epsilon = atof(s);

  printf("    Entrez le max d'itération(un nombre entier positif) : ");
  while (maxIter < 0)
  {
    scanf("%d", &maxIter);
    getchar();
  }

  while ((choixA != 'j') && (choixA != 'b') && (choixA != 'k') &&
         (choixA != 'l') && (choixA != 'e'))
  {
    printf("\nDe quelle manière voulez vous remplir la matrice A(Toute les "
           "manières possibles ici sont à diagonale dominante sinon cela "
           "fausserais complètement les résultats de la méthode de Jacobi.) "
           "?\n        j : Aléatoirement avec la diagonale dominante.\n        "
           "e : Avec une diagonale dominante et 70%% de zéros.\n        b : "
           "Avec la méthode de Bord.\n        k : Avec la méthode de Kms.\n    "
           "    l : Avec la méthode de Lehmer.\n");
    scanf("%c", &choixA);
    getchar();
  }

  while ((choixB != 'a') && (choixB != 'i') && (choixB != 'z') &&
         (choixB != 'j') && (choixB != 'b') && (choixB != 'd') &&
         (choixB != 'f') && (choixB != 'n') && (choixB != 'p') &&
         (choixB != 'k') && (choixB != 'l') && (choixB != 'o') &&
         (choixB != 'm'))
  {
    printf("De quelle manière voulez vous remplir la matrice colonne B ?\n     "
           "   a : Aléatoirement entre 100 et -100.\n        i : aléatoirement "
           "par des entiers entre 100 et -100.\n        z : Aléatoirement avec "
           "70 pourcent de zéros.\n        j : Aléatoirement avec la diagonale "
           "dominante.\n        e : Avec une diagonale dominante et 70%% de "
           "zéros.\n        b : Avec la méthode de Bord.\n        d : Avec la "
           "méthode de DingDong.\n        f : Avec la méthode de Franc.\n      "
           "  n : Avec la méthode de Hilbert Négative.\n        p : Avec la "
           "méthode de Hilbert Positive.\n        k : Avec la méthode de "
           "Kms.\n        l : Avec la méthode de Lehmer.\n        o : Avec la "
           "méthode de Lotkin.\n        m : Avec la méthode de Moler.\n");
    scanf("%c", &choixB);
    getchar();
  }
  printf("\n");
  printf("\e[?25l");

  float tempsjaco = 0;
  float tempsgauss = 0;
  float stabjaco = 0;
  float stabgauss = 0;
  float tempo = 0;
  float ErreurGauss = 0;
  float ErreurJaco = 0;
  int pointeur = 0;
  int tempopointeur = 0;

  matrice *A = creerMatrice(larg, larg);
  matrice *X;
  matrice *B = creerMatrice(1, larg);
  matrice *temporaire = creerMatrice(1, larg);

  // boucle pour avoir plusieurs essaies
  for (int i = 0; i < compteur; ++i)
  {
    switch (choixA)
    {
    case 'j':
      remplisAleaDiagonalDominante(A);
      break;
    case 'b':
      rempliBord(A);
      break;
    case 'k':
      rempliKms(A);
      break;
    case 'l':
      rempliLehmer(A);
      break;
    case 'e':
      remplisBeaucoupZeroDiagDomi(A);
      break;
    default:
      printf("Il y a une erreur, %c!!!\n", choixA);
      break;
    }

    switch (choixB)
    {
    case 'a':
      remplisAlea(B);
      break;
    case 'i':
      remplisAleaInt(B);
      break;
    case 'z':
      remplisAleaBcpZero(B);
      break;
    case 'j':
      remplisAleaDiagonalDominante(B);
      break;
    case 'e':
      remplisBeaucoupZeroDiagDomi(B);
      break;
    case 'b':
      rempliBord(B);
      break;
    case 'd':
      rempliDingDong(B);
      break;
    case 'f':
      rempliFranc(B);
      break;
    case 'n':
      rempliHilbertNeg(B);
      break;
    case 'p':
      rempliHilbertPos(B);
      break;
    case 'k':
      rempliKms(B);
      break;
    case 'l':
      rempliLehmer(B);
      break;
    case 'o':
      rempliLotkin(B);
      break;
    case 'm':
      rempliMoler(B);
      break;
    default:
      printf("Il y a une erreur, %c!!!\n", choixB);
      break;
    }

    clock_t t1, t2;
    t1 = clock();
    X = ResolutionParGauss(*A, *B);
    t2 = clock();

    tempsgauss += (float)(t2 - t1);

    X = multiplicationMatrice(*A, *X);
    temporaire = soustractino(*X, *B);
    tempo = 0;
    for (int j = 0; j < larg; j++)
    {
      tempo += fabsl(temporaire->Mat[j][0]);
    }
    tempo = tempo / larg;
    stabgauss += tempo;

    ErreurGauss += Norme(temporaire);

    t1 = clock();
    X = Jacobi(A, B, epsilon, maxIter, &tempopointeur);
    t2 = clock();

    pointeur += tempopointeur;
    tempsjaco += (float)(t2 - t1);

    X = multiplicationMatrice(*A, *X);
    temporaire = soustractino(*X, *B);
    tempo = 0;
    for (int j = 0; j < larg; j++)
    {
      tempo += fabsl(temporaire->Mat[j][0]);
    }
    tempo = tempo / larg;
    stabjaco += tempo;
    // fonctiond'erreurjaco = norme AX - b;
    ErreurJaco += Norme(temporaire);

    printf("\rIn progress : [");
    for (int j = 0; j <= (int)(i * (100.0f / compteur)); j += 2)
    {
      printf("#");
    }
    for (int j = (int)(i * (100.0f / compteur)); j < 100; j += 2)
    {
      printf(".");
    }
    printf("] %d / %d", i, compteur);
    fflush(stdout);
  }

  // calcul des moyenne
  tempsjaco = tempsjaco / compteur;
  tempsgauss = tempsgauss / compteur;

  stabgauss = stabgauss / compteur;
  stabjaco = stabjaco / compteur;

  ErreurGauss = ErreurGauss / compteur;
  ErreurJaco = ErreurJaco / compteur;

  pointeur = pointeur / compteur;
  // fonctiond'erreurgauss et fonctiond'erreurjaco = fonctiond'erreurjaco et
  // fonctiond'erreurgauss / compteur

  printf("\rPour des matrices carré de taille %d, et sur un échantillon de %d, "
         "on obtient que :\n Le temps nécessaire pour gauss est : %f secondes "
         "(%f), avec une stabilité(différence entre le résultat obtenue et le "
         "résultat attendu) de %f, et une fonction d'erreur de %f.\n Le temps "
         "nécessaire pour Jacobi est : %f secondes (%f), avec une marge de "
         "stabilité(différence entre le résultat obtenue et le résultat "
         "attendu) de %f, une fonction d'erreur de %f, et un nombre moyen "
         "d'itération de %d .\n\n",
         larg, compteur, (tempsgauss / 1000000), tempsgauss, stabgauss,
         ErreurGauss, tempsjaco / 1000000, tempsjaco, stabjaco, ErreurJaco,
         pointeur);
  printf("\e[?25h");
}

void rempliUneCase(matrice *A){
  int a = -1;
  int b = -1;
  int chiffrenotok = 1;
  char s[50];
  int curseur;
  
  printf("Entrez le numéro de ligne de la case a modifier (un nombre entier positif) : ");
  while(a < 0){scanf("%d", &a);getchar();}
  printf("Entrez le numéro de colonne de la case a modifier (un nombre entier positif) : ");
  while(b < 0){scanf("%d", &b);getchar();}

  while(chiffrenotok){
    printf("Veuillez entrez la valeur de la case %d %d : ", a, b);
    scanf("%s", s);getchar();
    curseur = 0;
    chiffrenotok = 0;
    while(s[curseur] != '\0'){
      if(s[curseur] == ',' || s[curseur] == '.'){
	s[curseur] = '.';
      }else if(!isdigit(s[curseur])){
	chiffrenotok = 1;
	break;
      }
      curseur++;
    }
  }
  A->Mat[a][b] = atof(s);
}

void casUneCase(matrice *A, matrice *B, matrice *X) {
  char choix;
  int nombre = 0;

  printf("Entrez maintenant le nombre maximum de case à changer souhaiter (un nombre entier positif) : ");
  while(nombre < 1){scanf("%d", &nombre);getchar();}

  printf("Quelle matrice voulez-vous remplir (A, B ou X)? ");
  scanf("%c", &choix);getchar();
  switch (choix) {
  case 'A' : for(int i = 0; i < nombre; i++){rempliUneCase(A);}break;
  case 'B' : for(int i = 0; i < nombre; i++){rempliUneCase(B);}break;
  case 'X' : for(int i = 0; i < nombre; i++){rempliUneCase(X);}break;
  default : printf("Vous ne pouvez pas remplir une matrice qui n'existe pas...\n"); break;
  }
}

matrice *casGauss(matrice *A, matrice *B, matrice *X){
  destroyMatrice(X);

  X = ResolutionParGauss(*A, *B);

  if(X != NULL){
    printf("Le résultat est stocké dans X, et est :\n");
    afficheMatrice(*X);
  }
  else
  {
    printf("Il y a eu une erreur, la matrice X a été réinitialisé.\n");
    X = creerMatrice(1, 1);
  }
  return X;
}

matrice *casJacobi(matrice *A, matrice *B, matrice *X)
{
  int chiffrenotok = 1;
  int curseur;
  char s[50];
  int max = 0;

  while (chiffrenotok)
  {
    printf("Veuillez entrez la valeur de epsilon( soit la marge d’erreur "
           "accepté) : ");
    scanf("%s", s);
    getchar();
    curseur = 0;
    chiffrenotok = 0;
    while (s[curseur] != '\0')
    {
      if (s[curseur] == ',' || s[curseur] == '.')
      {
        s[curseur] = '.';
      }
      else if (!isdigit(s[curseur]))
      {
        chiffrenotok = 1;
        break;
      }
      curseur++;
    }
  }
  
  printf("Entrez maintenant le nombre maximum de répétition souhaité(un nombre entier positif) : ");
  while(max < 1){scanf("%d", &max);getchar();}
	
  
  destroyMatrice(X);
  int a = 0;

  X = Jacobi(A, B, atof(s), max, &a);


  if (X != NULL)
  {
    printf("Le résultat est stocké dans X, et est :\n");
    afficheMatrice(*X);
  }

  /* printf("En cas d'aucune erreur, le résultat est stocké dans X, et est
   * :\n"); */
  /* afficheMatrice(*X); */

  return X;
}

void rempliAuto(matrice *A){
  char choix;
  printf("De quelle manière voulez vous remplir cette matrice ?\n        a : Aléatoirement entre 100 et -100.\n        i : aléatoirement par des entiers entre 100 et -100.\n        z : Aléatoirement avec 70 pourcent de zéros.\n        j : Aléatoirement avec la diagonale dominante.\n        e : Avec une diagonale dominante et 70%% de zéros.\n        b : Avec la méthode de Bord.\n        d : Avec la méthode de DingDong.\n        f : Avec la méthode de Franc.\n        n : Avec la méthode de Hilbert Négative.\n        p : Avec la méthode de Hilbert Positive.\n        k : Avec la méthode de Kms.\n        l : Avec la méthode de Lehmer.\n        o : Avec la méthode de Lotkin.\n        m : Avec la méthode de Moler.\n");
    scanf("%c", &choix);getchar();

    switch(choix){
    case 'a': remplisAlea(A);break;
    case 'i': remplisAleaInt(A); break;
    case 'z': remplisAleaBcpZero(A);break;
    case 'j': remplisAleaDiagonalDominante(A);break;
    case 'e': remplisBeaucoupZeroDiagDomi(A);break;
    case 'b': rempliBord(A);break;
    case 'd': rempliDingDong(A);break;
    case 'f': rempliFranc(A);break;
    case 'n': rempliHilbertNeg(A);break;
    case 'p': rempliHilbertPos(A);break;
    case 'k': rempliKms(A);break;
    case 'l': rempliLehmer(A);break;
    case 'o': rempliLotkin(A);break;
    case 'm': rempliMoler(A);break;
    default:printf("Cette méthode n'existe pas, si aucune ne vous plait, vous pouvez remplir la matrice à la main...\n");break;
    }  
}

void casAutoFill(matrice *A, matrice *B, matrice *X){
  char choix;
  printf("Quelle matrice voulez vous remplir(A, B ou X) ? ");
  scanf("%c", &choix);getchar();
  switch (choix) {
  case 'A' : rempliAuto(A);break;
  case 'B' : rempliAuto(B);break;
  case 'X' : rempliAuto(X);break;
  default:printf("Vous avez choisi une matrice qui n'existe pas...\n");break;
  }
}


void rempliMain(matrice *A){
  char s[40];
  int curseur;
  int chiffrenotok;
  for (int i = 0; i < A->longueur; i++) {
      for (int j = 0; j < A->largeur; j++) {
	chiffrenotok = 1;
	while(chiffrenotok){
	  printf("Veuillez entrez la valeur de la case %d %d : ", i, j);
	  scanf("%s", s);getchar();
	  curseur = 0;
	  chiffrenotok = 0;
	  while(s[curseur] != '\0'){
	    if(s[curseur] == ',' || s[curseur] == '.'){
	      s[curseur] = '.';
	    }else if(!isdigit(s[curseur])){
	      chiffrenotok = 1;
	      break;
	    }
	    curseur++;
	  }
	}
	A->Mat[i][j] = atof(s);
      }
  }

  afficheMatrice(*A);

}

void casRempli(matrice *A, matrice *B, matrice *X){
  char choix;

  printf("Quelle matrice voulez-vous remplir (A, B ou X)? ");
  scanf("%c", &choix);getchar();
  switch (choix) {
  case 'A' : rempliMain(A);break;
  case 'B' : rempliMain(B);break;
  case 'X' : rempliMain(X);break;
  default : printf("Vous ne pouvez pas remplir une matrice qui n'existe pas...\n"); break;
  }
  
}




