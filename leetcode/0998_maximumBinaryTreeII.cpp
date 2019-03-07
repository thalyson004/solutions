/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if( root==NULL ){
            TreeNode *cur = new TreeNode(val);     
            return cur;
        }
        
        if( root-> val < val  ){
            TreeNode *cur = new TreeNode(val);
            cur->left = root;
            root = cur;
        }else{
            root->right = insertIntoMaxTree(root->right, val);
        }
        
        return root;
    }
};
