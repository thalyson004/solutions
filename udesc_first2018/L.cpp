#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 1000005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long


unordered_map<string, int > mapa;

main(){
    int b1, b2, s;

    string cpf, a, b;
    int i, j;
    int xxx;
    cin >> xxx;
    while(xxx--){
        cin >> a >> b ;
        cpf = a.substr(0, 3) + "." + a.substr(3, 3) + "." + a.substr(6, 3)
         + "-" + b;
        if(cpf.size() != 14) goto vai;
        b1 = 0;
        b2 = 0;
        j = 10;
        for(i = 0; i < a.size() ; i++){
            b1 += (a[i]-'0')*(j);
            j--;
        }
        b1 %= 11;
        if(b1<2) b1 = 0;
        else b1 = 11-b1;

        b2 = 2*b1;
        j = 11;
        for(i = 0; i < a.size() ; i++){
            b2 += (a[i]-'0')*(j);
            j--;
        }
        b2 %= 11;
        if(b2<2) b2 = 0;
        else b2 = 11-b2;

        //printf(">> %d %d\n", b1, b2);
        if( (b1 == (cpf[12]-'0')) && (b2 == (cpf[13]-'0')) ){
            if( mapa [cpf] ){
                printf("Clonado\n");
            }else{
                printf("Sucesso\n");
                mapa[cpf] = 1;
            }
        }else{
            vai:
            printf("Invalido\n");
        }
    }
    return 0;
}


/*
4
111444777 35
948102232 10
948102232 30
111444777 35

*/
