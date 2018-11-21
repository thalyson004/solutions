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

#define MAXN 100005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<60)

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int n, m;

int check(string s){
   int d=0,l=0,u=0;
   for(char c : s){
      d = d or ( isupper(c) );
      l = l or ( islower(c) );
      u = u or ( isdigit(c) );
   }

   return (d and l and u);
}

int qual(char c){
   if( isupper(c) ) return 1;
   if( islower(c) )return 2;
   if( isdigit(c) ) return 3;
}

int dif(string a, string b){
   int d= 0;
   for(int i = 0; i < sz(a); i++){
      if( qual(a[i]) != qual(b[i]) )d++;
   }
   return d;
}

string q[] = {"aA","a1","1A","1a", "Aa", "A1"};

string w[] = {"a","1","A"};

main(){
   int caso;
   cin >> caso;
   while(caso--){
      string s;
      cin >> s;
      if( check(s) ){
         cout << s << endl;
         continue;
      }

      string ans = s;
      int menor  = 5;

      for(int i = 0; i+2 <=sz(s); i++){
         for(int j = 0; j <6; j++){
            string ss = s;
            int qq = 0;
            for(int k = 0; k < 2; k++){
               if( qual(ss[i+k]) != qual(q[j][k]) ){
                  ss[i+k] = q[j][k];
                  qq++;
               }
            }
            if( check(ss) and qq < menor){
               menor = qq;
               ans = ss;
            }
         }
      }

      for(int i = 0; i < sz(s); i++){
         for(int j = 0; j <3; j++){
            string ss = s;
            int qq = 0;
            if( qual(ss[i]) != qual(w[j][0]) ){
               ss[i] = w[j][0];
               qq++;
            }

            if( check(ss) and qq < menor){
               menor = qq;
               ans = ss;
            }
         }
      }

      cout << ans << endl;
   }
}

