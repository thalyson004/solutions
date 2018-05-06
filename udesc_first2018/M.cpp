#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int casos;
int n, k;

main(){
  int a, ans = 1;
  while ( cin >> a and a!=-1){
    ans = 0;
    while(a <= 10){
        if(a == 10){
        ans += 2;
        a = 11;
        }else if( a == 9 or a == 8){
        ans += 4;
        a = 10;
        }else if( a == 7){
            ans += 6;
            a = 9;
        }else if( a == 6 or a == 5){
            ans += 8;
            a = 7;
        }else if( a == 4){
            ans += 10;
            a = 5;
        }else if( a == 3 or a == 2){
            ans += 12;
            a = 4;
        }else {
            ans += 14;
            a = 2;
        }
    }
    cout << ans << endl;
  }
}
