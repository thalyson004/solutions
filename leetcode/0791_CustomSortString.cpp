class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> count(26);
        for(char c:str) count[c-'a']++;
        string ans = "";
        
        for(char c:order){
            for(int j = 0; j < count[c-'a']; j++)
                ans.push_back(c);
            count[c-'a']=0;
        }
        
        for(char c:str){
            if(count[c-'a'])
                ans.push_back(c);
        }
        
        return ans;
    }
};
