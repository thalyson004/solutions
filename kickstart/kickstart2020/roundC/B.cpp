/*
   Problem name: Stable Wall
   Difficulty level: Easy
   Techniques: Topological sorting
   Hints: Check how order is needed.
   Written by Thalyson
*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector< int >
#define vii vector< pair<int,int> >
#define vvi vector<vector< int > >
#define vvii vector<vector< pair<int,int> > >
#define int int64_t


#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sortv(V) sort(all(V))
#define reversev(V) reverse(all(V))
#define uniquev(V) sortv(V),(V).erase(unique(all(V)),(V).end())
#define pb push_back


#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define debug(x) cout << #x << " is " << x << "\n";

// Trace dinâmico (parameter pack (c++11))
template<typename T>
void println(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void println(T a, Args... args) { cout << a << " "; println(args...); }

template<typename T>
void print(T a) { cout << a; }
template<typename T, typename... Args>
void print(T a, Args... args) { cout << a << " "; print(args...); }

template<typename T>
void printv(T a, string last="\n") {
    for(auto el: a)
      print(el, "");
    print(last);
}

template<typename T>
void scanv(T &a) {
    for(auto &el: a)
      cin >> el;
}


//Constants
#define EPS 1e-6
#define oo int(1LL<<60)
#define endl '\n'

//Directions ^>v<
const int dx4[4] = {-1, 0, 1, 0};
const int dy4[4] = {0, 1, 0, -1};

const int dx8[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int dy8[8] = { 0,  1, 1, 1, 0, -1, -1, -1};


//Main
int N, M, K, CASES;

char grid[30][30];
set< char > letter;

vi G[30];
int adj[30][30];
vector<char> vans;
int color[30];

int value(char c){
   return c-'A';
}

int dfs(int v){
   color[v] = 1;

   for(int u:G[v]){
      if( color[u]==1 )return 0;
      if( color[u]==0 and !dfs(u) ) return 0;
   }
   vans.pb( 'A'+v );
   color[v] = 2;
   return 1;
}

main(){
   //std::ios::sync_with_stdio(false);
   //cin.tie(0);
   //cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> M;
      letter.clear();
      vans.clear();

      for(int i = 0; i < 30; i++){
         G[i].clear();
         color[i]=0;
         for(int j = 0; j < 30; j++)
            adj[i][j]=0;
      }

      for(int i = 0; i < N; i++){
         cin >> grid[i];
         for(int j = 0; j < M; j++)
            letter.insert( grid[i][j] );
      }

      for(int i = 0; i+1 < N; i++){
         for(int j = 0; j < M; j++){
            int v = value( grid[i][j] );
            int u = value( grid[i+1][j] );
            if( u!=v and !adj[u][v] ){
               adj[u][v] = 1;
               G[u].pb(v);
            }
         }
      }

      int ans = 1;
      for(char c: letter){
         if(!color[ value(c)])
            ans = dfs( value(c) );
         if(!ans)break;
      }


      cout << "Case #" << cases << ": ";

      if(!ans) print("-1\n");
      else{
         reverse( all(vans) );
         for(char c:vans) print(c);
         print("\n");
      }

   }


   /*
      Before submit:
         Check the corners cases
         Check solution restrictions

      For implementation solutions
         Check the flow of the variables
   */
}





















