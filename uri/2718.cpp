#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 405
#define oo 1000000005
#define ii pair<int,int>
#define vii vector< ii >
#define EPS 0.000000001
int vl[4] = {1, 0, 0, -1};
int vc[4] = {0, 1, -1, 0};
#define int long long


main(){
    int n, m;
    cin >>m;
    while(m--){
        cin >> n;
        int atual = 0, ans = 0;
        while(n){
            if(n%2) atual++;
            else atual = 0;
            ans = max(ans, atual);
            n /= 2;
        }
        printf("%lld\n", ans);
    }
}

