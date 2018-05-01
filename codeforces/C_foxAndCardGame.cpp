#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define MAXN 200005
#define ii pair<int,int>
#define EPS 0.000000001
#define int long long

int ans[2], n;

main(){
    vector<int> meio;
    cin >> n;
    for(int i = 0; i < n; i++){

        int a, b;
        cin >> a;
        for(int j = 0; j < a/2; j++){
            cin >> b;
            ans[0]+=b;
        }
        if(a%2){
            cin >> b;
            meio.push_back(b);
        }
        for(int j = 0; j < a/2; j++){
            cin >> b;
            ans[1]+=b;
        }
    }

    sort(meio.begin(), meio.end());
    reverse(meio.begin(), meio.end());

    for(int i = 0; i < meio.size();i++)
        ans[i%2] += meio[i];

    cout << ans[0] << " " << ans[1] << endl;
}
