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
  int sumTree(TreeNode *root, int &tilt){
    if(root==NULL) return 0;
    
    int leftSum= sumTree(root->left, tilt);
    int rightSum= sumTree(root->right, tilt);
    tilt += abs(leftSum-rightSum);
    
    return leftSum+root->val+rightSum;
  }
  int findTilt(TreeNode* root) {
    if(root==NULL) return 0;

    int tilt=0;
    sumTree(root, tilt);
    return tilt;
  }
};

