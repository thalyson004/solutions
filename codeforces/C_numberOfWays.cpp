#include <bits/stdc++.h>
using namespace std;
#define MAXL 400005
#define MAXA 300
#define ff first
#define ss second
#define int long long

int n;
int v[500005], presum[500005], possum[500005];
map<int,int > mapa;
int total;

main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    for(int i = 1; i <= n; i++){
        total += v[i];
        presum[i] = presum[i-1] + v[i];
        mapa[ presum[i] ] ++;
    }

    int ans = 0;
    for(int i =1; i< n; i++){
        int s = presum[i];
        mapa[s]--;
        if(total != s*3LL) continue;
        ans += mapa[ s*2LL ];
        if( presum[n]==s*2LL )ans--;
    }
    printf("%lld\n", ans);
}