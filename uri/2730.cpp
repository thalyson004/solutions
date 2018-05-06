#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define int long long

int n;
vector<int> A,B;

main(){
    while(cin>>n and n){
        A = vector<int>(n);
        B = vector<int>(n);
        set< pair<int, int> > ans;

        for(int i = 0; i<n; i++) cin >> A[i];
        for(int i = 0; i<n; i++) cin >> B[i];

        for(int i = 0; i<n; i++)
            for(int j = 0; j < n; j++)
                if(__gcd(A[i], B[j]) == 1)
                    ans.insert( {A[i], B[j]} ),
                    ans.insert( {B[j], A[i]} );

        cout << ans.size() << "\n";
    }
}
