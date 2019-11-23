#include <stdio.h>

int main(){
   int N;
   int V[10005];
   int resposta = 0;

   scanf("%d", &N);
   for(int i = 0; i < N; i++){
      scanf("%d", &V[i]);
   }

   for(int i = 2; i < N; i++){
      if( V[i-2]==1 && V[i-1]==0 && V[i]==0 ){
         resposta ++;
      }
   }
   printf("%d\n", resposta);
}
