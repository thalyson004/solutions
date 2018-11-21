#include <bits/stdc++.h>
using namespace std;
#define MAXL 400005
#define MAXA 300
#define ff first
#define ss second

char T[MAXL];
int n;
char P[MAXL];
int S[MAXL], tS[MAXL];
int R[MAXL], tR[MAXL];
int LP[MAXL], id[MAXL];
int fb[MAXL], SF[MAXL];

queue<int> fre[MAXL];

void printS(int k){
    printf("------------------\n");
    printf("id  -  Si -  Ri -  Ra -  LP -  FB \n");
    for(int i = 0; i < n; i++) printf("%3d - %3d - %3d - %3d - %3d - %3d - %s\n",i, S[i], R[ S[i] ], R[ S[i]+k ], LP[i], fb[i], T+S[i]);
    printf("------------------\n");
}

void countSort(int k){

    for(int i = 0; i < n; i++){
        fre[ R[ S[i]+k ] ].push( S[i] );
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        while(fre[j].size() == 0) j++;
        tS[i] = fre[j].front();
        fre[j].pop();
    }
    for(int i = 0; i < n; i++){
        S[i] = tS[i];
    }

}

void buildS(){
    for(int i = 0; i < n; i++){
        S[i] = i;
        R[i] = T[i];
    }

    for(int k = 1; k < n; k*=2){
        countSort(k);
        countSort(0);

        tR[0] = 0;
        for(int i = 1; i < n; i++){
            tR[i] = tR[i-1];
            if( R[ S[i] ] != R[ S[i-1] ] or R[ S[i]+k ] != R[ S[i-1]+k ] ) tR[i]++;
        }
        for(int i = 0; i < n; i++) R[ S[i] ] = tR[i];
        if( tR[n-1] == n-1 ) break;
    }
}


void LCP(){

    for(int i = 0; i < n; i++) id[ S[i] ] = i;
    int j = 0;
    for(int i = 0; i < n; i++){
        int a = id[ i ];
        if(!a)continue;
        int b = S[a-1];


        while( T[ i + j ] == T[ b + j ] ) j++;
        LP[ a ] = j;
        j = max(j-1, 0);
    }
}


main(){
    long long ans = 0;

    scanf("%d %s %s", &n, T, P);
    reverse(T, T+n);
    reverse(P, P+n);
    T[ n ] = '$';
    P[ n ] = '1';
    T[ ++n ] = '\0';

    buildS();
    LCP();

    for(int i = 0; i < n; i++){
        fb[i] = (P[ S[i] ] == '0');
        if(fb[i]) ans = max( ans, 1LL*n-S[i]-1 );
        SF[i] = fb[i] + (i?SF[i-1]:0);
    }

    stack< pair<int,int> > pilha;
    for(int i = 0; i < n; i++){
        while( pilha.size() and pilha.top().first >= LP[i] ){
            int ii = pilha.top().ss;
            int v = pilha.top().ff;
            pilha.pop();
            ans = max(ans, 1LL*v*( 1LL*SF[ii] - 1LL*(pilha.size()?SF[pilha.top().ss-1]:0) ) );
        }
        pilha.push( {LP[i], i} );
    }

    while( pilha.size() ){
        int i = n-1;
        int ii = pilha.top().ss;
        int v = pilha.top().ff;
        pilha.pop();
        ans = max(ans, 1LL*v*( 1LL*SF[i] - 1LL*(pilha.size()?SF[pilha.top().ss-1]:0) ) );
    }

    printf("%lld\n", ans);
}
