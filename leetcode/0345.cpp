class Solution {
public:
    bool vowel(char c){
        c = tolower(c);
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    string reverseVowels(string s) {
        string v;
        
        for(char &c:s){
            if( vowel(c) ){
                v.push_back(c);
            }
        }
        for(char &c:s){
            if( vowel(c) ){
                c = v.back();
                v.pop_back();
            }
        }
        return s;
    }
    
};
