#include <bits/stdc++.h>
#define MAXN 1005
//#define int long long
using namespace std;

int dp[100005], ans;

main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int sq = sqrt(0.5+x);
        vector<int> quais;
        int maior = 0;
        for(int j = 2; j <= sq and j <= x; j++){
            if( x%j == 0){
                maior = max(maior, dp[ j ]+1);
                quais.push_back( j );
                while(x%j == 0) x/=j;
            }
        }
        if( x>1 or quais.size()==0 ){
            maior = max(maior, dp[ x ]+1);
            quais.push_back( x );
        }
        for(int j : quais) dp[j] = maior;
        ans = max(ans, maior);
    }
    cout << ans << endl;
}

/*
5
2 3 4 6 9
*/
