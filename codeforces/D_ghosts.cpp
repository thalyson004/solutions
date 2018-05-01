#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

main(){
    int n, a, b;

    cin >> n >> a >> b;

    int ans = 0;
    map< int, int > mapa;
    map< int, map<int,int> > mx;
    map< int, map<int,int> > my;
    map< int, map< pair<int, int>, int > > mxy;

    for(int i = 0; i < n; i++){
        int xi, vxi, vyi;
        cin >> xi >> vxi >> vyi;
        ans += mapa[ vyi - vxi*a ]++;
        ans -= mx[ vyi - vxi*a ][ vxi ]++;
        ans -= my[ vyi - vxi*a ][ vyi ]++;
        ans += mxy[ vyi - vxi*a ][ make_pair(vxi, vyi) ]++;
    }
    cout << ans*2 << endl;

}
