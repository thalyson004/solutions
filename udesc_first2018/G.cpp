#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int tri(int a, int b, int c){
    if( a < c+b and b < a+c and c < a+b ) return 1;
    else return 0;
}

main(){
    vector<int> p;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        p.push_back( x );
    }
    int ans = 0;
    for(int i = 0; i < 5; i++)
    for(int j = i+1; j < 5; j++)
    for(int k = j+1; k < 5; k++)
        ans += tri(p[i], p[j], p[k] );

    cout << ans << endl;
}
