#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000
#define MAXN 1000005
#define all(x) x.begin(),x.end()

int N,M;
int coffe[MAXN];

int possible(int days){
   int total=0;

   for(int i = 1; i <= N;i++){
      total += max(coffe[i]-((i-1)/days), 0);

      if(total>=M)return 1;
   }

   return 0;
}

int solve(){
   for(int i = 1; i <= N; i++){
      scanf("%d", &coffe[i]);
   }
   sort( coffe+1, coffe+N+1 );
   reverse(coffe+1, coffe+N+1);

   int left = 1, right = N;
   while(left < right){
      int middle = (left+right)/2;
      if( possible( middle ) ){
         right = middle;
      }else{
         left = middle+1;
      }
   }
   
   if( possible(left) ){
      return left;
   }
   else return -1;
}

int main(){
   int n;
   while( scanf("%d%d", &N, &M) != -1 ) {
      printf("%d\n", solve());
   }
}


