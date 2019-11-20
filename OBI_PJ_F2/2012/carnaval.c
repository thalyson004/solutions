#include <stdio.h>

int main(){
   float maior, menor, soma;
   float notas[5];

   soma = 0;
   for(int i = 0; i < 5; i++){
      scanf("%f", &notas[i]);
      soma += notas[i];
   }
   maior = menor = notas[0];
   for(int i = 0; i < 5; i++){
      if( maior < notas[i] ){
         maior = notas[i];
      }
      if( menor > notas[i] ){
         menor = notas[i];
      }
   }
   printf("%.1f\n", soma-maior-menor);
}
