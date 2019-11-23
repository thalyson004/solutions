#include <stdio.h>

int main(){
   int L,R,D;
   scanf("%d %d %d", &L, &R, &D);
   
   if( R>50 && L<R && R>D ){
      printf("S\n");
   }else{
      printf("N\n");
   }
}
