/*
   Problem name: Combination Lock
   Difficulty level: mid-level
   Techniques: SumArray and Math
   Hints: Think about which intervals are better move directly
            and which intervals are better move around.
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

struct SumArray{
   int len;
   vector<int> sum_array;

   SumArray(vector<int> &v){
      len = v.size();
      for(int i = 0; i < len; i++){
         sum_array.push_back( v[i] + query(i-1) );
      }
   }
   int query(int l, int r){
      if(l>r) return 0;
      return query(r) - query(l-1);
   }

   int query(int r){
      if(r<0) return int(0);
      else return sum_array[r];
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
      cin >> N >> K;
      vi v(N);
      scanv(v);
      sortv(v);
      SumArray sum(v);

      int ans = oo;
      int l = 0, r = 0;
      for(int i = 0; i < N; i++){
         while(l<i and v[l]+K-v[i]<v[i]-v[l]) l++;
         r = max(r,i);
         while(r<N and v[r]-v[i]<K-v[r]+v[i] ) r++;
         int cost = (i-l)*v[i]-sum.query(l,i-1);
         cost += sum.query(i+1,r-1)-(r-i-1)*v[i];
         if(l){
            cost += sum.query(0, l-1) + (K-v[i])*(l);
         }else if(r<N){
            cost += (N-r)*K - sum.query(r, N-1) + (N-r)*v[i];
         }
         ans = min(ans, cost);
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
