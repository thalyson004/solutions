#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
//#define int long long

set<int> armario;
int x;
int ans=0;
int tempo[150000];

main(){
    int i = 0, n;
    while(cin >> n){
        ans = 0;
        fill(tempo, tempo+150, 0);
        armario.clear();
        while(n--){
            cin>>x;
            tempo[x] = ++i;
            if( armario.find(x) == armario.end() ){
                ans++;
                armario.insert(x);
                int u = 1000000000;
                int q;

                if(armario.size() == 5){
                    for(auto a:armario){
                        if( tempo[a] < u ){
                            u = tempo[a];
                            q = a;
                        }
                    }
                    armario.erase(q);
                }
            }
        }
        cout << ans << endl;
    }
}
