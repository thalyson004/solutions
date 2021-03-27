/*
   Problem name: Checksum
   Difficulty level: Hard to see but easy to implement
   Techniques: Spanning tree
   Hints: Think about circles
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

struct disjoint_set{
   int length;
   vector<int> leader;
   vector<int> group_size;
   vector<int> height;

   disjoint_set(){
      length = 0;
   }
   disjoint_set(int _len){
      length = _len;
      leader.resize(length);
      group_size.resize(length);
      height.resize(length);
      for(int i = 0; i < length; i++){
         leader[i]=i;
         group_size[i]=1;
      }
   }

   void update(int x, int y){
      x = query(x);
      y = query(y);
      if( x==y ) return;

      if( height[x]<height[y] ){
         swap(x,y);
      }else if(height[x]==height[y]){
         height[x]++;
      }

      group_size[ x ] += group_size[ y ];
      leader[ y ] = x;
   }

   bool query(int x, int y){
      return query(x)==query(y);
   }

   int query(int x){
      return x==leader[x]?(x):(leader[x] = query(leader[x]));
   }

   int get_size(int x){
      return group_size[ query(x) ];
   }
};


//Main
int N, M, K, CASES=1;

bool finish(vector<int> &v1, vector<int> &v2 ){
   for(int value: v1) if(value) return false;
   for(int value: v2) if(value) return false;
   return true;
}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N;

      Matrix<int> A(N,N), B(N,N);
      vector<int> R(N), mR(N);
      vector<int> C(N), mC(N);

      for(int i = 0; i < N; i++){
         for(int j = 0; j < N; j++){
            cin >> A[i][j];
         }
      }

      vector< pair<int, pair<int, int> > > cells;
      int ans = 0;

      for(int i = 0; i < N; i++){
         for(int j = 0; j < N; j++){
            cin >> B[i][j];
            if(A[i][j]==-1){
               cells.push_back( {B[i][j], {i,j+N} } );
               ans += B[i][j];
            }
         }
      }
      sortv(cells);
      reversev(cells);

      for(int i = 0; i < N; i++){
         cin >> R[i];
      }
      for(int i = 0; i < N; i++){
         cin >> C[i];
      }

      disjoint_set groups(N*2);

      for(auto cell: cells){
         int l = cell.second.first;
         int r = cell.second.second;
         int value = cell.first;

         if( !groups.query(l,r) ){
            ans -= value;
            groups.update(l,r);
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
