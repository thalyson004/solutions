class Solution {
public:
    int countUp(int value){
        int ans = 0;
        while(value){
            ans += value&1;
            value/=2;
        }
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        int N = arr.size();
        vector<int> masks;
        
        for(string s: arr){
            int mask = 0;
            for(char c: s){
                if(mask&(1<<(c-'a'))){
                    mask = 0;
                    break;
                } 
                else mask |= (1<<(c-'a'));
            }
            masks.push_back(mask);
        }
        
        int ans = 0;
        
        for(int subset = 0; subset < (1<<N); subset++){
            
            int cur = 0;
            for(int i = 0; i < N; i++){
                if( (subset&(1<<i)) and !(cur&masks[i]) ){
                    cur |= masks[i];
                }
            }
            
            if( countUp(cur)>ans ){
                ans = countUp(cur);
            }
        }
        
        return ans;
    }
};
