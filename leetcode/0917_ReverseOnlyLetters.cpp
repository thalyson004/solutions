class Solution {
public:
    bool isletter(char c){
        return c>='a' and c<='z' or c>='A' and c<='Z';
    }
    
    string reverseOnlyLetters(string s) {
        vector<char> letters;
        for(char letter: s) 
            if(isletter(letter))
                letters.push_back(letter);
        
        for(char &letter: s) 
            if(isletter(letter)){
                letter = letters.back();
                letters.pop_back();
            }
        
        return s;
    }
};
