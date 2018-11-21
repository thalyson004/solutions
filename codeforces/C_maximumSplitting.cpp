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
#define oo 100000000000005LL

main(){


    int q;
    scanf("%lld", &q);

    while(q--){
        int n;
        scanf("%lld", &n);

        if(n<4){
            printf("-1\n");
        }else if( n%4 == 0 ){
            printf("%lld\n", n/4);
        }else if( n%4 == 2 ){
            n-=6;
            printf("%lld\n", 1 + n/4);
        }else if( n%4 == 1 ){
            if(n < 9){
                printf("-1\n");
            }else{
                n-=9;
                printf("%lld\n", 1 + n/4);
            }
        }else if( n%4 == 3 ){
            if(n < 15){
                printf("-1\n");
            }else{
                n-=15;
                printf("%lld\n", 2 + n/4);
            }
        }
    }
}