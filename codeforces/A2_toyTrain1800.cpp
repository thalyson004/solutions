#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000
#define all(x) x.begin(),x.end()

int calc(int a, int b, int n){
   if(a<=b) return b-a;
   else return n-(a-b);
}

int solve( int n, int m ){
   vector< vector< int > > distance(n+1);


   for(int i=0; i < m; i++ ){
      int a, b;
      scanf("%d%d", &a, &b);
      distance[a].push_back( calc(a,b,n) );
   }

   vector<int> time(n+1);
   for(int i = 1; i<= n; i++){
      sort( all(distance[i]) );
      if( distance[i].size() )
         time[i] = n*(-1+distance[i].size()) + distance[i][0];
   }

   vector<int> ans;
   for(int i = 1; i <=n; i++){
      int total = 0;
      int k = i;
      for(int j = 0; j < n; j++){
         if( time[ k ] ) total = max(total, time[k]+j);
         k++;
         if(k>n)k=1;
      }
      printf("%d ", total);
   }
   printf("\n");
}

int main(){
   int n, m;

   while( scanf("%d%d", &n, &m) != -1 ) {
      solve(n, m);
   }
}
