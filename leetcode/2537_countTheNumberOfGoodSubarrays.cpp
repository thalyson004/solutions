class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        auto count = [&k](long long number){
            number--;
            return  min( (long long) k, ((number+1)*(number))/2);
        };

        unordered_map<int,int> counter;
        int have = 0;
        int left = -1;
        int right = 0;
        long long ans = 0;


        while(++left < nums.size()){
            while(have<k and right<nums.size()){
                
                have -= count(counter[ nums[right] ]);
                counter[ nums[right] ]++;
                have += count(counter[ nums[right] ]);
                right++;
            }
            if(have>=k) ans += 1+nums.size() - right;

            have -= count(counter[ nums[left] ]);
            counter[ nums[left] ]--;
            have += count(counter[ nums[left] ]);
        }
        return ans;
    }
};
