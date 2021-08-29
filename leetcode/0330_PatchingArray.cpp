class Solution {
public:
    int minPatches(vector<int>& nums, long long n) {
        int ans = 0;
        long long lagest = 0;
        int index = 0;
        
        while(lagest < n){
            if(index < nums.size() and lagest+1>=nums[index]){
                lagest = lagest+=nums[index++];
            }else{
                ans++;
                lagest = lagest*2 + 1;
            }
        }
        
        return ans;   
    }
};
