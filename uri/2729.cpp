#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;

    cin >> n;
    getchar();

    while(n--){
        char c;
        s ="";
        int f = 0;
        map<string, int > mapa;
        vector<string> ans;

        while(scanf("%c", &c) and c!='\n'){

            if(c == ' '){
                if(!mapa[s]){
                    f = 1;
                    mapa[s]=1;
                    ans.push_back(s);
                }
                s ="";
            } else{
                s=s+c;
            }
        }
        if(!mapa[s]){
            f = 1;
            mapa[s]=1;
            ans.push_back(s);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size();i++){
            printf("%s%c",ans[i].c_str(), " \n"[i+1==ans.size()]);
        }
    }
}
