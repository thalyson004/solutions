#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int n;
vector<int> G[105], ans;
int v[105];
int cor[105];

int dfs(int x){
    if(cor[x]) return 0;
    cor[x] = 1;
    for(int u:G[x]) dfs(u);
    ans.push_back( v[x] );
}

main(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> v[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if( !(i==j) and (v[i]*2==v[j] or (!(v[i]%3) and v[i]/3 == v[j]) ) ){
                G[i].push_back(j);
               // printf("%lld %lld\n", v[i], v[j]);
            }

    for(int i = 0; i < n; i++) if(!cor[i]) dfs(i);

    reverse(ans.begin(), ans.end());

    for(int i: ans) printf("%lld ", i);
}
