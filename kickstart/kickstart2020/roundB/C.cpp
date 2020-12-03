/*
   Problem name: Robot Path Decoding
   Difficulty level: Easy
   Techniques: Simulation and Parser
   Hints:
      Think about parser, for sample math expressions
      Think about dfs or stack to help.

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
int N, CASES;
string commands;
int mod = 1000000000;

void change(pair<int,int> &cur, char op){
   if(op=='N') cur.second--;
   else if(op=='S') cur.second++;
   else if(op=='W') cur.first--;
   else if(op=='E') cur.first++;

   cur.first = (cur.first + mod)%mod;
   cur.second = (cur.second + mod)%mod;
}

pair<int,int> solve(int &i){
   pair<int,int> ans = {0,0};

   while(i<N){
      if( commands[i]>='A' and commands[i]<='Z' ){
         change(ans, commands[i++]);
      }else if(commands[i]==')'){
         i++;
         break;
      }else {
         int t = commands[i]-'0';
         i+=2;
         pair<int,int> cur  = solve(i);
         ans.first += cur.first*t;
         ans.second += cur.second*t;
         change(ans, '@');
      }
   }

   return ans;
}

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> commands;
      N = commands.size();

      int i=0;
      pair<int,int> ans = solve(i);
      ans.first++;
      ans.second++;

      cout << "Case #"<<cases<<": ";
      println(ans.first, ans.second );
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
