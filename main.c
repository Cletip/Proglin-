#include "main.h"
#include "fonction.h"

int main()
{
  srand(time(NULL));
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

  afficheMatrice(*multiplicationMatrice(*e, *x));
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
