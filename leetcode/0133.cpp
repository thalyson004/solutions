/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void ajust(int v, vector<Node*> &G){
        while(G.size() < v){
            G.push_back( new Node() );
        }
    }
    void dfs(Node* node, vector<Node*> &G){
        int v = node->val;
        ajust(v, G);
        G[v-1]->val = v;
        
        for(Node* it: node->neighbors){
            int u = it->val;
            ajust(u, G);
            G[v-1]->neighbors.push_back( G[u-1] );
            if(G[u-1]->val == 0){
                dfs(it, G);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        vector<Node*> G;
        dfs(node, G);
        return G[0];
    }
};
