#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
//#define int long long

int n;
int dp[105][1005];

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        vector<int> v;
        int total = 0;
        memset(dp, 0, sizeof dp);
        int x;
        for(int i=0;i<n;i++){
            scanf("%d", &x);
            v.push_back(x);
            total+=x;
        }
        for(int i=0;i<n;i++){
            scanf("%d", &x);
            v.push_back(x);
            total+=x;
        }

        dp[0][0] = 1;
        for(int i = 0; i <v.size();i++){
            for(int j=min(i,n-1); j >=0; j--){
                for(int k = total-1; k>=0;k--){
                    if(dp[j][k]){
                        dp[j+1][k+v[i]]=1;
                    }
                }
            }
        }
        int ans = 10000000;
        for(int i=0;i<total;i++){
            if(dp[n][i]){
                ans = min(ans,
                          max(total-i, i)-
                        min(total-i, i) );
            }
        }
        cout << ans << endl;
    }
}
