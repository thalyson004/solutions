#include <bits/stdc++.h>
using namespace std;
#define int long long

main(){
   int n, m;
   scanf("%lld %lld", &n, &m);

   if(n==1LL or m >= (n*n - n)/2LL ){
      printf("NO\n");
      return 0;
   }

   vector<vector<int>> comp(n+1);
   for(int i = 1; i <= m; i++){
      int a, b;
      scanf("%lld %lld", &a, &b);
      comp[a].push_back(b);
      comp[b].push_back(a);
   }
   for(int i = 1; i <= n; i++)
      sort( comp[i].begin(), comp[i].end() );

   int ok = 0;
   vector<int> A(n+1);
   vector<int> B(n+1);

   for(int i = 1; !ok and i <= n; i++){
      if(comp[i].size()!=(n-1)){
         ok = 1;
         vector<int> quais(n+1);
         for(int x:comp[i]) quais[x]=1;
         int k;
         for(int j = 1; j <= n; j++){
            if(j!=i and !quais[j]){
               k = j;
               break;
            }
         }
         int id = 1;
         for(int j = 1; j <= n; j++){
            if(j!=i and j!=k){
               A[j]=B[j]=id++;
            }
         }
         A[i] = id; A[k] = id+1;
         B[i] = id; B[k] = id;
      }
   }

   if(!ok){
      printf("NO\n");
   }else{
      printf("YES\n");
      for(int i = 1; i <= n; i++) printf("%lld ", A[i]);
      printf("\n");
      for(int i = 1; i <= n; i++) printf("%lld ", B[i]);
      printf("\n");
   }
}
