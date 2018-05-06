#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

main(){
    int n, k;
    vector<int> v;
    cin >> n >> k;
    for(int i = 0 ; i < n; i++){
        int x;
        scanf("%lld", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    if(k==0){
        if(v[0] == 1) printf("-1\n");
        else printf("1\n");
    }else if(k==n or v[k]!=v[k-1]) cout << v[k-1] << endl;
    else cout << -1 << endl;
}
