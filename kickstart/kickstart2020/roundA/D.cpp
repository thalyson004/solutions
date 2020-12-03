/*
   Problem name: Bundling
   Difficulty level: Medium
   Techniques: Trie
   Hints:
      Think about removing the largest prefix as possible
      Think about prefix strings structures

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
int N, K, CASES;
vector<int> v;

struct Trie{
   struct node{
      int value;
      node *children[26];
      node(){
         value = 0;
         for(int i =0; i < 26; i++) children[i] = NULL;
      }
      node(int value){
         this->value = value;
         for(int i =0; i < 26; i++) children[i] = NULL;
      }
   };

   node *root;

   Trie(){
      root = new node();
   };

   void add_word(string &word){
      node *cur = root;
      cur->value++;
      for(char letter: word){
         int id = letter-'A';
         if( cur->children[id] == NULL ) cur->children[id] = new node();
         cur = cur->children[id];
         cur->value++;
      }
   }
   int solve(node *cur, int deep, int &ans){
      int rem = 0;
      for(int i = 0; i < 26; i++){
         if(cur->children[i]!=NULL){
            rem += solve(cur->children[i], deep+1, ans);
         }
      }
      if(cur->value-rem >= K){
         int quantity = (cur->value-rem)/K;
         rem+=K*quantity;
         ans+=deep*quantity;
      }

      return rem;
   }

   int solve(int &ans){
      return solve(root, 0, ans);
   }

   ~Trie(){
      clear(root);
   }
   void clear(node* cur){
      if(cur==NULL)return;
      for(int i = 0; i < 26; i++){
         clear(cur->children[i]);
      }
      delete(cur);
   }
};

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> CASES;
   for(int cases = 1; cases <= CASES; cases++){
      cin >> N >> K;

      Trie myTrie;

      for(int i = 0; i < N; i++){
         string s;
         cin >> s;
         myTrie.add_word(s);
      }

      int ans = 0;
      myTrie.solve(ans);

      cout << "Case #"<<cases<<": ";
      println(ans);
   }
}

/*
2
2 2
KICK
START
8 2
G
G
GO
GO
GOO
GOO
GOOO
GOOO
*/
