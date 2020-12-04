/*
   Problem name: Locked Doors
   Difficulty level: Hard
   Techniques:
      Greedy
      RMQ structure
      Binary Search
   Hints:
      If you moved left by L doors, how many right doors most you move?

   Written by Thalyson
*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define FF first.first
#define FS first.second
#define S second
#define SF second.first
#define SS second.second
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

struct SparseTable {
   int len;
   int log;
   int INF;
   int(*func)(int,int);
   vector< vector<int> > table;

   template<class RandomIterator>
   SparseTable( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){
      len = distance(begin, end);
      func = _func;
      setINF();
      setLog();

      table = vector< vector<int> >(log+1, vector<int>(len, -INF) );
      for(int i = 0; i < len; i++){
         table[0][i] = begin[i];
      }

      for(int i = 1; i <= log; i++){
         for(int j = 0; j < len; j++){
            if( j+(1<<i)-1 < len ){
               table[i][j] = func(table[i-1][j], table[i-1][j+(1<<(i-1))]);
            }
         }
      }
   }

   void setINF(){
      INF = 1;
      while( INF < (INF<<2) ) INF = (INF<<2);
      INF = func(INF, -INF );
   }

   void setLog(){
      log = 1;
      while( (1<<log) < len  ) log++;
   }

   int query(int l, int r){
      if(l>r or l<0 or r>=len) return -INF;
      if(l==r)return table[0][l];
      int n = 0;
      while(l+(1<<(n+1)) <= r) n++;
      return func( table[n][l], table[n][r-(1<<n)+1] );
   }
};

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
int N, Q, CASES;
vector<int> dif;

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> Q;
      dif.resize(N+1);
      dif[0] = 0;
      for(int i = 1; i <N; i++) cin >> dif[i];
      dif[N] = 0;
      SparseTable tree(dif.begin(), dif.end());

      vector<int> ans;

      while(Q--){
         int start, step;
         cin >> start >> step;
         step--;

         if(step==0){
            ans.push_back(start);
            continue;
         }else if(start == 1){
            ans.push_back(start+step);
            continue;
         }else if(start == N){
            ans.push_back(start-step);
            continue;
         }

         int l = 0, r = min(step, start-1);
         while(l < r){
            int m = (l+r+1)/2;
            int mx = tree.query(start-m, start-1);

            int rl = 0, rr = N-start;
            while(rl < rr){

               int mm = (rl+rr+1)/2;
               int mxx = tree.query(start, start+mm-1);

               if(mxx < mx) rl = mm;
               else rr = mm-1;
            }
            int quantity = (rl+m);
            if( quantity <= step ) l = m;
            else r = m-1;
         }

         int left = start-l;
         int right = left + step;

         if(l==0) start = right;
         else if(l==step) start = left;
         else if( tree.query(left, start-1)>tree.query(start, right-1) ) start = left;
         else start = right;

         ans.push_back(start);
      }


      cout << "Case #" << cases << ": ";
      printv(ans);
   }
}

/*
2
5 4
90 30 40 60
3 4
3 1
1 5
4 3
10 2
6 2 4 5 9 30 7 1 8
6 8
6 8
*/
