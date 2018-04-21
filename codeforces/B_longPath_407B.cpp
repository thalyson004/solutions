#include <bits/stdc++.h>
#define MAXN 1005
#define mod 1000000007
//#define int long long
using namespace std;

int n;
int v[10005];
int dp[10005];
long long ans = 0;

main(){
    cin >> n;
    for(int i= 1; i <= n;i++){
        cin >> v[i];
        int q = 1;
        for(int j = v[i]; j<i; j++) q = (q+dp[j]+1)%mod;
        dp[i] = q;
        ans = (ans+dp[i])%mod;
    }
    cout << (ans+n)%mod << endl;
}

/*
5
2 3 4 6 9
*/
