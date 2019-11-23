#include <stdio.h>
#define int long long
int mdc(int x, int y){
   if( x == 0 ) return y;
   else{
      return mdc(y%x,  x);
   }
}

int mmc(int x, int y){
   return (x/mdc(x,y)) * y;
}

main(){
   int a1, b1, a2, b2;
   int a3, b3;
   scanf("%lld %lld", &a1, &b1);
   scanf("%lld %lld", &a2, &b2);

   b3 = mmc(b1,b2);
   a3 = a1*(b3/b1) + a2*(b3/b2);

   printf("%lld %lld", a3/mdc(a3,b3), b3/mdc(a3,b3));
}
