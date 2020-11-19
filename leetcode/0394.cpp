class Solution {
public:
    string decodeString(string &s) {
        string ans = "";
        stack<int> mul;
        int t = 0;
        
        for(char c:s){
            if( (c>='a' and c<='z') ) ans.push_back(c);
            else if(c>='0' and c<='9') t = t*10 + (c-'0');
            else if(c=='[') {
                mul.push(t); 
                ans.push_back(c);
                t = 0;
            }else {
                int rep = mul.top(); mul.pop();
                string cur = "";
                while(ans.back() != '['){
                    cur.push_back( ans.back() );
                    ans.pop_back();
                }
                ans.pop_back();
                reverse(cur.begin(), cur.end());
                for(int i = 0; i < rep; i++){
                    for(char c: cur)
                        ans.push_back(c);
                }
            }
            
        }
        
        return ans;
    }
};
