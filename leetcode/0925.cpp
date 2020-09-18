class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<bool> mark(name.size());
        
        int j = 0;
        char last='$';
        for(int i = 0; i < name.size(); i++){
            while(j < typed.size() and typed[j]!=name[i]){
                if(typed[j]!=last)return false;
                j++;
            }
            
            if(j==typed.size()) return false;
            last = name[i];
            j++;
        }
        while(j < typed.size() and typed[j]==last){
            j++;
        }
        
        return j==typed.size();
    }
};
