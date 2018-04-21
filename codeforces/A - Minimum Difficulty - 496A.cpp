#include <bits/stdc++.h>
using namespace std;

//tipos
//#define int long long
#define ll long long
#define ull unsigned long long
#define ii pair< int , int>
#define vi vector<int>
#define vii vector< pair<int,int> >

//comandos
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define ff first
#define ss second


//constantes
#define MOD 1000000007
#define MAX 1000005
#define MAXN 300005
#define oo 1000000005LL

main(){

    int m = 0;
    int v[1005];

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    m = v[1]-v[0];
    for(int i = 2; i < n; i++){
        m = max(m, v[i]-v[i-1]);
    }
    int ans = max(m, v[2]-v[0]) ;
    for(int i = 2; i < n; i++){
        ans = min(ans, max(m, v[i]-v[i-2]));
    }
    cout << ans << endl;
}
