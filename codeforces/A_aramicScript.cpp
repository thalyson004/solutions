#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define srt(x) sort(x.begin(), x.end())
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

main(){
    int n;
    set< map<char, int> > S;

    cin  >> n;
    for(int i = 0; i < n; i++){
        string c;
        map<char, int> mapa;
        cin >>c;
        for(char k:c) mapa[k] = 1;
        S.insert( mapa );
    }
    cout << S.size() << endl;


}
