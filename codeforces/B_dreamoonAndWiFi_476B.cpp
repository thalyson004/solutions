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
    string a, b;

    cin >> a >> b;
    int suma = 0, sumb=0, what=0;
    for(char c: a) suma += (c=='+'?1:-1);
    for(char c: b){
        sumb += (c=='+'?1:(c=='-'?-1:0));
        what += (c=='?');
    }
    if(what){
        int dif = (suma-sumb);
        dif = max(dif, -dif);
        if(dif > what or (dif-what)%2  ){
            printf("0.000000000000\n");
        }else{
            double total = ((double) ( 1 << what )), ans = 0.0;
            for(int i = 0; i < (1 << what); i++){
                int valor = 0, j = i;
                for(int k = 0; k < what; k++){
                    valor += (j%2?1:-1);
                    j = j/2;
                }
                if( valor+sumb == suma ){
                    ans += (1.0/total);
                }
            }
            printf("%.12f\n", ans);
        }
    }else{
        printf("%d.000000000000\n", suma==sumb);
    }
}
