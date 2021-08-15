class Solution {
public:
    
    bool ok(vector<int> &constructed){
        for(int i = 0; i < 52;i ++){
            if(constructed[i]>0)
                return false;
        }
        return true;
    }
    int value(char letter){
        if(letter<='Z') return letter-'A';
        else return letter-'a'+26;
    }
    string minWindow(string s, string t) {
        vector<int> constructed(52);
        for(char letter:t) constructed[value(letter)]++;
        
        int ansStart = 0;
        int ansLen = 0;
        
        int right = 0;
        for(int left = 0; left + t.size() <= s.size(); left++){
            if(left>right){
                constructed[ value(s[right]) ]++;
                right++;
            }
            
            while(right<s.size() and !ok(constructed)){
                constructed[ value(s[right]) ]--;
                right++;
            }
            
            if(ok(constructed) and (!ansLen or ansLen > right-left)) {
                ansLen = right-left;
                ansStart = left;
            }
            
            constructed[ value(s[left]) ]++;
            
        }
        
        return s.substr(ansStart, ansLen);
    }
};
