class Solution {
public:
    bool isPalindrome(string s) {
        string a="",b="";
        
        for(char c: s)
            if(isalnum(c))
                a.push_back( tolower(c) );
        
        b = a;
        reverse(b.begin(), b.end());
        return a==b;
    }
};
