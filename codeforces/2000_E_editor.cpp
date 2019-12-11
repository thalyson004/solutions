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
#define debug(x) cout << #x << " is " << x << "\n";

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -2};

int N;
string in;
#define ciii pair< pair<char, int> , pair<int, int > >
stack < ciii > L, R;

void addLeft( char c ){
   if( L.size() ){
      ciii temp = L.top();
      temp.F.F=c;

      if(c== '(' ){
         temp.F.S++;
         temp.S.F = max(temp.F.S, temp.S.F);
      }else if( c==')' ){
         temp.F.S--;
         if( temp.F.S<0 ) temp.S.S = 0;
      }
      L.push( temp );

   }else{
      if(c== '(' ){
         L.push( {{c, 1}, {1 , 1}} );
      }else if( c==')' ){
         L.push( {{c, -1}, {-1 , 0}} );
      }else{
         L.push( {{c, 0}, {0 , 1}} );
      }
   }

}

void addRight( char c ){
   if( R.size() ){
      ciii temp = R.top();
      temp.F.F=c;

      if(c== ')' ){
         temp.F.S++;
         temp.S.F = max(temp.F.S, temp.S.F);
      }else if( c=='(' ){
         temp.F.S--;
         if( temp.F.S<0 ) temp.S.S = 0;
      }
      R.push( temp );
   }else{
      if(c== '(' ){
         R.push( {{c, -1}, {-1 , 0}} );
      }else if( c==')' ){
         R.push( {{c, 1}, {1 , 1}} );
      }else{
         R.push( {{c, 0}, {0 , 1}} );
      }
   }
}

char removeRight(){
   char ans = R.size()?R.top().F.F:' ';
   if( R.size() ){
      R.pop();
   }
   return ans;
}
char removeLeft(){
   char ans = L.size()?L.top().F.F:' ';
   if( L.size() ){
      L.pop();
   }
   return ans;
}

bool ok(stack< ciii > &t){
   return t.empty() or t.top().S.S;
}
int Open(){
   return L.size()? L.top().F.S :0;
}
int Close(){
   return R.size()? R.top().F.S :0;
}
int Max( stack< ciii > &t ){
   return t.size()? t.top().S.F :0;
}

int verify(char c){
   addLeft( c );

   int ans = ( ok(R) and ok(L) and Open() == Close() ) ?
               max(Open(), max(Max(L), Max(R)) ) : -1;
   removeLeft();
   return ans;
}

main(){
   cin >> N >> in;
   char actual = ' ';

   for(char c: in){
      if( c=='R' ){
         addLeft(actual);
         actual = removeRight();
      }else if( c=='L' ){
         if(L.size()){
            addRight(actual);
            actual = removeLeft();
         }
      }else{
         actual = c;
      }

      printf("%d ", verify(actual) );
   }
}
