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
    
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        
        int left = dfs(root->left);
        if(left==0 and root->left!=nullptr ) root->left = nullptr;
        
        int right = dfs(root->right);
        if(right==0 and root->right!=nullptr ) root->right = nullptr;

        return root->val + left + right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode *start = new TreeNode(1, root, nullptr);
        dfs(start);
        return start->left;
    }
};
