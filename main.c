#include "main.h"
#include "fonction.h"


int main()
{
  srand(time(NULL));


  matrice *t = creerMatrice(4, 4);
  matrice *e = creerMatrice(4, 8);

  remplisAleaBcpZero(t);
  remplisAleaBcpZero(e);

  afficheMatrice(*t);
  afficheMatrice(*e);


  
  matrice *s = additionMatrice(*t, *e); 

  afficheMatrice(*s);
  

  return 0;
}
