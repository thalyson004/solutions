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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        function<int(TreeNode*)> getDeep = [&getDeep](TreeNode* root) -> int{
            if(root == nullptr) return 0;

            return max(getDeep(root->left), getDeep(root->right)) + 1;
        };

        int deep = getDeep(root);
        vector<vector<TreeNode*>> nodeByDeep(deep);

        function<bool(TreeNode*, int)> selectNode = [&deep, &nodeByDeep, &selectNode](TreeNode *node, int level) -> bool{
            if(node == nullptr) return deep == level;


            bool left = selectNode(node->left, level+1);
            bool right = selectNode(node->right, level+1);

            if(left or right){
                nodeByDeep[level].push_back(node);
                return true;
            }else{
                return false;
            }
        };

        selectNode(root, 0);

        for(int i = deep-1; i >= 0; i--){
            if(nodeByDeep[i].size() == 1)
                return nodeByDeep[i].back();
        }

        return root;
    }
};
