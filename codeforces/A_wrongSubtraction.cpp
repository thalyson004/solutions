#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

main(){
    int a, b;
    cin >> a >> b;
    while(b--){
        if(a%10) a--;
        else a /= 10;
    }
    cout << a << endl;
}
