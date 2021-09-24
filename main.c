#include "main.h"
#include "fonction.h"


int main()
{
  srand(time(NULL));


  matrice *t = creerMatrice(20, 20);
  matrice *e = creerMatrice(4, 8);

 

  
  remplisAleaBcpZero(t);
  remplisAleaBcpZero(e);

   
  
  afficheMatrice(*t);
  afficheMatrice(*e);


  
  matrice *s = Gauss(*t); 

  printf("echelonnage :\n");
  afficheMatrice(*s);
  

  return 0;
}
