/*
   Problem name: Wandering Robot
   Difficulty level: Hard
   Techniques: Math
   Hints:
      Think about how many path to (i,j).
      Think about the safe routes.
      Storage fat and powers of 2 using log.
      Exp function is the mirror function to log.
      For simplicity, you can rotate the matrix
         swapping those values (M,N) (L,U) and (R,D)

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
int N, M, CASES;
int L, U, R, D;

double fat[200005];
double ptwo[200005];

double comb(int r, int c){
   return fat[r+c] - fat[r] - fat[c];
}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(12) << fixed;

   fat[0] = 0;
   ptwo[0] = 0;
   ptwo[1] = log(2.0);
   for(int i = 1; i < 200005; i++){
      fat[i]= fat[i-1] + log(i);
      ptwo[i] = ptwo[i-1] + ptwo[1];
   }

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> M >> N;
      cin >> L >> U >> R >> D;
      M--;N--;
      L--;U--;R--;D--;

      double ans = 0;

      if(R<M){
         for(int i = U-1, j = R+1; i>=0; i--, j++){
            double div = (j>M?2.0:1.0);
            j = min(j, M);
            int r = i;
            int d = j;
            ans += exp(comb(r, d)-ptwo[r+d])/div;
         }
      }
      swap(N,M);
      swap(U,L);
      swap(D,R);
      if(R<M){
         for(int i = U-1, j = R+1; i>=0; i--, j++){
            double div = (j>M?2.0:1.0);
            j = min(j, M);
            int r = i;
            int d = j;
            ans += exp(comb(r, d)-ptwo[r+d])/div;
         }
      }


      cout << "Case #"<<cases<<": ";
      println( abs(ans) );
   }
}

/*

1
3 3 2 2 2 2

5
3 3 2 2 2 2
5 3 1 2 4 2
1 10 1 3 1 5
6 4 1 3 3 4
*/
