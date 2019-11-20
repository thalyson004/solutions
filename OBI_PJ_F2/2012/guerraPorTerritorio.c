#include <stdio.h>

int main(){
   int N, soma, metade, resposta;
   int v[100005];

   scanf("%d", &N);
   soma = 0;
   for(int i = 1; i <= N; i++){
      scanf("%d", &v[i]);
      soma += v[i];
   }
   metade = 0;
   for(int i = 1; i <= N; i++){
      metade +=v[i];
      if( metade*2 == soma ){
         resposta = i;
      }
   }
   printf("%d\n", resposta);
}
