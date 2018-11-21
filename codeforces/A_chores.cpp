#include <bits/stdc++.h>
using namespace std;

//tipos
#define int long long
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
#define MAX 31625
#define oo 1000000005LL

int n, m, k, q, t, x;
//int v[10000005];

main(){

    cin >> n >> k >> x;

    int ans = 0;
    for(int i = 0; i < n-k; i++){
        int t;
        cin >> t;
        ans += t;
    }

    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        ans += min(x, t);

    }
     cout << ans << endl;
}

