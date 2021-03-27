/*
   Problem name: Rabbit House
   Difficulty level: Easy
   Techniques: BFS + greedy
   Hints:
      hit 01 - Think about the best strategy you can use.
      hit 02 - Try start with the greatest value and go decreasingly
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
#define send fflush(stdout)

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

   Matrix pow(int x, int mod){
      if(rows!=columns) return Matrix();

      Matrix<T> ans(rows, columns);
      for(int i=0; i < rows; i++)
         ans[i][i] = 1;

      Matrix<T> cur = *this;
      while(x){
         if(x&1){
            ans = multiply(ans, cur, mod);
         }
         cur = multiply(cur, cur, mod);
         x /= 2;
      }

      return ans;
   }


   void print(){
      for(int i = 0; i < rows; i++){
         for(int j = 0; j < columns; j++){
            cout << grid[i][j] << ' ';
         }
         cout << "\n";
      }
   }

   void flipH(){
      for(int i = 0; i < rows; i++){
         reverse(grid[i].begin(), grid[i].end());
      }
   }

private:
   Matrix<T> multiply(Matrix<T> &a, Matrix<T> &b, int mod){
      if(a.columns != b.rows ) return Matrix();
      Matrix<T> ans(a.rows, b.columns);
      for(int i = 0; i < a.rows; i++){
         for(int j = 0; j < b.columns; j++){
            for(int k = 0; k < a.columns; k++){
               ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod;
            }
         }
      }
      return ans;
   }
};

//Main
int N, M, K, CASES=1;

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> M;

      priority_queue< pair<int, pair<int,int>> > bfs;

      Matrix<int> G(N, M);
      for(int i =0; i< N; i++){
         for(int j = 0; j < M; j++){
            cin >> G[i][j];

            bfs.push( {G[i][j], {i,j}} );
         }
      }

      int ans = 0;
      while(bfs.size()){
         int r = bfs.top().second.first;
         int c = bfs.top().second.second;

         int value = bfs.top().first;
         bfs.pop();

         if(G[r][c]!=value) continue;

         for(int d = 0; d < 4; d++){
            int rr = r+dx4[d];
            int cc = c+dy4[d];

            if(rr>=0 and cc>=0 and rr<N and cc<M and G[r][c] > G[rr][cc]+1 ){
               ans += G[r][c] - (G[rr][cc]+1);
               G[rr][cc] = G[r][c]-1;
               bfs.push( {G[rr][cc], {rr,cc} } );
            }
         }

      }

      cout << "Case #" << cases << ": ";
      println(ans);
   }
}

/*
   Before submit:
      Check the corners cases
      Check solution restrictions

   For implementation solutions
      Check the flow of the variables

   For intervals problems
      Think about two pointers

   For complete search
      Think about cuts
*/
