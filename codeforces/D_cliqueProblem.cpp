#include <bits/stdc++.h>
#define MAXN 1005
#define int long long
using namespace std;

#define pos first
#define vel second

int n, r, avg;
int v[500005];
map<int,int> todo;

main(){
    scanf("%lld %lld %lld", &n, &r, &avg);
    avg = avg*n;

    for(int i = 0; i < n; i++){
        int a, c;
        scanf("%lld %lld", &a, &c);
        todo[c] += r-a;
        avg -= a;
    }
    avg = max(avg, 0LL);
    int ans = 0;
    for(auto it : todo){
        ans += min(avg,it.second)*it.first;
        avg -= min(avg, it.second);
    }
    printf("%lld\n", ans);

}
