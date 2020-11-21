/*
   Problem name: Rugby
   Difficulty level:
      Medium (If you dont know about this type of problem)
      Easy (If you already seen this type of problem)
   Techniques: Math
   Hints:
      Try solve Y and X independently
      Think about the best position of union
      If you is not used with math, think about ternary search
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

int getSum(vector<int> &Xs){
   int value = Xs[N/2];
   int sum = 0;
   for(int i = 0; i < N; i++) sum += abs(value - Xs[i] );
   return sum;

}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N;

      vi Xs, Ys;
      for(int i = 0; i < N; i++){
         int x,y;
         cin >> x >> y;
         Xs.push_back(x);
         Ys.push_back(y);
      }
      int ans = 0;
      if(N!=1){
         sortv(Ys);
         ans+=getSum(Ys);

         sortv(Xs);
         for(int i = 0; i < Xs.size(); i++){
            Xs[i] -= i+1;
         }
         sortv(Xs);
         ans+=getSum(Xs);
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
