class Solution {
public:
    short romanValue(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
    }
    
    int romanToInt(string s) {
        short ans = 0, value=1000, q = 0;
        
        for(char c: s){
            if( romanValue(c) == value ){
                q++;
            }else{
                if( romanValue(c) > value ){
                    ans -= q*value;
                }else{
                    ans += q*value;
                }
                q = 1;
                value = romanValue(c);
            }
        }
        ans += q*value;
        return ans;
    }
};
