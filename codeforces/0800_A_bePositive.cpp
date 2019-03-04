#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000
#define MAXN 2005
#define MOD 1000000007LL
#define all(x) x.begin(),x.end()

int N,  M;

int solve(){
   int positive = 0;
   int negative = 0;
   for(int i = 0; i < N;i++) {
      int a;
      scanf("%d", &a);
      positive += (a>0);
      negative += (a<0);
   }
   if( positive*2>=N ) return 1;
   if( negative*2>=N ) return -1;
   else return 0;
}

int main(){

   while( scanf("%d", &N) != -1 ) {
      printf("%d\n", solve() );

   }
}
