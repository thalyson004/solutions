#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

main(){
    vector<int> man;
    for(int i = 0; i < 14; i++){
        int a;
        cin >> a;
        man.push_back( a );
    }
    int ans = 0;
    for(int i = 0; i < 14; i++){
        vector<int> cur = man;

        int total = cur[i];
        cur[i] = 0;
        for(int j = i+1; j < 14 and total; j++) cur[j]++, total--;
        for(int j = 0; j < 14; j++) cur[j] += total/14;
        total %= 14;
        for(int j = 0; j < 14 and total; j++)cur[j]++, total--;

        int temp = 0;
        for(int j = 0; j < 14; j++)
            if( cur[j]%2==0 )
                temp += cur[j];
        ans = max(ans, temp);
    }
    cout << ans << endl;

}
