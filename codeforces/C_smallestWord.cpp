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

main(){
   string s;
   cin >> s;
   if(sz(s)>= 2){
      for(int i = 0; i < sz(s); i++){
         if( s[i]=='b' and s[i+1]=='a' ){
            printf("1 ");
            i++;
            while(i+1 < sz(s) and s[i+1]=='a'){
               printf("0 ");
               i++;
            }
            printf("1 ");
         }else{
            printf("0 ");
         }
      }
      printf("\n");
   }else{
      printf("0\n");
   }
}
