#include <bits/stdc++.h>
using namespace std;

//tipos
//#define int long long
#define ll long long
#define ull unsigned long long
#define ii pair< int , int>
#define vi vector<int>
#define vii vector< pair<int,int> >

//comandos
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define ff first
#define ss second


//constantes
#define MOD 1000000007
#define MAX 31625
#define oo 100000000000005LL

int n, m, k;
int M[105][105];

main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> M[i][j];

    int a = 0, b = 0;
    for(int j = 1; j <= m; j++){

        int maior = 0;
        int an = 0;
        int um = 0;
        for(int i = 1; i <= n; i++){
            int col = 0;
            if(M[i][j] == 1){
                for(int w = 0; w < k and w+i <= n; w++){
                    col += M[i+w][j];
                }
                if(col > maior){
                    maior = col;
                    an = um;
                }
                um++;
            }
        }
        a += maior;
        b += an;
    }
    printf("%d %d\n", a, b);
}

