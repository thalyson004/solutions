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
int len;
string s;


main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> len >> s;
      int ans;

      for(ans = 1; ans < len; ans++){
         if(len%ans) continue;

         int hasTwo = -1;

         vector<map<char,int>> counts = vector<map<char,int>>(ans, map<char,int>());

         for(int i=0; i<len and hasTwo<len; i++){
            int pos = i%ans;
            char letter = s[i];

            if(counts[pos].size()==1 and counts[pos].count(letter)==0){
               if(hasTwo==-1){
                  hasTwo = pos; //index pos have two letters
               }else{
                  hasTwo = len; //Impossible
               }
            }

            counts[pos][letter]++;

            if(counts[pos].size()>2){
               hasTwo=len; //Impossible
            }

         }

         if(hasTwo>=0 and hasTwo<len ){
            int mn = INT_MAX;
            for(auto &element:counts[hasTwo]){
               mn = min(mn, element.second);
            }
            if(mn>1){
               hasTwo = len; //Impossible
            }
         }

         if(hasTwo!=len) break;
      }

      println(ans);
   }
}
