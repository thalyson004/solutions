#include <bits/stdc++.h>
#define MAXN 1005
#define int long long
using namespace std;

main(){
    double ans = 0.0;
    double v[1005];
    v[0] = 0.0;
    int n;
    double l;

    cin >> n >> l;
    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v, v+n+1);
    ans = max(v[1], l-v[n]);
    for(int i = 2; i<= n; i++) ans = max(ans, (v[i]-v[i-1])/2.0);
    cout.precision( 10 );
    cout.setf(ios::fixed);
    cout << ans << endl;
}
