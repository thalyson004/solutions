#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair<int,int>
#define iii pair<ii, int>
#define iiii pair<ii, ii>
#define viiii vector< iiii >
#define viii vector< iii >
#define vii vector< ii >
#define vi vector< int >
#define int long long

#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define pb push_back
#define FOR(v, i, l) for(int v = i; v < (int)l; ++v)
#define REP(v, l) FOR(v, 0, l)

#define MAXN 100005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)
#define OO (1LL<<60)

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int n, k;
int a, b;

main(){
   scanf("%lld %lld", &n, &k);
   scanf("%lld %lld", &a, &b);
   int d1 = a;
   int d2 = k - a;

   int maior = 1;
   int menor = k*n;

   int o[5];
   o[0] = k - a - b;
   o[1] = k - a + b;
   o[2] = k - a + k - b;
   o[3] = a + b;
   o[4] = k + a - b;

   for(int j = 0; j < 5; j++)
      if(!o[j])
         o[j]+=k;

   for(int i = 0; i <= n; i++){
      for(int j = 0; j < 5; j++){
         int d = o[j]+i*k;
         int stop = (n*k)/__gcd(n*k,d);
         maior = max(maior, stop);
         menor = min(menor, stop);
      }
   }

   printf("%lld %lld\n", menor, maior);
}
