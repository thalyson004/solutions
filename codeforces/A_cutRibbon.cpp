#include <bits/stdc++.h>
using namespace std;

int n, v[3];
int dp[4005];

int main(){

    cin >> n >> v[0] >> v[1] >> v[2];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            if(i-v[j]>= 0 and dp[ i-v[j] ] ){
                dp[ i ] = max(dp[i], dp[ i-v[j] ]+1);
            }
        }
    }
    printf("%d\n", dp[n]-1);
}