#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int v[MAXN];
int soma[MAXN];

main(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        scanf("%lld", &v[i]);
        soma[i] = soma[i-1] + v[i];
    }

    int j = 1;
    int total = 0;
    for(int i = 0; i < q; i++){
        int cur;
        scanf("%lld", &cur);
        total += cur;
        int k = lower_bound(soma, soma+n+1, total) - soma;
        if(total >= soma[n]){
            printf("%lld\n", n);
            total = 0;
        }else {
            printf("%lld\n", n-k+1 - (soma[k] == total) );
        }

    }

}
