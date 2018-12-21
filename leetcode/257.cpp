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
    vector<string> path, ans;
    
    string toString(int x){
        int ne = 0;
        if(x<0){
            ne = 1;
            x = -x;
        }
        string s;
        do{
            s.push_back( '0'+x%10 );
            x/=10;
        }while(x);
        reverse( s.begin(), s.end() );
        if(ne) s = "-"+s;
        return s;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root){
            path.push_back( toString(root->val) );
            if(root->right!=root->left){
                if(root->left) dfs(root-> left );
                if(root->right) dfs( root->right );
            }else{
                ans.push_back( toString(root->val) );
            }
        }
        return ans;
    }
    
    string CreatePath(){
        string s = path[0], seta = "->";
        for(int i = 1; i < path.size(); i++){
            s = s+seta+path[i] ;
        }
        return s;
    }
    
    void dfs(TreeNode *node){
        path.push_back( toString(node->val) );    
        int ok = 0;
        if( node->left == node-> right ){
            ok = 1;
        }else{
            if(node->left) dfs(node-> left );
            if(node->right) dfs( node->right );
        }
        if(ok){ ans.push_back( CreatePath( ) );}
        path.pop_back();
    }
    ~Solution(){
        ans.clear();
    }
};

