#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define srt(x) sort(x.begin(), x.end())
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int n;
int v[MAXN];
int dd[MAXN];
int inc[MAXN];

main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        inc[i] = 1;
        if(i>1 and v[i]>v[i-1]) inc[i] = inc[i-1]+1;

    }

    int ans =0;
    for(int i = n; i>=1; i--){
        dd[i] = 1;
        if(v[i]<v[i+1])dd[i] = dd[i+1]+1;

        ans = max(ans, max(inc[i-1], dd[i+1])+1);
        if(i>1 and i <n and v[i-1]+1 < v[i+1]){
            ans = max(ans, dd[i+1]+inc[i-1]+1);
        }
    }
    cout << ans << endl;




}
