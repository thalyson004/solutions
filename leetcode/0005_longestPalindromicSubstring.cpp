class Solution {
public:
    
    int palOdd(string s, int j){
        int ans = 0;
        while( j-ans>=0 and j+ans<s.size() and s[j-ans]==s[j+ans] ) ans++;
        return ans-1;
    }
    int palEven(string s, int j){
        int ans = 0;
        while( j-ans-1>=0 and j+ans<s.size() and s[j-ans-1]==s[j+ans] ) ans++;
        return ans-1;
    }
    
    string longestPalindrome(string s) {
        string ans = "";
        
        for(int i = 0; i < s.size(); i++){
            int j = palOdd(s, i);
            int len = j*2+1;
            if( len > ans.size() ){
                ans  = s.substr(i-j, len);
            }
            if(i and s[i]==s[i-1]){
                j = palEven(s, i);
                len = 2*j+2;
                if( len > ans.size() ){
                    ans  = s.substr(i-j-1, len);
                }
            }
        }
        return ans;
    }
};
