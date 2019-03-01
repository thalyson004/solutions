#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000

int solve( int n ){
   vector< vector<int> > dp(15, vector<int>(5000, oo) );

   dp[0][n] = 0;
   int ans = oo;

   for(int i = 0; i < 14; i++){
      for(int j = 1; j < 5000; j++){
         if( dp[i][j] != oo ){
            if( j==(1<<i)  ) ans = min(ans, dp[i][j]+1);

            dp[i+1][j]=min(dp[i+1][j], dp[i][j]);

            if( j+(1<<i) < 5000 ){
               dp[i+1][j+(1<<i)]=min(dp[i+1][j+(1<<i)], dp[i][j]+1);
            }
            if( j-(1<<i) > 0 ){
               dp[i+1][j-(1<<i)]=min(dp[i+1][j-(1<<i)], dp[i][j]+1);
            }
         }
      }
   }

   return ans;
}

int main(){
   int t, n;
   scanf("%d", &t);

   while(t--){
      scanf("%d", &n);
      printf("%d\n", solve(n));
   }
}



