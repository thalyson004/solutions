struct node{
    int level;
    int finish;
    vector<node*> children;
    
    node(){
        level = 0;
        finish = 0;
        children = vector<node*>(26, NULL);
    }
};

void add(string s, node &root){
    node *cur = &root;
    
    for(char c:s){   
        c -= 'a';
        if( cur->children[c]==NULL ){
            cur->children[c] = new node();
            cur->children[c]->level = cur->level+1;
        }
        cur = cur->children[c];
    }
    cur->finish++;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        node root = node();
        for(string s:wordDict){
            add(s, root);
        }
        
        vector<bool> ans = vector<bool>(s.size()+1);
        ans[0] = 1;
        
        for(int i = 0; i < s.size(); i++){
            if(ans[i]==false)continue;
            node *cur = &root;
            
            for(int j = 0; j+i<s.size(); j++){
                char c = s[i+j];
                c -= 'a';
                if( cur->children[c]==NULL ){
                    break;
                }else{
                    cur = cur->children[c];
                    if(cur->finish){
                        ans[i+j+1] = true;
                    }
                }
            }
        }
        
        return ans[s.size()];
    }
};
