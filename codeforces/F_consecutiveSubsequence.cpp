#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int n, maior = 0, id;

int G[MAXN], v[MAXN], q[MAXN];
unordered_map<int,int> mapa;

main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &v[i]);
        q[i] = 1;
        G[i] = i;
        if( mapa[ v[i]-1 ] ){
            G[i] = mapa[ v[i]-1 ];
            q[i] += q[ G[i] ];
        }
        mapa[ v[i] ] = i;
        if(q[i] > maior){
            maior = q[i];
            id = i;
        }
    }
    vector<int> ans;
    while( G[ id ] != id ){
        ans.push_back( id );
        id = G[id];
    }
    ans.push_back( id );
    printf("%u\n", ans.size() );
    reverse(ans.begin(), ans.end());
    for(int i: ans) printf("%lld ", i);

}
