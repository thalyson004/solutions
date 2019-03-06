#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000LL
#define MAXN 100005
#define MOD 1000000007LL
#define all(x) x.begin(),x.end()
#define int long long

int X,  Y, N;
int A,  B;
char weather[MAXN];
pair<int,int> sum[MAXN];

pair<int,int> wind(pair<int,int> p, char c){
   if(c=='U')p.second++;
   if(c=='D')p.second--;
   if(c=='L')p.first--;
   if(c=='R')p.first++;

   return p;
}

bool possible(int day){
   int x=X, y=Y;
   x += sum[N].first*(day/N);
   x += sum[day%N].first;

   y += sum[N].second*(day/N);
   y += sum[day%N].second;

   return day>= llabs(x-A)+llabs(y-B);
}

int solve(){
   scanf("%lld%lld%lld", &A, &B, &N);
   scanf("%s", weather+1);

   for(int i = 1; i <= N; i++){
      sum[i] = wind(sum[i-1], weather[i]);
   }

   int l = 1, r=oo*oo;
   while(l<r){
      int m = (l+r)/2;

      if( possible(m) ){
         r=m;
      }else{
         l=m+1;
      }
   }
   if(possible(l))return l;
   else return -1LL;
}

main(){

   while( scanf("%lld%lld", &X, &Y) != -1 ) {
      printf("%lld\n", solve() );

   }
}
