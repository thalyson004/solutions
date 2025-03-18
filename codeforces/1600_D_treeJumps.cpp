/*
   Problem name: -
   Difficulty level: -
   Techniques: -
   Hints: -
   Written by Thalyson
*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector< int >
#define vii vector< pair<int,int> >
#define vvi vector<vector< int > >
#define vvii vector<vector< pair<int,int> > >
#define matrix(l, r) vvi(l, vi(r))
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


//Main
int N, M, K, CASES=1;

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   int mod = 998244353LL;
   int n;

   for(int cases = 1; cases <= CASES; cases++){
      cin >> n;

      int parent[n+5];
      vi G[n+5];
      int level[n+5];
      int cnt[n+5]={0}, cntLevel[n+5]={0};
      int ans = 1;
      level[1] = 1;
      cnt[1] = 1;
      cntLevel[1]=1;
      for(int i = 2; i <= n; i++){
         cin >> parent[i];
         G[parent[i]].push_back(i);
         level[i] = level[parent[i]]+1;
      }

      queue<int> bfs;
      for(int v : G[1]) bfs.push(v);

      while(bfs.size()){
         int v = bfs.front();
         bfs.pop();

         cnt[v] = (cntLevel[ level[v]-1 ] - (parent[v]!=1 ? cnt[parent[v]] : 0) + mod)%mod;
         cntLevel[level[v]] = (cntLevel[level[v]] + cnt[v])%mod;
         ans = (ans+cnt[v])%mod;

         for(int u : G[v]) bfs.push(u);
      }
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
