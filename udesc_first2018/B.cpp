#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 1000005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

string lego[5][5] = {
"***", "***", "***", "***" , "***",
"*.*", "*.*", "*..", "*.*",  "*..",
"***", "***", "*..", "*.*", "***",
"*.*", "*.*", "*..", "*.*", "*..",
"*.*", "***", "***", "***", "***"};

main(){
  int n;
  string s;
  cin >> n >> s;
  for(int i = 0;i < 5; i++){
    for(int j = 0; j < n; j++) cout << lego[i][ s[j]-'A' ];
    cout << endl;
  }
}
