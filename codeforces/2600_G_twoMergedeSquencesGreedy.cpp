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
//#define int long long

#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define pb push_back
#define FOR(v, i, l) for(int v = i; v < (int)l; ++v)
#define REP(v, l) FOR(v, 0, l)

#define MAXN 200005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<30)
#define MAX 1000000000LL

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int N;
int v[MAXN];

main(){
    scanf("%d", &N);
    int values[]= {-oo, oo};
    vector<int> ans;
    int ok = 1;
    for(int i = 1; i <= N; i++) scanf("%d", v+i);
    for(int i = 1; i <=N;i++){
      if( v[i]>values[0] and v[i]<values[1] ){
         if(i!=N and v[i]<v[i+1]){
            values[0] = v[i];
            ans.push_back( 0 );
         }else{
            values[1] = v[i];
            ans.push_back( 1 );
         }
      }else if( v[i]>values[0]  ){
         ans.push_back( 0 );
         values[0] = v[i];
      }else if( v[i]<values[1]  ){
         ans.push_back( 1 );
         values[1] = v[i];
      }else{
         ok = 0;
      }
    }
    if(ok){
       printf("YES\n");
       for(int x: ans) printf("%d ", x);
    }else{
      printf("NO\n");
    }
}
