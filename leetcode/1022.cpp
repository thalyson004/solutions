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
    int sum(TreeNode* root, int &num){
        if(root==NULL) return 0;
        
        num = (num<<1) + root->val;
        int cur = 0;
        
        if( root->left or root->right ){
            cur = sum(root->left,num) + sum(root->right,num); 
        }else{
            cur = num;
        }
        
        num = (num>>1);
        return cur;
    }
    int sumRootToLeaf(TreeNode* root) {
        int temp=0;
        if(root) return sum(root, temp);
        else return 0;
    }
};
