/*
   Problem name: Perfect Subarray
   Difficulty level: Easy-Medium
   Techniques: Precalc sum
   Hints:
      Think about prefix sum or/and suffix sum
      Try improve query for negatives numbers

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

int pos(int x){
   if(x<0) return 100*N - x;
   return x;
}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N;

      vi v(N);
      scanv(v);

      int ans = 0;


      cout << "Case #" << cases << ": ";

      int sum = 0;

      vi mapa(N*100*2 + 5);
      mapa[0] = 1;

      for(int i = 0; i < N; i++){
         int value = v[i];
         sum += value;

         for(int target = 0; sum-target*target >= -100*(i+1); target++){
            ans += mapa[ pos(sum - target*target) ];
         }
         mapa[ pos(sum) ]++;
      }
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





















