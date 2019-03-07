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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if(nums.empty())return NULL;
		
		vector<int> l, r;
		
		int id = 0;
		for(int i = 0; i < nums.size(); i++)
			if( nums[i] > nums[id] )
				id = i;
			
		for(int i = 0; i < id; i++) l.push_back(nums[i]);
		for(int i = id+1; i < nums.size(); i++) r.push_back(nums[i]);
		
		TreeNode *root = new TreeNode(nums[id]);
		root->left = constructMaximumBinaryTree(l);
		root->right = constructMaximumBinaryTree(r);
		return root;
	}
};
