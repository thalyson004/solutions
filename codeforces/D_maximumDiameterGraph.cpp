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
//#define int long long
#define MAXN 100005
#define MAXM 305
#define MAXB 20
#define oo 10000000001000000000LL



main(){
   int n;
   cin >> n;
   vector< int > um, mais;
   vector< vector<int> > G(n+1);
   vector<int> D(n+1);

   for(int i = 1; i <= n; i++){
      cin >> D[i];
      if(D[i]==1) um.push_back( i );
      else mais.push_back( i );
   }
   if( um.size()>=2 and mais.size()==0 ){
      printf("NO\n");
      return 0;
   }
   vector<int> chain;
   if(um.size()){ chain.push_back( um.back() ), um.pop_back(); }
   else { chain.push_back( mais.back() ), mais.pop_back(); }
   while( mais.size() ){
      int x = chain.back();
      D[ x ]--;
      chain.push_back( mais.back() );
      mais.pop_back();
      int y = chain.back();
      D[ y ]--;
      G[x].push_back( y );
   }
   if(um.size()){
      int x = chain.back();
      D[ x ]--;
      chain.push_back( um.back() );
      um.pop_back();
      int y = chain.back();
      D[ y ]--;
      G[x].push_back( y );
   }
   int ans = chain.size() - 1;
   int ok = 1;
   while(ok and um.size()){
      int put=0;
      for(int x : chain){
         if( D[x] ){
            G[x].push_back( um.back() );
            um.pop_back();
            put = 1;
            D[x]--;
            break;
         }
      }
      if(!put){
         printf("NO\n");
         return 0;
      }
   }
   printf("YES %d\n%d\n", ans, n-1);
   for(int i = 1; i <=n; i++){
      for(int u:G[i]){
         printf("%d %d\n", i, u);
      }
   }


}


