class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string number = "";
        while(x){
            number.push_back('0'+x%10);
            x /= 10;
        }
        
        string numberR = number;
        reverse(numberR.begin(), numberR.end());
        return number == numberR;
    }
};
