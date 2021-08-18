class Solution {
public:
    int solve(string &s, int i, vector<int> &memo){
        //base
        if(i==s.size()) return 1;
        //Já calculado?
        if(memo[i]!=-1) return memo[i];
        
        int ans = 0;
        
        if(s[i]!='0'){
            ans += solve(s, i+1, memo);
            if(i+1<s.size()){
                int number = (s[i]-'0')*10 + (s[i+1]-'0');     
                if(number<=26) ans += solve(s, i+2, memo);
            }
        }
        
        return memo[i]=ans;
    }
    
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return solve(s, 0, memo);
    }
};
