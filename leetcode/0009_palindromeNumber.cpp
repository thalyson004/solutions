class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else{
            long long ans=0,y=x;
            while(y){
                ans = ans*10 + y%10;
                y/=10;
            }
            return ans==x;
        }   
    }
};
