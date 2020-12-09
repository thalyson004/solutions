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
class BSTIterator {
public:
    vector<TreeNode*> path;

    BSTIterator(TreeNode* root) {
        path.push_back(root);
        while(root and root->left){
            root = root->left;
            path.push_back(root);
        }
    }

    int next() {
        int value = path.back()->val;

        if(path.back()->right!=nullptr){
            TreeNode* root = path.back()->right;
            path.pop_back();
            path.push_back(root);
            while(root and root->left){
                root = root->left;
                path.push_back(root);
            }
        }else{
            path.pop_back();
        }

        return value;
    }

    bool hasNext() {
        return !path.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
