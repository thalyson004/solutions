
class Solution {
public:
    
    int getInt(int &id, string &s){
        int ans = 0;
        while(id<s.size() and isdigit(s[id])){
            ans = ans*10 + (s[id]-'0');
            id++;
        }
        
        return ans;
    }
    
    int calc(int &id, string &s){
        if(id==s.size()) return 0;
            
        int ans = 0;
        int sign = 1;
        
        while(id<s.size()){
            if(s[id]=='('){ ans += sign*calc(++id, s); sign=1;}
            else if(s[id]==')'){ id++; return ans;}
            else if(isdigit(s[id])){ ans += sign*getInt(id, s); sign=1;}
            else if(s[id]=='-'){id++;sign*=-1;}
            else id++;
        }
        
        return ans;
    }
    
    int calculate(string s) {
        int i = 0;
        return calc(i, s);    
    }
};
