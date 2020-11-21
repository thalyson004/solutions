/*
   Problem name: Friends
   Difficulty level: Easy
   Techniques: BFS, Graph Modeling
   Hints:
      Think about how model the graph for minimize the number of edges
      Number of edges will be 26*N, not N*N
      Think about divide the path between two names
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

   void add_edge(int v, int u){
      edges[v].push_back(u);
   }

   vector<int> distanceFrom(int v){
      vector<int> dist(vertices, -1);
      dist[v] = 0;
      queue<int> bfs;
      bfs.push( v );
      while(bfs.size()){
         int v = bfs.front();
         bfs.pop();

         for(int u: edges[v]){
            if( dist[u]==-1 ){
               dist[u] = dist[v]+1;
               bfs.push( u );
            }
         }
      }
      return dist;
   }

   int longestVerticeFrom(int v){
      vector<int> distA = distanceFrom(v);
      int longest = 0;
      for(int i = 0; i < vertices; i++){
         if(  distA[longest] < distA[i] )
            longest = i;
      }
      return longest;
   }

   int longestDistanceFrom(int v){
      vector<int> distA = distanceFrom(v);
      int longest = 0;
      for(int i = 0; i < vertices; i++){
         if(  distA[longest] < distA[i] )
            longest = i;
      }
      return distA[longest];
   }

   int diameter(){
      int longest = longestVerticeFrom(0);
      return longestDistanceFrom(longest);
   }

   SimpleGraph transpose(){
      SimpleGraph ans(vertices);
      for(int v = 0; v < vertices; v++){
         for(int u:edges[v])
            ans.add_edge(u,v);
      }
      return ans;
   }

   void toposort(int v, vector<int> &order, vector<bool> &mark){
      mark[v]=1;
      for(int u: edges[v]){
         if(!mark[u])
            toposort(u, order, mark);
      }
      order.push_back(v);
   }

   vector<int> toposort(){
      vector<int> order;
      vector<bool> mark(vertices);
      for(int i = 0; i < vertices; i++ ){
         if(!mark[i])
            toposort(i, order, mark);
      }
      return order;
   }

   vector<int> scc(){
      vector<int> comp(vertices);
      vector<int> order = toposort();
      SimpleGraph T = transpose();

      int cur = 0;
      while(order.size()){
         int v = order.back();
         order.pop_back();
         if(comp[v])continue;
         queue<int> bfs;
         bfs.push(v);
         comp[v] = ++cur;
         while(bfs.size()){
            v = bfs.front();
            bfs.pop();
            for(int u:T[v]){
               if(!comp[u]){
                  comp[u]=cur;
                  bfs.push(u);
               }
            }
         }
      }
      return comp;
   }
};


//Main
int N, M, K, CASES;

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> M;

      vector<int> ans;

      vector<string> names(N);
      scanv(names);

      SimpleGraph G(N+30);
      {
         int v = 0;
         for(string &name:names){
            uniquev(name);
            for(char letter:name){
               G.add_bi_edge(v, N + (letter-'A'));
            }
            v++;
         }
      }

      vector< vector<int> > distFrom;
      for(int i = 0; i < 26; i++){
         distFrom.push_back( G.distanceFrom(N+i) );
      }

      for(int i = 0; i < M; i++){
         int v,u;
         cin >> v >> u;
         v--;
         u--;
         int dist = oo;
         for(int letter = 0; letter < 26; letter++){
            if( distFrom[letter][v]>0 and distFrom[letter][u]>0 ){
               int cur = distFrom[letter][v] + distFrom[letter][u] + 1;
               if(cur>0){
                  cur -= cur/2;
                  dist = min(dist, cur);
               }
            }
         }
         if(dist == oo) dist = -1;
         ans.push_back( dist );
      }


      cout << "Case #" << cases << ": ";
      printv(ans);
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
