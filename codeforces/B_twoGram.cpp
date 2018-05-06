#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

main(){
    int n, q;
    string s, ans;
    q = 0;
    cin >> n >> s;
    for(int i = 1; i < n; i++){
        string t = s.substr(i-1, 2);
        int v = 0;
        for(int j = 1; j < n; j++){
            v += (t==s.substr(j-1, 2));
        }
        if(v>q){
            q = v;
            ans = t;
        }
    }
    cout << ans << endl;
}
