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

int main(){
    int n;
    int v[5005], w[5005];
    int a[5005], b[5005];
    int p[5005];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("? %d %d\n", 0, i);
        fflush(stdout);
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < n; i++){
        printf("? %d %d\n", i, 0);
        fflush(stdout);
        scanf("%d", &w[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++) b[j] = v[j]^i;
        for(int j = 0; j < n; j++) a[j] = w[j]^b[0];

        int f = 1;
        for(int j = 0; j < n; j++) if( a[ b[j] ] != j ) f = 0;
        ans += f;

        if(f) for(int j = 0; j < n; j++) p[j] = a[j];
    }

    printf("!\n");
    fflush(stdout);

    printf("%d\n", ans);
    for(int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
}