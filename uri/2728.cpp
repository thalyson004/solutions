#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first

int main(){
    int n;
    string s;
    string busca = "cobol";

    while(getline(cin, s)){
        vector< pair<char,char> > L;
        char u=s[0],d;

        for(int i =0; i < s.size(); i++){
            if(s[i]=='-'){
                d = s[i-1];
                u = tolower(u);
                d = tolower(d);
                L.push_back( {u, d} );
                u = s[i+1];
            }
        }
        d = s[ s.size()-1 ];
        u = tolower(u);
        d = tolower(d);
        L.push_back( {u, d} );
        int flag = 0;
        for(int i = 0; i < L.size(); i++){
            int ok = 0;
            for(int j = 0; j < busca.size(); j++){
                if(busca[j] == L[i+j].ff ||
                   busca[j] == L[i+j].ss) ok++;
            }
            if(ok == busca.size()){
                flag = 1;
                break;
            }
        }
        printf("%s\n", flag?"GRACE HOPPER":"BUG");
    }
}
