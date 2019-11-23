#include <stdio.h>

int main(){
   int N, I, F;
   int V[1005];
   int quantidade = 0;
   scanf("%d %d %d", &N, &I, &F);
   for(int i = 0; i < N; i++){
      scanf("%d", &V[i]);
   }

   for(int i = 0; i < N; i++){
      for(int j = i+1; j < N; j++){
         if( V[i]+V[j] <= F && V[i]+V[j] >= I ){
            quantidade++;
         }
      }
   }
   printf("%d\n", quantidade);
}
