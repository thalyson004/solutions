/*
   Problem name: Beauty of tree
   Difficulty level: Medium
   Techniques: DFS + Expected Value
   Hints:
      Using a DFS on tree, all vertices in stack are parents of the current node.
      Expected value could be Ev = Value(1)*F(1) + Value(2)*F(2)...
      But also could be Ev = (Sum of Values)/(Total number of events)

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
int N, A, B, CASES;

vvi GA, GB, G;
vi CA, CB;

void create(int v, vi &cur){
   if(cur.size()>=A) GA[ cur[sz(cur)-A] ].push_back(v);
   if(cur.size()>=B) GB[ cur[sz(cur)-B] ].push_back(v);
   cur.push_back(v);

   for(int u:G[v])
      create(u, cur);

   cur.pop_back();
}

int countChildren(int v, vi &C, vvi &G){
   if(C[v]!=0)return C[v];

   C[v] = 1;

   for(int u:G[v])
      C[v]+=countChildren(u, C, G);

   return C[v];
}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> A >> B;

      G = vvi(N);
      GA = vvi(N);
      GB = vvi(N);

      for(int i = 1; i < N; i++){
         int u;
         cin >> u;
         G[u-1].push_back(i);
      }


      vector<int> cur;
      create(0, cur);

      CA=vi(N);
      CB=vi(N);
      for(int i = 0; i < N; i++){
         countChildren(i, CA, GA);
         countChildren(i, CB, GB);
      }

      double ans = 0;
      double total = N*N;
      for(int i = 0; i < N; i++){
         ans += (CA[i]*N)/total;
         ans += (CB[i]*N)/total;
         ans -= (CA[i]*CB[i])/total;
      }

      cout << "Case #" << cases << ": ";
      println(ans);
   }

   /*
      Before submit:
         Check the corners cases
         Check solution restrictions

      For implementation solutions
         Check the flow of the variables
   */
}
