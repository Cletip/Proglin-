#include "main.h"
#include "fonction.h"

int main()
{

  srand(time(NULL));

  matrice *t = creerMatrice(4, 4);
  matrice *e = creerMatrice(4, 8);
  
  afficheMatrice(*e);

  matrice *s = Gauss(*t);

  afficheMatrice(*s);

  matrice *a = creerMatrice(4, 4);
  remplisAleaBcpZero(a);
  /* afficheMatrice(*a); */
  InversematriceD(4, a);
  /* afficheMatrice(*a); */

  return 0;
}
