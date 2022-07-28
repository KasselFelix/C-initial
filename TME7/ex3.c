#include <stdio.h> 
#include<stdlib.h>
#include "mes_fonctions.h" 

int main() {
  cellule_t *n1=malloc(sizeof(cellule_t)),*n2=malloc(sizeof(cellule_t));
  n1->donnee=0;
  n2->donnee=8;
  int k;
  
  k = Sommer(n1, n2);
  printf("%d + %d = %d\n", n1->donnee, n2->donnee, k);
  k = Soustraire(n1, n2);
  printf("%d + %d = %d\n", n1->donnee, n2->donnee, k);
  return 0;
}


// Q1: gcc -Wall -Werror -o ex3 ex3.c mes_fonctions.c  //
// Q2: Le compilateur repond :implicit declaration of function ‘Soustraire’  //
// Pour qu il n y ai pas d erreur lors de la compilation, il faut rajouter    //
//	La fonction Soustraire dans mes_fonctions.h				    //
