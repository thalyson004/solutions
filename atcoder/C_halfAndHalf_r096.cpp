#include <bits/stdc++.h>
#define MAXN 1005
#define int long long
using namespace std;

main(){
    int a, b, ab;
    int qa, qb;

    cin >> a >> b >> ab;
    cin >> qa >> qb;

    int ans =0;
    while( qa and qb and (2*ab < a+b) ){
        qa--;
        qb--;
        ans += ab*2;
    }
    cout << ans + qa*min(2*ab,a) + qb*min(2*ab,b) << endl;

}
