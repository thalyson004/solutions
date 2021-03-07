/*
   Problem name: Parenting Partnering Returns
   Difficulty level: Easy
   Techniques: Greedy + Sorting
   Hints: Is not a optimization. The answer is boolean.
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
int N, M, K, CASES=1;

struct activity{
   int start, finish;
   int id;

   bool operator < (activity cur){
      if(start!=cur.start) return start<cur.start;
      return finish<cur.finish;
   }
};

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N;
      vector< activity > acts;

      for(int i = 0; i < N; i++){
         int start, finish;
         cin >> start >> finish;
         acts.push_back( {start, finish, i} );
      }
      sortv(acts);

      string ans = string(N, '@');
      int j = 0;
      int c = 0;
      int flag = 1;
      for(activity cur: acts){
         if(min(j,c)>cur.start){
            flag = 0;
            break;
         }
         if(j<c){
            ans[ cur.id ] = 'J';
            j = cur.finish;
         }else{
            ans[ cur.id ] = 'C';
            c = cur.finish;
         }
      }

      cout << "Case #" << cases << ": ";
      if(flag){
         println(ans);
      }else{
         println("IMPOSSIBLE");
      }
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
