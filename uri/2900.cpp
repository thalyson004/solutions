#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000

int solve( int n ){
   int metade = 0;
   int completos = 0;

   int len, number;
   for(int i = 0; i < n; i++){
      scanf("%d%d", &len, &number);
      completos += number/4;
      number %=4;
      metade += number/2;
   }
   return completos + metade/2;
}

int main(){
   int n;

   while( scanf("%d", &n) and n ) {
      printf( "%d\n", solve(n) );
   }
   printf("\n");
}



