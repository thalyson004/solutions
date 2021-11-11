class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        for(int i = 0; i < strs[0].size(); i++){
            char letter = strs[0][i];
            
            bool ok = true;
            for(int j = 0; ok and j < strs.size(); j++){
                ok = ok and strs[j][i]==letter;
            }
            
            if(!ok) break;
            ans.push_back(letter);
        }
        
        return ans;
    }
};
