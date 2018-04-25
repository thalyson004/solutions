#include <bits/stdc++.h>
#define MAXN 1005
//#define int long long
using namespace std;

#define pos first
#define vel second

main(){
    int w,h,n;
    set<int> H,V;
    multiset<int> MH,MV;

    scanf("%d %d %d", &w, &h, &n);
    H.insert(0);
    V.insert(0);

    H.insert(h);
    V.insert(w);

    MH.insert( h );
    MV.insert( w );
    for(int i = 0; i < n; i++){
        char c;
        int l;
        scanf(" %c %d", &c, &l);
        if(c=='H'){
            H.insert( l );
            auto it = H.find( l );
            auto a = prev(it);
            auto b = next(it);
            MH.erase( MH.find( (*b) - (*a) )  );

            MH.insert( (*it) - (*a) );
            MH.insert( (*b) -  (*it) );
        }else{
            V.insert( l );
            auto it = V.find( l );
            auto a = prev(it);
            auto b = next(it);
            MV.erase( MV.find( (*b) - (*a) )  );
            MV.insert( (*it) - (*a) );
            MV.insert( (*b) -  (*it) );
        }

        auto a = MH.end(); --a;
        auto b = MV.end(); --b;
        printf("%lld\n", 1LL*(*a)*(*b) );
    }

}

/*
7 6 5
H 4
V 3
V 5
H 2
V 1
*/
