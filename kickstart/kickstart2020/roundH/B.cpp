/*
   Problem name: Boring Numbers
   Difficulty level: Medium
   Techniques: Math
   Hints:
      Build the calc for [0, N] = F(N)
      [L, R] = F(R)- F(L-1)
      Think about numbers using all digits.
      Think about numbers using less digits.

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

int L, R;
vi vl, vr;

int calc(string number){
   int ans = 0;
   int p = 1;
   for(int i = 1; i < number.size(); i++){
      p*=5;
      ans += p;
   }
   p*=5;


   for(int i = 0; i < number.size(); i++){
      int value = number[i]-'0';
      p/=5;
      for(int j = (i+1)%2; j < value; j+=2){
         ans += p;
      }
      if( value%2 != (i+1)%2 ) p = 0;
   }

   return ans+p;
}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){

      cin >> L >> R;
      string sL=to_string(L-1), sR=to_string(R);

      cout << "Case #" << cases << ": ";
      println( calc(sR)-calc(sL) );
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
