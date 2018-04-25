#include <bits/stdc++.h>
#define MAXN 30005
//#define int long long
using namespace std;

#define pos first
#define vel second

int vet[MAXN];
int dp[MAXN][500];

int a, b, c, d;
int n, m;

main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        vet[a]++;
    }

    dp[m][250] = vet[0]+vet[m] + 1;
    int ans = dp[m][250];
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < 500; ++j){
            int passo = m + (250-j);
            int valor = dp[i][j];
            if(dp[i][j]){
                if(passo>1 and i+passo-1 < MAXN ){
                    dp[ i+passo-1 ][ j+1 ] = max(dp[ i+passo-1 ][ j+1 ],
                                                 valor+vet[ i+passo-1 ]);
                    ans = max(ans, dp[ i+passo-1 ][ j+1 ]);
                }
                if(passo > 0 and i+passo < MAXN) {
                    dp[ i+passo ][ j ] = max(dp[ i+passo ][ j ],
                                                 valor+vet[ i+passo ]);
                    ans = max(ans, dp[ i+passo ][ j ]);
                }

                if(passo+1>0 and i+passo+1 < MAXN) {
                    dp[ i+passo+1 ][ j-1 ] = max(dp[ i+passo+1 ][ j-1 ],
                                                 valor+vet[ i+passo+1 ]);
                    ans = max(ans, dp[ i+passo+1 ][ j-1 ]);
                }
            }
        }
    }
    printf("%d\n", ans-1);
}

/*
4 10
10
21
27
27

8 8
9
19
28
36
45
55
66
78
*/
