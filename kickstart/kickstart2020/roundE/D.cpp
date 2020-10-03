/*
   Problem name: Golden Stone
   Difficulty level: Medium-Hard (for optimization required)
   Techniques: Dijkstra
   Hints:
      Think about relaxations
      Normally relaxations means some greedy heuristic
      Normally greedy heuristics can be modelled using shortest path
   Written by Thalyson

   obs: oo modified for this problem
*/

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define iii pair<ii, int>
#define iiii pair<ii, ii>
#define viiii vector< iiii >
#define viii vector< iii >
#define vii vector< ii >
#define vi vector< int >
#define vvi vector<vector< int > >
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
#define oo int(1000000000000LL)
#define endl '\n'

//Directions ^>v<
const int dx4[4] = {-1, 0, 1, 0};
const int dy4[4] = {0, 1, 0, -1};

const int dx8[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int dy8[8] = { 0,  1, 1, 1, 0, -1, -1, -1};


//Main
int N, M, S, R, CASES;
template<class T>
struct Matrix{
   int rows;
   int columns;
   vector< vector<T> > grid;

   Matrix(){
         rows = columns = 0;
         grid = vector< vector<T> >();
   }

   Matrix(int _rows, int _columns){
      rows = _rows;
      columns = _columns;
      grid = vector< vector<T> >(rows, vector<T>(columns));
   }

   Matrix(int _rows, int _columns, T value){
      rows = _rows;
      columns = _columns;
      grid = vector< vector<T> >(rows, vector<T>(columns, value));
   }

   bool inside(int row, int column){
      return row>=0 and row<rows and column>=0 and column<columns;
   }

   vector<T>& operator [] (int row){
      return grid[row];
   }

   void fill(T value){
      for(int i = 0; i < rows; i++)
         for(int j = 0; j < columns; j++)
            grid[i][j] = value;
   }

   void clock_rotate(){
      vector< vector<T> > result = vector< vector<T> >(columns, vector<T>(rows));

      for(int i = 0; i < columns; i++){
         for(int j = 0; j < rows; j++){
            result[i][j] = grid[rows-j-1][i];
         }
      }
      swap(columns, rows);
      grid = result;
   }

   void print(){
      for(int i = 0; i < rows; i++){
         for(int j = 0; j < columns; j++){
            cout << grid[i][j] << ' ';
         }
         printf("\n");
      }
   }
};

struct SimpleGraph{
   int vertices;
   vector<vector<int>> edges;

   vector<int> &operator [] (int i){
      return edges[i];
   }

   SimpleGraph(){
      vertices=0;
   }

   SimpleGraph(int _vertices){
      vertices = _vertices;
      edges = vector<vector<int>>(vertices);
   }

   void add_bi_edge(int v, int u){
      edges[v].push_back(u);
      edges[u].push_back(v);
   }
};

struct recipe{
   vector<int> need;
   int target;
   vector<bool> has;
};

struct vertice{
   int cost;
   int v, stone;
   bool operator < (const vertice &b) const & {
      return cost > b.cost;
   }
};

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cout << "Case #" << cases << ": ";

      cin >> N >> M >> S >> R;

      SimpleGraph G(N);
      Matrix<int> dp(N, S, oo);
      vector< recipe > recipes;

      for(int i = 0; i < M; i++){
         int v, u;
         cin >> v >> u;
         v--; u--;
         G.add_bi_edge(u,v);
      }

      priority_queue< vertice > dj;

      for(int i = 0; i < N; i++){
         int quant;
         cin >> quant;
         while(quant--){
            int stone;
            cin >> stone;
            stone--;
            dp[i][stone] = 0;
            dj.push( {0, i, stone} );
         }
      }

      for(int i = 0; i< R; i++){
         int quant, target;
         cin >> quant;
         recipe cur;

         cur.need.resize(quant);
         cur.has.resize(S);

         for(int &x:cur.need){
            cin >> x;
            x--;
            cur.has[x]=true;
         }

         cin >> target;
         target--;
         cur.target = target;
         recipes.push_back( cur );
      }

      int ans = oo;
      while( dj.size() ){
         vertice cur = dj.top();
         dj.pop();

         int v = cur.v;
         int stone = cur.stone;
         int cost = cur.cost;

         if(cost > dp[v][stone] ) continue;
         if(stone==0){
            ans = cost;
            break;
         }

         for(int u:G[v]){
            if( dp[u][stone] > dp[v][stone]+1 ){
               dp[u][stone] = dp[v][stone]+1;
               dj.push( {dp[u][stone], u, stone} );
            }
         }
         for(recipe &r:recipes){
            if( r.has[stone]==false or cost >= dp[v][r.target] ) continue;

            int total = 0;
            for(int s:r.need){
               total += dp[v][s];
            }

            if( dp[v][ r.target ]>total ){
               dp[v][ r.target ] = total;
               dj.push( {total, v, r.target} );
            }
         }
      }

      println(ans==oo ? int(-1) : ans);
   }
}







