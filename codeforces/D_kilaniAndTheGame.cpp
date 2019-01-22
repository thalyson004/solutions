#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000
#define MAXN 1005

int dis[MAXN][MAXN];
char G[MAXN][MAXN];

int p, n, m;
int dl[] = {0,0,1,-1};
int dr[] = {1,-1,0,0};
int ans[10];
queue< pair<int,int> > q[10];
int s[10];

int limit(int pl, int pr, int nl, int nr){
   return nl>=1 and nr>=1 and nl<=n and nr<=m and G[nl][nr]=='.';
}

int main(){
   scanf("%d %d %d", &n, &m, &p);
   for(int i = 1; i <= p;i++) scanf("%d", &s[i]);

   for(int i = 1; i <= n; i++){
      scanf("%s", &G[i][1]);
      for(int j = 1; j <= m; j++){
            if(isdigit(G[i][j]) ){
               q[ G[i][j] - '0' ] .push( {i,j} );
               ans[ G[i][j] - '0' ] ++;
            }
      }
   }

   int flag = 1, round=1;
   while(flag){
      flag = 0;

      for(int i = 1; i<=p;i++){
         while( q[i].size() ){
            int l = q[i].front().first;
            int r = q[i].front().second;
            if( dis[l][r]==round*s[i] ) break;
            q[i].pop();


            for(int j = 0; j < 4; j++){
               int ll = l+dl[j];
               int rr = r+dr[j];
               if( limit(l,r,ll,rr) ){
                  dis[ll][rr] = dis[l][r]+1;
                  G[ll][rr] = G[l][r];
                  q[i].push( {ll,rr} );
                  ans[i]++;
                  flag = 1;
               }
            }
         }
      }
      round++;
   }
   for(int i = 1; i <= p; i++) printf("%d ", ans[i]);
}
