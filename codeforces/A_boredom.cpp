#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int n;
int dp[MAXN];
int f[MAXN];

int solve(int x){
    if(x<=0) return 0;
    if(dp[x]>=0) return dp[x];

    dp[x] = solve(x-1);
    dp[x] = max(dp[x], solve(x-2) + f[x]*x );

    return dp[x];
}

main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        f[a]++;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(100000) << endl;
}
