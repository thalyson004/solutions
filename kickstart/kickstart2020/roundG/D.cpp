/*
   Problem name: Merge Cards
   Difficulty level: Hard (to me)
   Techniques: Dynamic Programmig and Expected value
   Hints:
      For test 1: Think about all possibilities
      For test 2: Think about dp to not recalc.
      For test 3: Think about how linearity of expected value can be
         used to improve DP to quadratic.

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
int maxN=5005;
vector<vector<double>> dp;

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   dp = vector<vector<double>>(maxN, vector<double>(maxN, 0));
   for(int i = 0; i < maxN; i++){
      for(int j = 0; j < maxN; j++){
         double &ans = dp[i][j];
         if(i>0) ans += (1.0/(i+j))*(1.0 + dp[i-1][j]);
         if(i>1) ans += ((i-1.0)/(i+j))*dp[i-1][j];

         if(j>0) ans += (1.0/(i+j))*(1.0 + dp[i][j-1]);
         if(j>1) ans += ((j-1.0)/(i+j))*dp [i][j-1];
      }
   }

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N;
      double ans = 0;
      for(int i = 0; i < N; i++){
         double value;
         cin >> value;
         ans += (value*dp[i][N-1-i]);
      }

      cout << "Case #" << cases << ": ";
      cout << ans << endl;
   }

}



















