#include <stdio.h>

int main(){
   int N;
   int M[1005][1005];
   int linha[1005]={0};
   int coluna[1005]={0};
   int resposta = 0;

   scanf("%d", &N);
   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
         scanf("%d", &M[i][j]);
         linha[i]+=M[i][j];
         coluna[j]+=M[i][j];
      }
   }
   for(int i = 1; i <= N; i++)
      for(int j = 1; j <= N; j++){
         int soma = linha[i]+coluna[j]-M[i][j]*2;
         if( soma > resposta){
            resposta = soma;
         }
      }
   printf("%d\n", resposta);


}
