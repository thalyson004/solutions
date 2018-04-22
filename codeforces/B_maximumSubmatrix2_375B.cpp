#include <bits/stdc++.h>
#define MAXN 1005
//#define int long long
using namespace std;

int n, m;
char g[5005][5005];
int frente[5005][5005];

main(){

    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++) scanf("%s", g[i]);
    for(int i = 0; i < n; i++){
        for(int j = m-1; j >=0; j--){
            frente[i][j] = ( g[i][j]=='1'?frente[i][j+1]+1:0 );
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        vector<int> linha;
        for(int j = 0; j <n; j++) linha.push_back( frente[j][i] );
        sort( linha.begin(), linha.end() );
        for(int j = 0; j < n; j++) ans = max(ans, linha[j]*(n-j) );
    }
    printf("%d\n", ans);
}
