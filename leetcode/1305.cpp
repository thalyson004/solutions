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
    
    void inorder(TreeNode* root, vector<int> &order){
        if(root==NULL) return;
        
        inorder(root->left, order );
        order.push_back( root->val );
        inorder(root->right, order );
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> left;
        vector<int> right;
        
        inorder(root1, left);
        inorder(root2, right);
        
        vector<int> ans;
        int l=0, r=0;
        
        while(l< left.size() and r < right.size()){
            if( left[l] < right[r] ) ans.push_back( left[l++] );
            else ans.push_back( right[r++] );
        }
        while(l< left.size()){
            ans.push_back( left[l++] );
        }
        while(r < right.size()){
            ans.push_back( right[r++] );
        }
        return ans;
    }
};
