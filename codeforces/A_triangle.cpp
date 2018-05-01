#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 1005
#define ii pair<int,int>
#define EPS 0.000000001

//#define int long long

double D(ii a, ii b){
    return sqrt( pow(a.ff-b.ff, 2.0) + pow(a.ss-b.ss, 2.0) );
}

int E(double a, double b){
    return abs(a-b) < EPS;
}

main(){
    int a, b;

    cin >> a>> b;
    vector< pair<int, int> > A, B;

    for(int i = 1; i < b; i++){
        int cur = sqrt(b*b - i*i + 0.5);
        if( cur*cur + i*i != b*b ) continue;
        B.push_back( {cur, i} );
    }
    for(int i = 1; i < a; i++){
        int cur = sqrt(a*a - i*i + 0.5);
        if( cur*cur + i*i != a*a ) continue;
        A.push_back( {-cur, i} );
    }
    double dist = hypot((double)a, (double)b);
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            if( A[i].ss == B[j].ss )continue;
            if( E( D(A[i], B[j] ), dist) ){
                printf("YES\n0 0\n%d %d\n%d %d\n",A[i].first, A[i].second,
                       B[j].first, B[j].second);
                return 0;
            }
        }
    }
    printf("NO\n");
}
