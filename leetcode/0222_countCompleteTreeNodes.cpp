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
        target--;
        
        int level = 0;
        {
            int cur = target;
            while(cur >= (1<<level)){
                cur -= (1<<level);
                level++;
            }
        }
        
        int remain = target-( (1<<(level)) - 1);
        
        for(int i = level-1; i >= 0; i--){
            if(root == nullptr) return false;
            if(remain&(1<<i)){
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
