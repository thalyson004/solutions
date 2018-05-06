#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 100005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int casos;
int n, k;

main(){
  int a, b, c;
  cin >> c;
  for(int i = 1; i <= c ; i++){
      cin >> a >> b;
      printf("Caso #%lld: %lld\n", i, ((a+b)*(b-a+1))/2 );
  }
}
