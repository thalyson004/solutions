class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> corpus;
        
        string cur="";
        for(char c:str){
            if(c==' '){
                corpus.push_back(cur);
                cur.clear();
            }else{
                cur.push_back(c);
            }
        }
        corpus.push_back(cur);
        cur.clear();
        map<string, int> mapa;
        bool ok = pattern.size() == corpus.size();
        vector<int> last(26, -1);
        for(int i = 0; ok and i < pattern.size(); i++){
            char c = pattern[i];
            
            if( last[c-'a'] != -1 ){
                ok = (corpus[i]==corpus[ last[c-'a'] ]);
            }else{
                if( mapa[ corpus[i] ] ) ok = false;
                else mapa[corpus[i]] =1 ;
            }
            
            last[c-'a'] = i;
        }
        return ok;
    }
};
