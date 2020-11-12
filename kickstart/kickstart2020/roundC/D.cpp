/*
   Problem name: Candies
   Difficulty level: Medium/easy
   Techniques:
      Prefix Sum
      Fenwick Tree
   Hints:
      Think how represent the sum using sums of intervals
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

struct PrefixSumBit{
   int len;
   vector<int> bit;

   /*1 to len*/
   PrefixSumBit(int _len): len(_len), bit(len+1){}

   /*LeastSignificantBit*/
   static int LSB(int value){
      return value & -value;
   }

   void update(int value, int id){
      while( id <= len ){
         bit[id]+=value;
         id += LSB(id);
      }
   }

   int query(int id){
      int ans = 0;
      while(id){
         ans += bit[id];
         id -= LSB(id);
      }
      return ans;
   }
};
struct PosfixSumBit : public PrefixSumBit{
   PosfixSumBit(int _len) : PrefixSumBit(_len){}

   int reverseIndex(int id){
      return len-id+1;
   }
   int query(int id){
      return PrefixSumBit::query(reverseIndex(id));
   }
   void update(int value, int id){
      PrefixSumBit::update(value, reverseIndex(id));
   }
};
//END

//Main
int N, M, K, CASES;
const int MAXN = 200005;


main(){
   //std::ios::sync_with_stdio(false);
   //cin.tie(0);
   //cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> M;
      vi v(N);
      scanv(v);

      PrefixSumBit sum[2] = {PrefixSumBit(N), PrefixSumBit(N)};
      PrefixSumBit sumM[2] = {PrefixSumBit(N), PrefixSumBit(N)};

      for(int i = 0; i < N; i++){
         sum[(i+1)%2].update(v[i], i+1 );
         sumM[(i+1)%2].update(v[i]*(i+1), i+1 );
      }
      int ans = 0;
      while(M--){
         char op;
         int x, y;
         cin >> op >> x >> y;
         if(op == 'Q'){
            int cur = 0;
            cur += sumM[x%2].query(y)-sumM[x%2].query(x-1);
            cur -= (sum[x%2].query(y)-sum[x%2].query(x-1))*(x-1);

            cur -= sumM[(x+1)%2].query(y)-sumM[(x+1)%2].query(x-1);
            cur += (sum[(x+1)%2].query(y)-sum[(x+1)%2].query(x-1))*(x-1);

            ans += cur;
         }else{
            sum[x%2].update(-v[x-1], x);
            sumM[x%2].update(-x*v[x-1],x);
            v[x-1]=y;
            sumM[x%2].update(x*v[x-1],x);
            sum[x%2].update(v[x-1],x);
         }
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





















