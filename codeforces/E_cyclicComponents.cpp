#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int n, m;
vector<int> G[MAXN], path;
int cor[MAXN];

int dfs(int x){
    int ans = (G[x].size()==2);
    cor[x] = 1;

    for(int u:G[x]) {
        if(!cor[u])
            ans = (dfs(u) && ans);
    }

    return ans;
}

main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(!cor[i]){
            ans += dfs(i);
        }
    }

    cout << ans << endl;
}
