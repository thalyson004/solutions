#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector< ii >
#define vi vector< int >
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define EPS 0.000000001
#define pb push_back
#define int long long
#define MAXN 100005
#define MAXM 305
#define MAXB 20
#define oo 10000000001000000000LL

main(){
   int n;
   scanf("%lld", &n);
   vector<int> r(n), l(n);
   for(int i=0;i<n;i++)scanf("%lld%lld", &r[i], &l[i]);
   sort(all(r));
   sort(all(l));
   int ans=n;
   for(int i=0;i<n;i++) ans+=max(r[i],l[i]);
   printf("%lld\n", ans);
}
