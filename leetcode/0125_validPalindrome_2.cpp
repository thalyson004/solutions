class Solution {
public:
    bool isPalindrome(string s) {
        string removed = "";
        for(char letter: s){
            if( isalnum(letter) ){
                removed.push_back( tolower(letter) );
            }
        }
        string reversed = removed;
        reverse(reversed.begin(), reversed.end());
        
        return reversed == removed;
    }
};
