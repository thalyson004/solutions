#include <stdio.h>

int main(){
   int V, N, x;

   scanf("%d %d", &V, &N);
   for(int i = 0; i < N; i++){
      scanf("%d", &x);
      V += x;
      if( V > 100 ){
         V = 100;
      }
      if( V < 0 ){
         V = 0;
      }
   }
   printf("%d\n", V);
}
