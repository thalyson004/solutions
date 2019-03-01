#include <stdio.h>

int main(){
   /*
   int N, i;
   int fatorial=1;

   scanf("%d", &N);
   for(i =1; i <= N; i++){
      fatorial = fatorial*i;
   }
   printf("%d\n", fatorial);
   */
   int a,b,c;
   scanf("%d%d%d", &a,&b,&c);
   int va = 2*b + 4*c;
   int vb = 2*a + 2*c;
   int vc = 2*b + 4*a;
   int ans = va;
   if( ans > vb ) ans = vb;
   if( ans > vc ) ans = vc;
   printf("%d\n", ans);
}
