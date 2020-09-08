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
    void dfs(TreeNode *root, vector<int> &ans, int deep=0){
        if(!root) return;
        
        if(ans.size()==deep) ans.push_back( root->val );
        else ans[ deep ] = max(ans[deep], root->val);
        
        dfs(root->left, ans, deep+1);
        dfs(root->right, ans, deep+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
