#include <stdio.h>

int main(){
   int N;
   int sinuca[65][65];

   scanf("%d", &N);
   for(int i = 0; i < N; i++){
      scanf("%d", &sinuca[1][i]);
   }
   for(int j=2; j <= N; j++){
      for(int i = 0; i <= N-j; i++){
         if(sinuca[j-1][i] == sinuca[j-1][i+1]){
            sinuca[j][i] = 1;
         }else{
            sinuca[j][i] = -1;
         }
      }
   }
   if( sinuca[N][0]==1){
      printf("preta\n");
   }else{
      printf("branca\n");
   }
}
