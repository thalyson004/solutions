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

main(){
    int n, m;
    cin >> n >>m;
    int A[10], B[10];
    int ans = 1000;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i] == B[j]) ans = min(ans, A[i]);
            ans = min(ans, A[i] + 10*B[j]);
            ans = min(ans, 10*A[i] + B[j]);
        }
    }
    cout << ans << endl;
}
