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
    
    bool dfs(TreeNode *root, int k, unordered_set<int> &sums){
        if(root == nullptr) return false;
        if(sums.count(k-root->val)) return true;
        sums.insert(root->val);
        return dfs(root->left, k, sums) or dfs(root->right, k, sums);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> sums;
        return dfs(root, k, sums);
    }
};
