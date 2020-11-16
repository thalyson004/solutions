class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0;
        
        int lastDec = 0;
        int lastInc = 0;
        int lastHeight=-1;
        
        for(int height:A){
            if(height > lastHeight){
                if(lastDec){
                    lastInc=1;
                    lastDec=0;
                }
                lastInc++;
            }else if(height < lastHeight){
                lastDec++;
            }else{
                lastInc=1;
                lastDec=0;
            }
            lastHeight = height;

            
            if(lastInc>1 and lastDec) ans = max(ans, lastInc+lastDec);
        }
        return ans;
    }
};
