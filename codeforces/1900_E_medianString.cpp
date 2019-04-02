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

#define MAXN 300005
#define MAXM 305
#define MAXB 20
#define EPS 1e-6
#define oo (1LL<<60)
#define MAX 1000000000LL

const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

string a, b;
int len;

string sum(string a, string b){
   string c;
   reverse(all(a));
   reverse(all(b));
   int go = 0;
   for(int i = 0; i < len; i++){
      c.push_back( a[i]+b[i]-'a'+go );
      if(!islower( c[i] )){
         go = 1;
         c[ i ]-=26;
      }else go = 0;
   }
   if(go) c.push_back('b');
   reverse(all(c));
   return c;
}

string divide(string a){
   string b;
   int go = 0;
   for(char c:a){
      b.push_back( 'a' + (c-'a')/2 + 13*go );
      go = (c-'a')%2;
   }
   return b;
}

main(){

   cin >> len >> a >> b;
   string c = divide( sum(a, b) );
   if(c.size()>len) c.erase(c.begin());
   cout << c << endl;
}
