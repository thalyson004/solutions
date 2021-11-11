class Solution {
    bool is_number(char c){
        return c<='9' and c>='0';
    }    
    bool is_signal(char c){
        return c=='+' or c=='-';
    }
    
public:
    int myAtoi(string s) {
        int id = 0;
        
        while(id<s.size() and s[id]==' ') id++;
        if(id==s.size()) return 0;
        
        int signal = 1;
        if(is_signal(s[id])){
            if(s[id]=='-') signal = -1;
            id++;
        }
        
        int ans = 0;
        while(id<s.size()){
            if(is_number(s[id])==false) break;
            
            if(ans>INT_MAX/10 or ans==INT_MAX/10 and (s[id]-'0')>INT_MAX%10){
                return INT_MAX;
            }
            
            if(ans<INT_MIN/10 or ans==INT_MIN/10 and (s[id]-'0')>8){
                return INT_MIN;
            }
            
            ans = ans*10 + signal*(s[id]-'0');
            
            id++;
        }
        return ans;
    }
};
