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
#define MAX 31625
#define oo 1000000005LL

int n;
char en[100005];
map<int, int> mapa;

main(){
    cin >> n;
    cin >> en+1;
    int dif = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(en[i]=='1')dif += 1;
        else dif -= 1;

        if(dif == 0) ans = i;
        else if( mapa[dif] ){
            ans = max(ans, i - mapa[ dif ] );
        }else {
            mapa[ dif ] = i;
        }
    }
    cout << ans << endl;
}

