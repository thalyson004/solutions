class Solution {
public:
    
    static string toString(int a){
        string ans;
        
        do{
            ans.push_back('0'+(a%10));
            a/=10;
        }while(a);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    static bool comp(int  &a, int &b){
        string A = toString(a), B= toString(b);
        return A+B > B+A;
        
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp );
        
        string ans;
        for(int x:nums){
            string s = toString(x);
            for(char c: s){
                if(c=='0' and ans.size()==1 and ans[0]=='0' )
                    continue;
                ans.push_back( c );
            }
        }
        return ans;
    }
};
