/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        
        queue< pair<Node*,int> > fila;
        fila.push( {root,0} );
        while( fila.size() ){
            Node* temp = fila.front().first;
            int level = fila.front().second;
            fila.pop();
            if(fila.size() and fila.front().second == level){
                temp->next = fila.front().first;
            }
            if(temp->left) fila.push( {temp->left, level+1} );
            if(temp->right) fila.push( {temp->right, level+1} );
        }
        return root;
    }
};
