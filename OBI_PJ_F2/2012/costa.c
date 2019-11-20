#include <stdio.h>

int main(){
   int N, M;
   int resultado = 0;
   char C[1005][1005];

   scanf("%d %d", &N, &M);

   for(int i = 0; i < N; i++){
      scanf("%s", C[i]);
   }

   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         if( C[i][j]=='#'
            && ( (i+1==N || C[i+1][j]=='.')
               ||(i-1==-1 || C[i-1][j]=='.')
               ||(j+1==M || C[i][j+1]=='.')
               ||(j-1==-1 || C[i][j-1]=='.') ) ) {
            resultado ++;
         }
      }
   }
   printf("%d\n", resultado);
}
