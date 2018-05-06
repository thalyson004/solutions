#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 405
#define oo 1000000005
#define ii pair<int,int>
#define vii vector< ii >
#define EPS 0.000000001
int vl[4] = {1, 0, 0, -1};
int vc[4] = {0, 1, -1, 0};
//#define int long long

int n, m;
char G[MAXN][MAXN];
int cor[MAXN][MAXN];

int limite(int a, int b){
    return a<n and b <m and a>=0 and b>=0 and G[a][b]=='C' and cor[a][b]==0;
}

int dfs(int a, int b){
    int ans = 1;
    cor[a][b] = 1;
    for(int i = 0; i < 4; i++){
        int aa = a+vl[i];
        int bb = b+vc[i];
        if(limite(aa,bb))
            ans+= dfs(aa,bb);
    }
    return ans;
}

main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf(" %c", &G[i][j]);

    int ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if( limite(i,j) )
            ans = max(ans, dfs(i,j));

    printf("%d\n", ans);
}


/*
5 5
C C C C P
P C P R C
C R P R C
C C R C C
R P C P R
*/
