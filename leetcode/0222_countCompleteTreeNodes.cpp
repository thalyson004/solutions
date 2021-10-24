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
    bool check(TreeNode* root, int target){
        int level = 0;
        {
            int cur = target;
            while(cur){
                level++;
                cur = cur >> 1;
            }
        }
        
        for(int i = level-2; i >= 0; --i){
            if(root == nullptr) return false;
            if(target&(1<<i)){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        
        return root != nullptr;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int left = 1;
        int right = 5*1e4 + 5;
        
        while(left < right){
            int mid = (left+right+1)/2;
            
            if(check(root, mid)){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        
        return left;
    }
};
