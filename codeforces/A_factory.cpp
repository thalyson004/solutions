#include <bits/stdc++.h>
#define MAXN 1005
//#define int long long
using namespace std;

#define pos first
#define vel second

int vet[100005];

int main(){
    int a, b;

    scanf("%d %d", &a, &b);
    a = a%b;
    vet[ a%b ] = 1;
    while( !vet[ (a + (a%b) )%b ] ){
        a = (a + (a%b))%b;
        vet[a] = 1;
    }

    if(vet[0]) printf("Yes\n");
    else printf("No\n");
}
