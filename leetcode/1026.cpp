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
    int maxAncestorDiff(TreeNode* root, int mn = INT_MAX, int mx = INT_MIN ) {
        if(root==NULL)return 0;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        
        int dif = mx-mn;
        dif = max(dif, maxAncestorDiff(root->left, mn, mx));
        dif = max(dif, maxAncestorDiff(root->right, mn, mx));
        return dif;   
    }
};
