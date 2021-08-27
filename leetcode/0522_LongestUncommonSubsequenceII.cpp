class Solution {
public:
    
    bool isSub(string a, string b){
        int i = 0;
        
        for(char letter:b){
            if(i<a.size() and a[i]==letter)
                i++;
        }
        return i==a.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int ans = 0;
        
        for(int index=0; index<strs.size(); index++){
            string str = strs[index];
            int len = str.size();
            
            bool ok = true;
            for(int i = 0; ok and i < strs.size(); i++){
                if(i==index)continue;
                if( isSub(str, strs[i]) ) ok = false;
            }
            
            if(ok) ans = max(ans, int(str.size()));
        }
        
        return ans==0?-1:ans;
    }
};
