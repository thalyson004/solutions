/*
   Problem name: L Shaped Plots
   Difficulty level: Easy/medium
   Techniques: Dp
   Hints: Think about how many L you can make with one shared cell.
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

int count(Matrix<int> &G){
   Matrix<int> toUp(N,M);
   Matrix<int> toDown(N,M);

   for(int j = 0; j < M; j++){
      for(int i = 0;  i< N; i++){
         if(G[i][j]){
            toUp[i][j] = 1;
            if(i) toUp[i][j] += toUp[i-1][j];
         }
      }

      for(int i = N-1;  i>=0; i--){
         if(G[i][j]){
            toDown[i][j] = 1;
            if(i+1<N) toDown[i][j] += toDown[i+1][j];
         }
      }
   }

   int ans = 0;
   for(int i = 0; i < N; i++){
      int seq = 0;

      for(int j = 0;  j< M; j++){
         if(G[i][j]) seq++;
         else seq=0;

         if(seq>=2){
            if(toDown[i][j]>=4) ans += min(seq-1, toDown[i][j]/2-1);
            if(toUp[i][j]>=4) ans += min(seq-1, toUp[i][j]/2-1);
         }

         if(seq>=4){
            if(toDown[i][j]>=2) ans += min(seq/2-1, toDown[i][j]-1);
            if(toUp[i][j]>=2) ans+= min(seq/2-1, toUp[i][j]-1);
         }

      }

   }
   return ans;
}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> M;

      Matrix<int> G(N,M);


      for(int i = 0; i < N; i++){
         for(int j = 0;  j< M; j++){
            cin >> G[i][j];
         }
      }
      int ans = 0;
      ans += count(G);

      G.flipH();
      ans += count(G);



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
