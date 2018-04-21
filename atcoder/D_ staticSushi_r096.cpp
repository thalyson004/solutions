#include <bits/stdc++.h>
#define MAXN 1005
#define int long long
using namespace std;

int n, c;
int v[100005], x[100005];
int ida[100005], volta[100005];


main(){
    cin >> n >> c;

    for(int i = 1 ; i <= n; i++){
        cin >> x[i] >> v[i];
    }

    int sum = 0;
    int best = 0;
    for(int i = 1; i <= n; i++){
        sum += v[i] - (x[i]-x[i-1]);
        best = max(sum, best);
        ida[i] = best;
        //printf("indo _ Melhor ate %lld - %lld\n", i, ida[i]);
    }
    reverse(x+1, x+n+1);
    reverse(v+1, v+n+1);
    sum = 0;
    best = 0;
    x[0] = c;
    for(int i = 1; i <= n; i++){
        sum += v[i] - (x[i-1]-x[i]);
        best = max(sum, best);
        volta[i] = best;
        //printf("voltando _ Melhor ate %lld - %lld\n", i, volta[i]);
    }

    reverse(x+1, x+n+1);
    reverse(v+1, v+n+1);
    x[0] = 0;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max( ans, max(ida[i], max( volta[i], ida[i] + volta[n-i] - min(x[i],c-x[i+1]) )) );
    }
    cout << ans << endl;

}
