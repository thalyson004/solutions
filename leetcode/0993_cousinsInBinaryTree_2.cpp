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
    
    pair<int,int> depth(TreeNode* root, int target, int d=1, int parent=-1){
        if(root==nullptr) return {0,0};
        if(root->val==target) return {d, parent};
        return max(depth(root->left, target, d+1, root->val),
                   depth(root->right, target, d+1, root->val));
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> ansx = depth(root, x);
        pair<int,int> ansy = depth(root, y);
        
        return ansx.first==ansy.first and ansx.second!=ansy.second;
    }
};
