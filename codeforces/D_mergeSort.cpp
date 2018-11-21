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
#define oo 1000000000000000LL

int n, m;
int res[100005];

int conta(int a, int b){
    int ans = 1;

    if(a+1 != b){
        ans += conta(a, (a+b)/2);
        ans += conta((a+b)/2, b);
    }

    return ans;
}

int merge(int a, int b){
    if(!m) return 0;
    if(a+1 == b) return 0;

    m -= 2;

    int temp[100005];
    int t = (a+b)/2 - a;
    int mid = (a+b)/2;
    for(int i = 0; i < t; i++) swap( res[a+i], res[a+t+i] );
    merge(a, mid);
    merge(mid, b);
}

main(){

    cin >> n >> m;

    if(m%2 == 0){
        printf("-1\n");
        return 0;
    }
    int maximo = conta(0, n);

    if(m > maximo){
        printf("-1\n");
        return 0;
    }

    for(int i = 0; i < n; i++) res[i] = i+1;

    m--;
    merge(0, n);

    for(int i = 0; i < n; i++) printf("%d%c", res[i], " \n"[i+1==n]);

}