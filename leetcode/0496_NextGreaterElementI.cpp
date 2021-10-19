class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> next_greater;
        stack<int> in_order;
        
        for(int i=nums2.size()-1; i >= 0; i--){
            while(in_order.size() and in_order.top()<nums2[i]) 
                in_order.pop();
            
            next_greater[nums2[i]] = in_order.size()?in_order.top():-1;
            in_order.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int value : nums1) 
            ans.push_back(next_greater[value]);
        
        return ans;
    }
};
