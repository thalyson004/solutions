#include <bits/stdc++.h>
using namespace std;

#define int long long

main(){
    int n, ans = 0, sx = 0, sy = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%lld %lld", &x, &y);

        ans += (x*x)*(n-1LL);
        ans += (y*y)*(n-1LL);
        ans -= sx*x*2LL;
        ans -= sy*y*2LL;
        sx += x;
        sy += y;
    }

    printf("%lld\n", ans);
}