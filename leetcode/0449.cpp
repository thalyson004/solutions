/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string numberToString(int val){
        if(val==0) return "0";
        string ans ="";
        while(val){
            ans.push_back( '0' + val%10 );
            val /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    // Encodes a tree to a single string.
    void serialize(TreeNode* root, string &ans) {
        if(root==NULL) return;
        
        ans.push_back('(');
        serialize(root->left, ans);
        
        string val = numberToString(root->val);
        for(char c:val) ans.push_back(c);
        
        serialize(root->right, ans);
        ans.push_back(')');
    }
    
    string serialize(TreeNode* root) {
        string ans = "";
        serialize(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data, int &id){
        TreeNode *root = new TreeNode(0);
        
        if(data[id]=='('){
            id++;
            root->left = deserialize(data, id);    
        }
        
        while(data[id]>='0' and data[id]<='9'){
            root->val *= 10;
            root->val += (data[id]-'0');
            id++;
        }
        
        if(data[id]=='('){
            id++;
            root->right = deserialize(data, id);    
        }
        
        id++;
        return root;
        
    }
    
    TreeNode* deserialize(string data) {
        int id = 1;
        if(data.size()) return deserialize(data, id);
        else return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
