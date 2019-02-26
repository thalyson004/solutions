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
    bool isCousins(TreeNode* root, int x, int y) {
        if(dep(root, x)==dep(root, y) and !father(root,x,y)){
            return true;
        }else{
            return false;
        }
    }
    int dep(TreeNode* root, int x){
        if( root == NULL ) return -10000000;
        if( root->val == x ) return 0;
        return max( dep(root->right, x), dep(root->left, x)) +1;
    }
    bool father(TreeNode* root, int x, int y){
        if(root==NULL) return false;
        if( root->left!=NULL and root->right!=NULL and min(x,y)==min(root->left->val,root->right->val) and max(x,y)==max(root->left->val,root->right->val) ){
            return true;
        } 
        return father(root->left,x,y) or father(root->right,x,y);
    }
};
