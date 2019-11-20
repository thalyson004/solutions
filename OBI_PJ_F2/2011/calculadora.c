#include <stdio.h>

int main(){
   int N;
   double resultado=1;
   double x;
   char op;

   scanf("%d", &N);
   for(int i = 0; i < N; i++){
      scanf("%lf %c", &x, &op);
      if( op == '*' ){
         resultado = resultado*x;
      }else{
         resultado = resultado/x;
      }
   }
   printf("%.0f\n", resultado);
}
