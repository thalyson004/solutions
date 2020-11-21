class Solution {
public:
    int solve(int i, string &number, string &digits, int p){
        if(i==number.size())return 1;
        
        int ans = 0;
        for(char d: digits){
            if(d<number[i]){
                ans += p;
            }else if(d==number[i]){
                ans += solve(i+1, number, digits, p/digits.size());
            }
        }
        return ans;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int ans = 0;
        
        string number = to_string(n);
        
        string digit = "";
        for(string d:digits) digit = digit + d;
        
        //less digits
        int p = 1;
        for(int i = 1; i < number.size();i++){
            p*=digits.size();
            ans += p;
        }
        
        //plus equal number of digits
        return ans+solve(0, number, digit, p);
    }
};
