#include "main.h"
#include "fonction.h"

int main()
{
  srand(time(NULL));
  int estAdiagdomine = 0;
  int taille = 5;

  matrice *t = creerMatrice(5, 5);
  matrice *e = creerMatrice(taille, taille);
  matrice *f = creerMatrice(1, 5);

  remplisAlea(t);
  while(!estAdiagdomine){
    remplisAleaBcpZero(e);
    estAdiagdomine = 1;
    for(int i = 0; i < taille; i++){
      int verifieur = 0;
      for(int j = 0; j < taille; j++){
	if(j != i){
	  verifieur += fabsl(e->Mat[i][j]);
	}
      }
      if(verifieur > e->Mat[i][i]){
	estAdiagdomine = 0;
	break;
      }
    }
  }

  
  remplisAlea(f);
  
  afficheMatrice(*t);

  matrice *s = Gauss(*t);

  afficheMatrice(*s);

  matrice *a = creerMatrice(4, 4);
  remplisAleaBcpZero(a);
  /* afficheMatrice(*a); */
  InversematriceD(4, a);
  /* afficheMatrice(*a); */

  
  Jacobi(e, f);
  

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
  

  

  return 0;
}
