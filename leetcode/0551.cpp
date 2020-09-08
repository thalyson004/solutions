class Solution {
public:
    bool checkRecord(string s) {
        int A=0;
        int L=0;
        for(char c:s){
            if(c=='A')A++;
            
            if(c=='L')L++;
            else L=0;
            
            if(L>2 or A>1) return false;
        }
        
        return true;
    }
};
