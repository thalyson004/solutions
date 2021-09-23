class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.size();
        if(N<=1) return "";
        
        for(int i = 0; i < N/2; i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome.back()='b';
        return palindrome;
    }
};
