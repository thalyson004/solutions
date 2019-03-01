#include <bits/stdc++.h>
using namespace std;


int main(){
   long long ans[40];
   ans[0] = ans[1] = 1;
   for(int i = 2; i < 40; i++) ans[i] = ans[i-1]+ans[i-2];
   int n;
   cin >> n;
   for(int i = n-1; i >= 0; i--) printf("%lld%c", ans[i], " \n"[!i]);
}



