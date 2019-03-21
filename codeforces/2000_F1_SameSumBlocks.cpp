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

#define MAXN 300005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<60)
#define MAX 1000000000LL

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int N;
int v[100005];
int presum[100005];

int firstSum(int i, int s, int a){
   while(i>a){
      s-=v[i];
      if(!s)return i;
      i--;
   }

   return -1;
}

void printAns(int c, int s){
   printf("%lld\n", c);
   int ant = 0;
   for(int w=1;w<=N;w++){
      int id = firstSum(w, s, ant);
      if(id!=-1){
         printf("%lld %lld\n", id, w);
         ant=w;
      }
   }
}

int solve(){

      fill(presum, presum+1+N, 0);
      for(int i = 1; i <= N; i++) presum[i] = presum[i-1]+v[i];
      int count = 0;
      int sum = 0;

      for(int i = 1; i <=N;i++)
      for(int j = i; j <=N;j++){
         int csum = presum[j]-presum[i-1];
         int ccount = 0;

         int ant=0;
         for(int w=1;w<=N;w++){
            int id = firstSum(w, csum, ant);
            if(id!=-1){
               ccount++;
               ant=w;
            }
         }
         if(ccount > count){
            count=ccount;
            sum = csum;
         }
      }
      printAns(count, sum);
}

main(){
   while( scanf("%lld", &N) != -1 ){
      for(int i = 1; i <= N; i++) scanf("%lld", v+i);
      solve();
   }
}
