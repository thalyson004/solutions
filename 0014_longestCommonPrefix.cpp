class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        
        int ans = 0, ok = 1;
        for(int i = 0; ok and i < strs[0].size(); i++){
            for(int j = 1; ok and j < strs.size(); j++){
                if( strs[j].size() < i+1 or strs[j][i] != strs[0][i]){
                    ok = 0;
                }
            }
            if(ok) ans++;
        }
        
        return strs[0].substr(0, ans);
    }
};
