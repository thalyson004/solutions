/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(vector<int> &nums, int left, int right){
        if(left>right){
            return nullptr;
        }else if(left==right){
            return new TreeNode(nums[left]);
        }else{
            int mid = (left+right)/2;
            return new TreeNode(nums[mid], dfs(nums, left, mid-1), dfs(nums, mid+1, right));
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};
