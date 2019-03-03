#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000
#define MAXN 2005
#define MOD 1000000007LL
#define all(x) x.begin(),x.end()

long long N,M;

void mult(long long **a, long long **b ){
   vector< vector<long long> > temp(M, vector<long long> (M, 0));

   for(int i = 0; i <M; i++)
   for(int j = 0; j <M; j++)
      for(int k = 0; k <M; k++)
         temp[i][j] = (temp[i][j] + a[i][k]*b[k][j])%MOD;

   for(int i = 0; i <M; i++)
   for(int j = 0; j <M; j++)
      a[i][j] = temp[i][j];
}

long long fib(long long x){
   long long **m = (long long**)malloc(sizeof(long long*)*M);
   long long **ans = (long long**)malloc(sizeof(long long*)*M);

   for(int i = 0; i < M; i++){
      m[i]= (long long*)calloc(M, sizeof(long long));
      ans[i]= (long long*)calloc(M, sizeof(long long));

      ans[i][i] = 1LL;
   }
   for(int i = 0; i < M-1; i++) m[i+1][i] = 1;
   m[0][M-1]=m[M-1][M-1] = 1LL;

   while(x){
      if(x&1) mult(ans, m);
      x /= 2;
      mult(m,m);
   }
   long long resp = 0;
   for(int i = 0; i < M; i++)
      resp = (resp+ans[i][M-1])%MOD;
   free(m);
   free(ans);

   return resp;
}

long long solve(){
   if(N<M) return 1;
   else return fib( N-M+1 );
}

int main(){

   while( scanf("%lld%lld", &N, &M) != -1 ) {
      printf("%lld\n", solve() );

   }
}
