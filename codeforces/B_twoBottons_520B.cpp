#include <bits/stdc++.h>
#define MAXN 1005
#define int long long
using namespace std;

int dist[100005];

main(){
    int a, b;
    cin >> a >> b;
    queue<int> fila;
    fila.push( a );
    dist[a] = 1;
    while(fila.size()){
        a  = fila.front();
        fila.pop();
        if( a*2 <= b*2 and !dist[ a*2 ] ){
            dist[ a*2 ] = dist[a]+1;
            fila.push( a*2 );
        }

        if( a and !dist[ a-1 ] ){
            dist[ a-1 ] = dist[a]+1;
            fila.push( a-1 );
        }
    }
    cout << dist[b]-1 << endl;

}
