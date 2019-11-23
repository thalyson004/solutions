#include <stdio.h>



int main(){
   int N, K, x;
   int arvore[105]={0};
   int morta = 0, imorta=0;
   long long int frutas = 0;
   long long resposta = 0;
   int atual=0;

   scanf("%d %d", &N, &K);
   for(int i = 0; i < K; i++){
      scanf("%d", &x);
      arvore[x]++;
      frutas += x;
   }

   for(int j = 0; j < N; j++){
      char previsao;
      scanf(" %c", &previsao);

      if( previsao == 'C' ){
         frutas += (K-morta);
         atual--;
      }else{
         frutas -= (K-morta);
         atual++;
      }
      while(imorta <= atual && imorta<100){
         morta += arvore[ imorta ];
         imorta++;
      }
      resposta += frutas;

   }
   printf("%lld\n", resposta);
}
