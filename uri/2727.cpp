#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;

    while(cin >> n){
        getchar();
        while(n--){
            getline(cin, s);
            int ponto=0, espaco=0;
            for(int i =0; i < s.size(); i++){
                char c =s[i];
                if(c==' ') espaco++;
                else ponto ++;
            }
            cout << (char)('a'+(espaco*3)+(ponto/(espaco+1)-1)) << endl;
        }
    }
}
