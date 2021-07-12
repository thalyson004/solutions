class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char, char> match;
        set<char> used;
        
        for(int i = 0; i < s.size(); i++){
            if( match.count(s[i]) ){
                if( match[ s[i] ] != t[i] ) return false;
            }else{
                if( used.count( t[i] ) ) return false;
                used.insert( t[i] );
                match[ s[i] ] = t[i];
            }
        }
        return true;
    }
};
