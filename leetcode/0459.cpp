class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i = 1; i*i <= len ; i++){
            if( len%i==0 ){
                if( igual(s, i) ){
                    return true;
                }
                if(i*i!=len and igual(s, len/i)){
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool igual(string &s, int r){
        if(r==s.size()) return false;
        
        for(int i = 0; i < r; i++){
            for(int j = 1; i + r*j < s.size(); j++){
                if( s[i + j*r]!=s[i] ) return false; 
            }
        }
        return true;
    }
};
