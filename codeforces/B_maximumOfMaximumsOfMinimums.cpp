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

int v[100005];
int A[100005];
int B[100005];

main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) scanf("%lld", &v[i]);

    if(k == 1){
        int ans = 10000000005LL;
        for(int i = 0; i < n; i++) ans = min(ans, v[i]);
        cout << ans << endl;
    }else if(k > 2){
        int ans = -10000000005LL;
        for(int i = 0; i < n; i++) ans = max(ans, v[i]);
        cout << ans << endl;
    }else{

        A[0] = v[0];
        for(int i = 1; i < n; i++) A[i] = min(A[i-1], v[i]);


        B[n-1] = v[n-1];
        for(int i = n-2; i >= 0; i--) B[i] = min(B[i+1], v[i]);

        int ans = -10000000005LL;
        for(int i = 0; i < n-1; i++) ans = max(ans, max(A[i], B[i+1]) );
        cout << ans << endl;
    }
}

