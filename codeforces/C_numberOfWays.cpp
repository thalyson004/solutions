#include <bits/stdc++.h>
#define MAXN 1005
#define int long long
using namespace std;

#define pos first
#define vel second

int v[500005];
int sum[500005];
map<int,int> todo;

main(){
    int n;
    int s = 0;
    scanf("%lld", &n);
    for(int i = 0; i < n;i++){
        scanf("%lld", &v[i]);
        s += v[i];
        todo[s]++;
    }

    todo[s]--;

    if(s%3){
        printf("0\n");
    }else{
        int ss = 0;
        int ans = 0;
        for(int i = 0; i+2 < n;i++){
            ss += v[i];
            todo[ss]--;
            if(ss*3LL == s)
                ans += todo[ ss*2LL ];
        }
        printf("%lld\n", ans);
    }

}
