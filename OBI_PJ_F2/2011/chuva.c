#include <stdio.h>

int main(){
   int N;
   int A[105][105];
   int B[105][105];

   scanf("%d", &N);

   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         scanf("%d", &A[i][j]);
      }
   }

   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         scanf("%d", &B[i][j]);
      }
   }

   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         printf("%d ", A[i][j] + B[i][j]);
      }
      printf("\n");
   }
}
